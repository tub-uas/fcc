#include "psu.h"

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

Psu::Psu() : participant(nullptr),
             publisher(nullptr),
             topicPsu(nullptr),
             writerPsu(nullptr),
             typePsu(new DataPsuPubSubType()) {
}

Psu::~Psu() {

	if (writerPsu != nullptr) {
		publisher->delete_datawriter(writerPsu);
	}

	if (topicPsu != nullptr) {
		participant->delete_topic(topicPsu);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Psu::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("PsuParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typePsu.register_type(participant);

	// Create the publications Topic
	topicPsu = participant->create_topic("DataPsu", "DataPsu", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicPsu == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerPsu = publisher->create_datawriter(topicPsu, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerPsu == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (psuCom.init() == false) {
		return false;
	}

	return true;
}


void Psu::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};
		dataPsu.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataPsu.alive(true);
		} else {
			dataPsu.alive(false);
		}

		writerPsu->write(&dataPsu);
		dataPsuLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Psu::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (psuCom.receive()) {

			std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};

			dataPsu.senseTime(psuCom.time);
			dataPsu.main_volt(psuCom.mainVolt);
			dataPsu.main_curr(psuCom.mainCurr);
			dataPsu.main_pwr(psuCom.mainPow);
			dataPsu.pwr_volt(psuCom.pwrVolt);
			dataPsu.pwr_curr(psuCom.pwrCurr);
			dataPsu.pwr_pwr(psuCom.pwrPow);
			dataPsu.sys_volt(psuCom.sysVolt);
			dataPsu.sys_curr(psuCom.sysCurr);
			dataPsu.sys_pwr(psuCom.sysPow);

			// reset the alive timer
			aliveTime = timer.getSysTime();

			dataPsuLock.unlock();

			// psuCom.print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

void Psu::print() {

	std::cout << "--- " << this->name << " " << dataPsu.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataPsu.senseTime() << std::endl;
	std::cout << "mainVolt  " << dataPsu.main_volt() << std::endl;
	std::cout << "mainCurr  " << dataPsu.main_curr() << std::endl;
	std::cout << "mainPow   " << dataPsu.main_pwr() << std::endl;
	std::cout << "pwrVolt   " << dataPsu.pwr_volt() << std::endl;
	std::cout << "pwrCurr   " << dataPsu.pwr_curr() << std::endl;
	std::cout << "pwrPow    " << dataPsu.pwr_pwr() << std::endl;
	std::cout << "sysVolt   " << dataPsu.sys_volt() << std::endl;
	std::cout << "sysCurr   " << dataPsu.sys_curr() << std::endl;
	std::cout << "sysPow    " << dataPsu.sys_pwr() << std::endl;
	std::cout << "alive     " << dataPsu.alive() << std::endl;

}
