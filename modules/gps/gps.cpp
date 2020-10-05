#include "gps.h"

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

Gps::Gps() : participant(nullptr),
               publisher(nullptr),
               topicGps(nullptr),
               writerGps(nullptr),
               typeGps(new DataGpsPubSubType()) {
}

Gps::~Gps() {

	if (writerGps != nullptr) {
		publisher->delete_datawriter(writerGps);
	}

	if (topicGps != nullptr) {
		participant->delete_topic(topicGps);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Gps::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	DomainParticipantQos participantQos;
	participantQos.name("GpsParticipant");
	participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeGps.register_type(participant);

	// Create the publications Topic
	topicGps = participant->create_topic("DataGps", "DataGps", TOPIC_QOS_DEFAULT);
	if (topicGps == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerGps = publisher->create_datawriter(topicGps, DATAWRITER_QOS_DEFAULT, &listener);
	if (writerGps == nullptr) {
		return false;
	}

	if (gpsCom.init() == false) {
		return false;
	}

	return true;
}


void Gps::publish() {

	while (1) {

		std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};
		dataGps.time(timer.getSysTime());
		dataGps.alive(true);

		writerGps->write(&dataGps);
		dataGpsLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Gps::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (gpsCom.receive()) {

			std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};

			dataGps.senseTime(gpsCom.time);
			dataGps.gyrX(gpsCom.gyr[0]);
			dataGps.gyrY(gpsCom.gyr[1]);
			dataGps.gyrZ(gpsCom.gyr[2]);
			dataGps.accX(gpsCom.acc[0]);
			dataGps.accY(gpsCom.acc[1]);
			dataGps.accZ(gpsCom.acc[2]);
			dataGps.magX(gpsCom.mag[0]);
			dataGps.magY(gpsCom.mag[1]);
			dataGps.magZ(gpsCom.mag[3]);
			dataGps.temp(gpsCom.temp);
			dataGps.press(gpsCom.press);
			dataGps.phi(gpsCom.att[0]);
			dataGps.the(gpsCom.att[1]);
			dataGps.psi(gpsCom.att[2]);
			dataGps.p0(-1.0);
			dataGps.p1(-2.0);
			dataGps.p2(-3.0);
			dataGps.p3(-4.0);

			dataGpsLock.unlock();

			// gpsCom.print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

bool Gps::print() {

	std::cout << "--- " << this->name << " " << dataGps.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataGps.senseTime() << std::endl;
	std::cout << "gyrX      " << dataGps.gyrX() << std::endl;
	std::cout << "gyrY      " << dataGps.gyrY() << std::endl;
	std::cout << "gyrZ      " << dataGps.gyrZ() << std::endl;
	std::cout << "accX      " << dataGps.accX() << std::endl;
	std::cout << "accY      " << dataGps.accY() << std::endl;
	std::cout << "accZ      " << dataGps.accZ() << std::endl;
	std::cout << "magX      " << dataGps.magX() << std::endl;
	std::cout << "magY      " << dataGps.magY() << std::endl;
	std::cout << "magZ      " << dataGps.magZ() << std::endl;
	std::cout << "temp      " << dataGps.temp() << std::endl;
	std::cout << "press     " << dataGps.press() << std::endl;
	std::cout << "phi       " << dataGps.phi() << std::endl;
	std::cout << "the       " << dataGps.the() << std::endl;
	std::cout << "psi       " << dataGps.psi() << std::endl;
	std::cout << "p0        " << dataGps.p0() << std::endl;
	std::cout << "p1        " << dataGps.p1() << std::endl;
	std::cout << "p2        " << dataGps.p2() << std::endl;
	std::cout << "p3        " << dataGps.p3() << std::endl;
	std::cout << "alive     " << dataGps.alive() << std::endl;

	return true;
}
