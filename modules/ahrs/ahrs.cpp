#include "ahrs.h"

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

Ahrs::Ahrs() : participant(nullptr),
               publisher(nullptr),
               topicAhrs(nullptr),
               writerAhrs(nullptr),
               typeAhrs(new DataAhrsPubSubType()) {
}

Ahrs::~Ahrs() {

	if (writerAhrs != nullptr) {
		publisher->delete_datawriter(writerAhrs);
	}

	if (topicAhrs != nullptr) {
		participant->delete_topic(topicAhrs);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Ahrs::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	DomainParticipantQos participantQos;
	participantQos.name("AhrsParticipant");
	participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeAhrs.register_type(participant);

	// Create the publications Topic
	topicAhrs = participant->create_topic("DataAhrs", "DataAhrs", TOPIC_QOS_DEFAULT);
	if (topicAhrs == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerAhrs = publisher->create_datawriter(topicAhrs, DATAWRITER_QOS_DEFAULT, &listener);
	if (writerAhrs == nullptr) {
		return false;
	}

	if (ahrsCom.init() == false) {
		return false;
	}

	return true;
}


void Ahrs::publish() {

	while (1) {

		std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
		dataAhrs.time(timer.getSysTime());
		dataAhrs.alive(true);

		writerAhrs->write(&dataAhrs);
		dataAhrsLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Ahrs::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (ahrsCom.receive()) {

			std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};

			dataAhrs.senseTime(ahrsCom.time);
			dataAhrs.gyrX(ahrsCom.gyr[0]);
			dataAhrs.gyrY(ahrsCom.gyr[1]);
			dataAhrs.gyrZ(ahrsCom.gyr[2]);
			dataAhrs.accX(ahrsCom.acc[0]);
			dataAhrs.accY(ahrsCom.acc[1]);
			dataAhrs.accZ(ahrsCom.acc[2]);
			dataAhrs.magX(ahrsCom.mag[0]);
			dataAhrs.magY(ahrsCom.mag[1]);
			dataAhrs.magZ(ahrsCom.mag[3]);
			dataAhrs.temp(ahrsCom.temp);
			dataAhrs.press(ahrsCom.press);
			dataAhrs.phi(ahrsCom.att[0]);
			dataAhrs.the(ahrsCom.att[1]);
			dataAhrs.psi(ahrsCom.att[2]);
			dataAhrs.q0(-1.0);
			dataAhrs.q1(-2.0);
			dataAhrs.q2(-3.0);
			dataAhrs.q3(-4.0);

			dataAhrsLock.unlock();

			// ahrsCom.print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

bool Ahrs::print() {

	std::cout << "--- " << this->name << " " << dataAhrs.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataAhrs.senseTime() << std::endl;
	std::cout << "gyrX      " << dataAhrs.gyrX() << std::endl;
	std::cout << "gyrY      " << dataAhrs.gyrY() << std::endl;
	std::cout << "gyrZ      " << dataAhrs.gyrZ() << std::endl;
	std::cout << "accX      " << dataAhrs.accX() << std::endl;
	std::cout << "accY      " << dataAhrs.accY() << std::endl;
	std::cout << "accZ      " << dataAhrs.accZ() << std::endl;
	std::cout << "magX      " << dataAhrs.magX() << std::endl;
	std::cout << "magY      " << dataAhrs.magY() << std::endl;
	std::cout << "magZ      " << dataAhrs.magZ() << std::endl;
	std::cout << "temp      " << dataAhrs.temp() << std::endl;
	std::cout << "press     " << dataAhrs.press() << std::endl;
	std::cout << "phi       " << dataAhrs.phi() << std::endl;
	std::cout << "the       " << dataAhrs.the() << std::endl;
	std::cout << "psi       " << dataAhrs.psi() << std::endl;
	std::cout << "q0        " << dataAhrs.q0() << std::endl;
	std::cout << "q1        " << dataAhrs.q1() << std::endl;
	std::cout << "q2        " << dataAhrs.q2() << std::endl;
	std::cout << "q3        " << dataAhrs.q3() << std::endl;
	std::cout << "alive     " << dataAhrs.alive() << std::endl;

	return true;
}
