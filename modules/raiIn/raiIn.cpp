#include "raiIn.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : publication_matched(0) {
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

RaiIn::RaiIn() : participant(nullptr),
                 publisher(nullptr),
                 topicRaiIn(nullptr),
                 writerRaiIn(nullptr),
                 typeRaiIn(new DataRaiInPubSubType()) {
}

RaiIn::~RaiIn() {

	if (writerRaiIn != nullptr) {
		publisher->delete_datawriter(writerRaiIn);
	}

	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool RaiIn::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	DomainParticipantQos participantQos;
	participantQos.name("RaiInParticipant");
	participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiIn.register_type(participant);

	// Create the publications Topic
	topicRaiIn = participant->create_topic("DataRaiIn", "DataRaiIn", TOPIC_QOS_DEFAULT);
	if (topicRaiIn == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerRaiIn = publisher->create_datawriter(topicRaiIn, DATAWRITER_QOS_DEFAULT, &listener);
	if (writerRaiIn == nullptr) {
		return false;
	}

	if (raiCom.init() == false) {
		return false;
	}

	return true;
}


void RaiIn::publish() {

	while (1) {

		std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
		dataRaiIn.time(timer.getSysTime());
		dataRaiIn.alive(true);

		writerRaiIn->write(&dataRaiIn);
		dataRaiInLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
	}

}


void RaiIn::run() {

	// std::cout << this->name << " run" << std::endl;

	while (1) {

		if (raiCom.receive()) {

			std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};

			dataRaiIn.senseTime(raiCom.time);
			dataRaiIn.chnl(raiCom.channel);
			dataRaiIn.roll(mixer.pwm2rad(Mixer::AILR, raiCom.channel[1])); // we are assuming ail is symmetrical
			dataRaiIn.pitch(mixer.pwm2rad(Mixer::ELE, raiCom.channel[2]));
			dataRaiIn.yaw(mixer.pwm2rad(Mixer::RUD, raiCom.channel[3]));
			dataRaiIn.thr(mixer.pwm2rad(Mixer::THR, raiCom.channel[0]));
			dataRaiIn.fltMode(mixer.pwm2mode(raiCom.channel[6]));

			dataRaiInLock.unlock();

			// raiCom.print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(2);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(2);

	}

}

bool RaiIn::print() {

	std::cout << "--- " << this->name << " " << dataRaiIn.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataRaiIn.senseTime() << std::endl;
	for (int i=0; i<CAN_META_RAI_CHNL_NUM; i++) {
		std::cout << "chnl[" << i << "]" << "   " << dataRaiIn.chnl().at(i) << std::endl;
	}
	std::cout << "roll      " << dataRaiIn.roll() << std::endl;
	std::cout << "pitch     " << dataRaiIn.pitch() << std::endl;
	std::cout << "yaw       " << dataRaiIn.yaw() << std::endl;
	std::cout << "thr       " << dataRaiIn.thr() << std::endl;
	std::cout << "fltMode   " << dataRaiIn.fltMode() << std::endl;
	std::cout << "alive     " << dataRaiIn.alive() << std::endl;

	return true;
}
