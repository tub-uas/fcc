#include "log.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include <cstdint>
#include <endian.h> // TODO implement plafform independent endianess (host to little endian)

#include <boost/filesystem.hpp>


Listener::Listener() : subscription_matched(0) {
}

Listener::~Listener() {
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
	void* data = reader->type().create_data();

	while (reader->read_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK) {
		if (info.instance_state == eprosima::fastdds::dds::ALIVE && info.valid_data) {
			/***PYTHON_GEN_ON_DATA_CALLBACK*/
			if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {
				std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
				reader->take_next_sample(&dataRaiIn, &info);
				dataRaiInLock.unlock();
				newDataRaiIn = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
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

Log::Log() : participant(nullptr),
             subscriber(nullptr),
             /***PYTHON_GEN_CONSTR*/
             topicRaiIn(nullptr),
             readerRaiIn(nullptr),
             typeRaiIn(new DataRaiInPubSubType()),
             topicCtrl(nullptr),
             readerCtrl(nullptr),
             typeCtrl(new DataCtrlPubSubType()) {

}

Log::~Log() {

	/***PYTHON_GEN_DELETE*/
	if (readerRaiIn != nullptr) {
		subscriber->delete_datareader(readerRaiIn);
	}
	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
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

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

	/***PYTHON_GEN_CLOSE_FILES*/
	raiInFile.close();
	ctrlFile.close();
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

	/***PYTHON_GEN_REGISTER_TYPE*/
	// Register the Type
	typeRaiIn.register_type(participant);
	// Create the subscriptions Topic
	topicRaiIn = participant->create_topic("DataRaiIn", "DataRaiIn", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicRaiIn == nullptr) {
		return false;
	}
	// Register the Type
	typeCtrl.register_type(participant);
	// Create the subscriptions Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	/***PYTHON_GEN_CREATE_DATAREADER*/
	// Create the DataReader
	readerRaiIn = subscriber->create_datareader(topicRaiIn, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerRaiIn == nullptr) {
		return false;
	}
	// Create the DataReader
	readerCtrl = subscriber->create_datareader(topicCtrl, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerCtrl == nullptr) {
		return false;
	}

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
	raiInFile.open(logdir.str() + "/raiIn.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	ctrlFile.open(logdir.str() + "/ctrl.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);

	return true;
}

void Log::run() {

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		/***PYTHON_GEN_WRITE_FILES*/
		if (listener.newDataRaiIn) {
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			std::cout << "newDataRaiIn" << std::endl;
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.time()), sizeof(listener.dataRaiIn.time()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.senseTime()), sizeof(listener.dataRaiIn.senseTime()));
			for (unsigned int i=0; i<listener.dataRaiIn.chnl().size(); i++) {
				raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.chnl().at(i)), sizeof(listener.dataRaiIn.chnl().at(i)));
			}
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.roll()), sizeof(listener.dataRaiIn.roll()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.pitch()), sizeof(listener.dataRaiIn.pitch()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.yaw()), sizeof(listener.dataRaiIn.yaw()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.thr()), sizeof(listener.dataRaiIn.thr()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.fltMode()), sizeof(listener.dataRaiIn.fltMode()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.alive()), sizeof(listener.dataRaiIn.alive()));
			raiInFile.flush();
			dataRaiInLock.unlock();
			listener.newDataRaiIn = false;
		}
		if (listener.newDataCtrl) {
			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			std::cout << "newDataCtrl" << std::endl;
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.time()), sizeof(listener.dataCtrl.time()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.xi()), sizeof(listener.dataCtrl.xi()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.eta()), sizeof(listener.dataCtrl.eta()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.zeta()), sizeof(listener.dataCtrl.zeta()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.etaT()), sizeof(listener.dataCtrl.etaT()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.etaF()), sizeof(listener.dataCtrl.etaF()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.fltMode()), sizeof(listener.dataCtrl.fltMode()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.alive()), sizeof(listener.dataCtrl.alive()));
			ctrlFile.flush();
			dataCtrlLock.unlock();
			listener.newDataCtrl = false;
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(2);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(2);
	}
}
