#include "air.h"

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

Air::Air() : participant(nullptr),
             publisher(nullptr),
             topicAir(nullptr),
             writerAir(nullptr),
             typeAir(new DataAirPubSubType()) {

}

Air::~Air() {

	if (writerAir != nullptr) {
		publisher->delete_datawriter(writerAir);
	}

	if (topicAir != nullptr) {
		participant->delete_topic(topicAir);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Air::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("AirParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeAir.register_type(participant);

	// Create the publications Topic
	topicAir = participant->create_topic("DataAir", "DataAir", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicAir == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerAir = publisher->create_datawriter(topicAir, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerAir == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (airCom.init() == false) {
		return false;
	}

	return true;
}


void Air::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataAirLock {dataAirMutex};
		dataAir.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataAir.alive(true);
		} else {
			dataAir.alive(false);
		}

		writerAir->write(&dataAir);
		dataAirLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Air::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (airCom.receive()) {

			std::unique_lock<std::mutex> dataAirLock {dataAirMutex};

			dataAir.senseTime(airCom.time);
			dataAir.dynamicPress(airCom.dynamicPress);
			dataAir.velocity(airCom.velocity);
			dataAir.baroPress(airCom.baroPress);
			dataAir.density(airCom.density);
			dataAir.temp(airCom.temp);

			// reset the alive timer
			aliveTime = timer.getSysTime();

			dataAirLock.unlock();

			// airCom.print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

void Air::print() {

	std::cout << "--- " << this->name << " " << dataAir.time() << " ---" << std::endl;

	std::cout << "senseTime    " << dataAir.senseTime() << std::endl;
	std::cout << "dynamicPress " << dataAir.dynamicPress() << std::endl;
	std::cout << "velocity     " << dataAir.velocity() << std::endl;
	std::cout << "baroPress    " << dataAir.baroPress() << std::endl;
	std::cout << "density      " << dataAir.density() << std::endl;
	std::cout << "temp         " << dataAir.temp() << std::endl;
	std::cout << "alive        " << dataAir.alive() << std::endl;

}
