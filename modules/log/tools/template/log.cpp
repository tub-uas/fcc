#include "log.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include <cstdint>
#include <endian.h> // todo: implement plafform independent endianess (host to little endian)

#include <boost/filesystem.hpp>


Listener::Listener() : publication_matched(0),
                       subscription_matched(0) {
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

void Listener::on_subscription_matched(eprosima::fastdds::dds::DataReader*,
                                       const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) {

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

void Listener::on_data_available(eprosima::fastdds::dds::DataReader* reader) {

	eprosima::fastdds::dds::SampleInfo info;
	std::string topic = reader->get_topicdescription()->get_name();

	/***PYTHON_GEN_ON_DATA_CALLBACK*/

}

Log::Log() : participant(nullptr),
             publisher(nullptr),
             subscriber(nullptr),
             topicLog(nullptr),
             writerLog(nullptr),
             typeLog(new DataLogPubSubType()),
             /***PYTHON_GEN_CONSTR*/

}

Log::~Log() {

	if (writerLog != nullptr) {
		publisher->delete_datawriter(writerLog);
	}
	if (topicLog != nullptr) {
		participant->delete_topic(topicLog);
	}
	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	/***PYTHON_GEN_DELETE*/

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

	/***PYTHON_GEN_CLOSE_FILES*/
}

bool Log::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("LogParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeLog.register_type(participant);
	// Create the publications Topic
	topicLog = participant->create_topic("DataLog", "DataLog", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicLog == nullptr) {
		return false;
	}
	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}
	// Create the DataWriter
	writerLog = publisher->create_datawriter(topicLog, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerLog == nullptr) {
		return false;
	}

	/***PYTHON_GEN_REGISTER_TYPE*/

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	/***PYTHON_GEN_CREATE_DATAREADER*/

	aliveTime = timer.getSysTime();

	time_t t_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm local_tm_now = *localtime(&t_now);

	std::stringstream logdir;
	logdir << "../logs/" << std::flush;

	// Create log directory
	if (!boost::filesystem::exists(logdir.str())) {
		boost::filesystem::create_directory(logdir.str());
	}

	logdir << local_tm_now.tm_year + 1900 << "-"
	       << local_tm_now.tm_mon + 1 << "-"
	       << local_tm_now.tm_mday << "-"
	       << local_tm_now.tm_hour << "-"
	       << local_tm_now.tm_min << "-"
	       << local_tm_now.tm_sec << std::flush;

	// Create sub directory with date and time
	if (!boost::filesystem::exists(logdir.str())) {
		boost::filesystem::create_directory(logdir.str());
	}

	/***PYTHON_GEN_OPEN_FILES*/

	return true;
}

void Log::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataLogLock {dataLogMutex};
		dataLog.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataLog.alive(true);
		} else {
			dataLog.alive(false);
		}

		writerLog->write(&dataLog);
		dataLogLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Log::run() {

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		/***PYTHON_GEN_WRITE_FILES*/

		// reset the alive timer
		aliveTime = timer.getSysTime();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}
}

void Log::print() {

	std::cout << "--- " << this->name << " " << dataLog.time() << " ---" << std::endl;

	std::cout << "alive   " << dataLog.alive() << std::endl;

}
