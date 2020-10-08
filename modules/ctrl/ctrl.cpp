#include "ctrl.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cmath>

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
			if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {
				std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
				reader->take_next_sample(&dataRaiIn, &info);
				dataRaiInLock.unlock();
				newDataRaiIn = true;

			} else if (reader->get_topicdescription()->get_name().compare("DataSFusion") == 0) {
				std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
				reader->take_next_sample(&dataSFusion, &info);
				dataSFusionLock.unlock();
				newDataSFusion = true;

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

Ctrl::Ctrl() : participant(nullptr),
               publisher(nullptr),
               subscriber(nullptr),
               topicCtrl(nullptr),
               writerCtrl(nullptr),
               typeCtrl(new DataCtrlPubSubType()),
               topicRaiIn(nullptr),
               readerRaiIn(nullptr),
               typeRaiIn(new DataRaiInPubSubType()),
               topicSFusion(nullptr),
               readerSFusion(nullptr),
               typeSFusion(new DataSFusionPubSubType()) {

}

Ctrl::~Ctrl() {

	if (writerCtrl != nullptr) {
		publisher->delete_datawriter(writerCtrl);
	}

	if (topicCtrl != nullptr) {
		participant->delete_topic(topicCtrl);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	if (readerRaiIn != nullptr) {
		subscriber->delete_datareader(readerRaiIn);
	}

	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
	}

	if (readerSFusion != nullptr) {
		subscriber->delete_datareader(readerSFusion);
	}

	if (topicSFusion != nullptr) {
		participant->delete_topic(topicSFusion);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Ctrl::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	DomainParticipantQos participantQos;
	participantQos.name("CtrlParticipant");
	participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeCtrl.register_type(participant);

	// Create the publications Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerCtrl = publisher->create_datawriter(topicCtrl, DATAWRITER_QOS_DEFAULT, &listener);
	if (writerCtrl == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiIn.register_type(participant);

	// Create the subscriptions Topic
	topicRaiIn = participant->create_topic("DataRaiIn", "DataRaiIn", TOPIC_QOS_DEFAULT);
	if (topicRaiIn == nullptr) {
		return false;
	}

	// Register the Type
	typeSFusion.register_type(participant);

	// Create the subscriptions Topic
	topicSFusion = participant->create_topic("DataSFusion", "DataSFusion", TOPIC_QOS_DEFAULT);
	if (topicSFusion == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	readerRaiIn = subscriber->create_datareader(topicRaiIn, DATAREADER_QOS_DEFAULT, &listener);
	if (readerRaiIn == nullptr) {
		return false;
	}

	// Create the DataReader
	readerSFusion = subscriber->create_datareader(topicSFusion, DATAREADER_QOS_DEFAULT, &listener);
	if (readerSFusion == nullptr) {
		return false;
	}

	if (pidRoll.set(0.5, 0.0/*0.5*/, 0.0, Mixer::AIL_MAX, -Mixer::AIL_MAX, false) != true) {
		return false;
	}

	if (pidPitch.set(0.5, 0.0/*0.5*/, 0.0, Mixer::ELE_MAX, -Mixer::ELE_MAX, false) != true) {
		return false;
	}

	if (pidYaw.set(0.0, 0.0/*0.5*/, 1.0, Mixer::RUD_MAX, -Mixer::RUD_MAX, false) != true) {
		return false;
	}

	return true;
}


void Ctrl::publish() {

	while (1) {

		std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
		dataCtrl.time(timer.getSysTime());
		dataCtrl.alive(true);

		writerCtrl->write(&dataCtrl);
		dataCtrlLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Ctrl::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataRaiIn /*|| listener.newDataSFusion*/) { // Chris will dass wir nur auf raiIn triggern

			std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};

			static float lastTime = timer.getSysTimeS();
			float deltaTime = timer.getSysTimeS()-lastTime;

			float outRoll = 0.0;
			pidRoll.run(deltaTime, 2.0*listener.dataRaiIn.roll(), -listener.dataSFusion.phi(), &outRoll);

			float outPitch = 0.0;
			pidPitch.run(deltaTime, 2.0*listener.dataRaiIn.pitch(), -listener.dataSFusion.the(), &outPitch);

			// float outYaw = 0.0;
			// pidYaw.run(deltaTime, listener.dataRaiIn.yaw(), -listener.dataSFusion.psi(), &outYaw);

			lastTime = timer.getSysTimeS();

			// std::cout << "soll:      " << listener.dataRaiIn.yaw() << std::endl
			//           << "ist:       " << listener.dataSFusion.psi() << std::endl
			//           << "stell:     " << outYaw << std::endl
			//           << "deltaTime: " << deltaTime << std::endl;

			if (listener.dataRaiIn.fltMode() == Mixer::MAN) {
				dataCtrl.xi(listener.dataRaiIn.roll());
				dataCtrl.eta(listener.dataRaiIn.pitch());
				dataCtrl.zeta(listener.dataRaiIn.yaw());

				pidRoll.reset();
				pidPitch.reset();
				// pidYaw.reset();

			} else if (listener.dataRaiIn.fltMode() == Mixer::ATT) {
				dataCtrl.xi(outRoll);
				dataCtrl.eta(listener.dataRaiIn.pitch());
				dataCtrl.zeta(listener.dataRaiIn.yaw());

				pidPitch.reset();
				// pidYaw.reset();

			} else if (listener.dataRaiIn.fltMode() == Mixer::NAV) {
				dataCtrl.xi(outRoll);
				dataCtrl.eta(outPitch);
				dataCtrl.zeta(listener.dataRaiIn.yaw());

				// dataCtrl.zeta(outYaw);
			}

			dataCtrl.etaT(listener.dataRaiIn.thr());
			dataCtrl.etaF(69.0);
			dataCtrl.fltMode(listener.dataRaiIn.fltMode());

			dataSFusionLock.unlock();
			dataRaiInLock.unlock();
			dataCtrlLock.unlock();

			listener.newDataRaiIn = false;
			listener.newDataSFusion = false;
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

bool Ctrl::print() {

	std::cout << "--- " << this->name << " " << dataCtrl.time() << " ---" << std::endl;

	std::cout << "xi      " << dataCtrl.xi() << std::endl;
	std::cout << "eta     " << dataCtrl.eta() << std::endl;
	std::cout << "zeta    " << dataCtrl.zeta() << std::endl;
	std::cout << "etaT    " << dataCtrl.etaT() << std::endl;
	std::cout << "etaF    " << dataCtrl.etaF() << std::endl;
	std::cout << "fltMode " << dataCtrl.fltMode() << std::endl;
	std::cout << "alive   " << dataCtrl.alive() << std::endl;

	return true;
}
