#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <atomic>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

/***PYTHON_GEN_PUBSUB*/
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../ctrl/idl/DataCtrlPubSubTypes.h"

#include "../../util/timer/timer.h"

class Listener : public eprosima::fastdds::dds::DataReaderListener
{
public:

	Listener();

	~Listener() override;

	void on_subscription_matched(eprosima::fastdds::dds::DataReader*,
	                             const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

	void on_data_available(eprosima::fastdds::dds::DataReader *reader) override;

	/***PYTHON_GEN_DATA_MUTEX*/
	DataRaiIn dataRaiIn;
	std::mutex dataRaiInMutex;
	std::atomic_bool newDataRaiIn;
	DataCtrl dataCtrl;
	std::mutex dataCtrlMutex;
	std::atomic_bool newDataCtrl;

private:
	std::atomic_int subscription_matched;

};


class Log
{

public:
	const std::string name = std::string("Log");

	Log();
	virtual ~Log();

	bool init();
	void run();

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener                                   listener;

	/***PYTHON_GEN_TOPIC*/
	eprosima::fastdds::dds::Topic       *topicRaiIn;
	eprosima::fastdds::dds::DataReader  *readerRaiIn;
	eprosima::fastdds::dds::TypeSupport  typeRaiIn;
	eprosima::fastdds::dds::Topic       *topicCtrl;
	eprosima::fastdds::dds::DataReader  *readerCtrl;
	eprosima::fastdds::dds::TypeSupport  typeCtrl;

	Timer  timer;

	/***PYTHON_GEN_FILES*/
	std::fstream raiInFile;
	std::fstream ctrlFile;
};

#endif // LOG_H
