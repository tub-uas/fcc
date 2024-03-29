#include "ahrs.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : publication_matched(0) {
}

Listener::~Listener() {
}

void Listener::on_publication_matched(eprosima::fastdds::dds::DataWriter*,
                                      const eprosima::fastdds::dds::PublicationMatchedStatus& info) {

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

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Ahrs::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("AhrsParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeAhrs.register_type(participant);

	// Create the publications Topic
	topicAhrs = participant->create_topic("DataAhrs", "DataAhrs", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicAhrs == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerAhrs = publisher->create_datawriter(topicAhrs, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerAhrs == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (ahrsCom.init() == false) {
		return false;
	}

	return true;
}


void Ahrs::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
		dataAhrs.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataAhrs.alive(true);
		} else {
			dataAhrs.alive(false);
			std::cerr << "AHRS NOT ALIVE" << std::endl;
		}
		if(_publish_now) {
			writerAhrs->write(&dataAhrs);
			_publish_now = false;
		}
		dataAhrsLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
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
			dataAhrs.magZ(ahrsCom.mag[2]);
			dataAhrs.temperature(ahrsCom.temp);
			dataAhrs.barometric_pressure(ahrsCom.press);
			dataAhrs.phi(ahrsCom.att[0]);
			dataAhrs.the(ahrsCom.att[1]);
			dataAhrs.psi(ahrsCom.att[2]);

			// reset the alive timer
			aliveTime = timer.getSysTime();
			_publish_now = true;
			dataAhrsLock.unlock();

			// print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);

	}

}

void Ahrs::print() {

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
	std::cout << "temp      " << dataAhrs.temperature() << std::endl;
	std::cout << "press     " << dataAhrs.barometric_pressure() << std::endl;
	std::cout << "phi       " << dataAhrs.phi() << std::endl;
	std::cout << "the       " << dataAhrs.the() << std::endl;
	std::cout << "psi       " << dataAhrs.psi() << std::endl;
	std::cout << "alive     " << dataAhrs.alive() << std::endl;

}
