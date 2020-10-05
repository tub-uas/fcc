#include "raiOut.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : publication_matched(0),
                       subscription_matched(0) {
}

Listener::~Listener() {
}

void Listener::on_publication_matched(DataWriter*,
                                      const PublicationMatchedStatus& info) {

	if (info.current_count_change == 1) {
		publication_matched = info.total_count;
		std::cout << "Publisher matched." << std::endl;
	} else if (info.current_count_change == -1) {
		publication_matched = info.total_count;
		std::cout << "Publisher unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
	}
}

void Listener::on_subscription_matched(DataReader*,
                                       const SubscriptionMatchedStatus& info) {

	if (info.current_count_change == 1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber matched." << std::endl;
	} else if (info.current_count_change == -1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
	}
}

void Listener::on_data_available(DataReader* reader) {

	SampleInfo info;
	void* data = reader->type().create_data();

	while (reader->read_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK) {
		if (info.instance_state == ALIVE && info.valid_data) {
			if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
				std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
				reader->take_next_sample(&dataCtrl, &info);
				dataCtrlLock.unlock();
				newDataCtrl = true;

			} else {
				reader->take_next_sample(&data, &info);
			}
		} else {
			reader->take_next_sample(&data, &info);
		}
	}

	// TODO why does this cause a segfault ?!?
	// reader->type().delete_data(data);
}

RaiOut::RaiOut() : participant(nullptr),
                   publisher(nullptr),
                   subscriber(nullptr),
                   topicRaiOut(nullptr),
                   writerRaiOut(nullptr),
                   typeRaiOut(new DataRaiOutPubSubType()),
                   topicCtrl(nullptr),
                   readerCtrl(nullptr),
                   typeCtrl(new DataCtrlPubSubType()) {

}

RaiOut::~RaiOut() {

	if (writerRaiOut != nullptr) {
		publisher->delete_datawriter(writerRaiOut);
	}

	if (topicRaiOut != nullptr) {
		participant->delete_topic(topicRaiOut);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	if (readerCtrl != nullptr) {
		subscriber->delete_datareader(readerCtrl);
	}

	if (topicCtrl != nullptr) {
		participant->delete_topic(topicCtrl);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool RaiOut::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	DomainParticipantQos participantQos;
	participantQos.name("RaiOutParticipant");
	participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiOut.register_type(participant);

	// Create the publications Topic
	topicRaiOut = participant->create_topic("DataRaiOut", "DataRaiOut", TOPIC_QOS_DEFAULT);
	if (topicRaiOut == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerRaiOut = publisher->create_datawriter(topicRaiOut, DATAWRITER_QOS_DEFAULT, &listener);
	if (writerRaiOut == nullptr) {
		return false;
	}

	// Register the Type
	typeCtrl.register_type(participant);

	// Create the subscriptions Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	readerCtrl = subscriber->create_datareader(topicCtrl, DATAREADER_QOS_DEFAULT, &listener);
	if (readerCtrl == nullptr) {
		return false;
	}

	if (raiCom.init() == false) {
		return false;
	}

	return true;
}


void RaiOut::publish() {

	while (1) {

		std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};
		dataRaiOut.time(timer.getSysTime());
		dataRaiOut.alive(true);

		writerRaiOut->write(&dataRaiOut);
		dataRaiOutLock.unlock();

		raiCom.send(); // Send the commands to RAI over CAN

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void RaiOut::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataCtrl) {

			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};

			// std::array<uint16_t, CAN_META_RAI_CHNL_NUM> fix =  {900, 1000, 1100, 1200, 1300, 1400,
			//                                                    1500, 1600, 1700, 1800, 1900, 2000};

			dataRaiOut.chnl(raiCom.channel);
			dataRaiOut.roll(listener.dataCtrl.xi());
			dataRaiOut.pitch(listener.dataCtrl.eta());
			dataRaiOut.yaw(listener.dataCtrl.zeta());
			dataRaiOut.thr(listener.dataCtrl.etaT());
			dataRaiOut.fltMode(listener.dataCtrl.fltMode());

			raiCom.time = timer.getSysTimeS();
			raiCom.channel[0] = mixer.rad2pwm(Mixer::THR, listener.dataCtrl.etaT());
			raiCom.channel[1] = mixer.rad2pwm(Mixer::AILR, listener.dataCtrl.xi());
			raiCom.channel[2] = mixer.rad2pwm(Mixer::ELE, listener.dataCtrl.eta());
			raiCom.channel[3] = mixer.rad2pwm(Mixer::RUD, listener.dataCtrl.zeta());
			raiCom.channel[4] = mixer.rad2pwm(Mixer::AILL, -listener.dataCtrl.xi());
			raiCom.channel[5] = 1500;
			raiCom.channel[6] = mixer.mode2pwm(Mixer::MAN);
			raiCom.channel[7] = 1500;
			raiCom.channel[8] = 1500;
			raiCom.channel[9] = 1500;
			raiCom.channel[10] = 1500;
			raiCom.channel[11] = 1500;

			dataCtrlLock.unlock();
			dataRaiOutLock.unlock();

			// raiCom.print();

			listener.newDataCtrl = false;
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

bool RaiOut::print() {

	std::cout << "--- " << this->name << " " << dataRaiOut.time() << " ---" << std::endl;

	for (int i=0; i<CAN_META_RAI_CHNL_NUM; i++) {
		std::cout << "chnl[" << i << "]" << " " << dataRaiOut.chnl().at(i) << std::endl;
	}

	std::cout << "roll      " << dataRaiOut.roll() << std::endl;
	std::cout << "pitch     " << dataRaiOut.pitch() << std::endl;
	std::cout << "yaw       " << dataRaiOut.yaw() << std::endl;
	std::cout << "thr       " << dataRaiOut.thr() << std::endl;
	std::cout << "fltMode   " << dataRaiOut.fltMode() << std::endl;
	std::cout << "alive     " << dataRaiOut.alive() << std::endl;

	return true;
}
