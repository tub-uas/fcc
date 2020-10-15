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

#include "./idl/DataLogPubSubTypes.h"

/***PYTHON_GEN_PUBSUB*/
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../raiOut/idl/DataRaiOutPubSubTypes.h"
#include "./../sFusion/idl/DataSFusionPubSubTypes.h"
#include "./../ahrs/idl/DataAhrsPubSubTypes.h"
#include "./../air/idl/DataAirPubSubTypes.h"
#include "./../psu/idl/DataPsuPubSubTypes.h"
#include "./../ctrl/idl/DataCtrlPubSubTypes.h"
#include "./../downlink/idl/DataDownlinkPubSubTypes.h"

#include "../../util/timer/timer.h"

class Listener : public eprosima::fastdds::dds::DataWriterListener, public eprosima::fastdds::dds::DataReaderListener
{
public:

	Listener();

	~Listener() override;

	void on_publication_matched(eprosima::fastdds::dds::DataWriter*,
	                            const eprosima::fastdds::dds::PublicationMatchedStatus& info) override;

	void on_subscription_matched(eprosima::fastdds::dds::DataReader*,
	                             const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

	void on_data_available(eprosima::fastdds::dds::DataReader *reader) override;

	/***PYTHON_GEN_DATA_MUTEX*/
	DataRaiIn dataRaiIn;
	std::mutex dataRaiInMutex;
	std::atomic_bool newDataRaiIn;
	DataRaiOut dataRaiOut;
	std::mutex dataRaiOutMutex;
	std::atomic_bool newDataRaiOut;
	DataSFusion dataSFusion;
	std::mutex dataSFusionMutex;
	std::atomic_bool newDataSFusion;
	DataAhrs dataAhrs;
	std::mutex dataAhrsMutex;
	std::atomic_bool newDataAhrs;
	DataAir dataAir;
	std::mutex dataAirMutex;
	std::atomic_bool newDataAir;
	DataPsu dataPsu;
	std::mutex dataPsuMutex;
	std::atomic_bool newDataPsu;
	DataCtrl dataCtrl;
	std::mutex dataCtrlMutex;
	std::atomic_bool newDataCtrl;
	DataDownlink dataDownlink;
	std::mutex dataDownlinkMutex;
	std::atomic_bool newDataDownlink;

private:
	std::atomic_int publication_matched;
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
	void publish();
	void print();

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener                                   listener;

	eprosima::fastdds::dds::Topic        *topicLog;
	eprosima::fastdds::dds::DataWriter   *writerLog;
	eprosima::fastdds::dds::TypeSupport   typeLog;
	DataLog       dataLog;
	std::mutex    dataLogMutex;

	/***PYTHON_GEN_TOPIC*/
	eprosima::fastdds::dds::Topic       *topicRaiIn;
	eprosima::fastdds::dds::DataReader  *readerRaiIn;
	eprosima::fastdds::dds::TypeSupport  typeRaiIn;
	eprosima::fastdds::dds::Topic       *topicRaiOut;
	eprosima::fastdds::dds::DataReader  *readerRaiOut;
	eprosima::fastdds::dds::TypeSupport  typeRaiOut;
	eprosima::fastdds::dds::Topic       *topicSFusion;
	eprosima::fastdds::dds::DataReader  *readerSFusion;
	eprosima::fastdds::dds::TypeSupport  typeSFusion;
	eprosima::fastdds::dds::Topic       *topicAhrs;
	eprosima::fastdds::dds::DataReader  *readerAhrs;
	eprosima::fastdds::dds::TypeSupport  typeAhrs;
	eprosima::fastdds::dds::Topic       *topicAir;
	eprosima::fastdds::dds::DataReader  *readerAir;
	eprosima::fastdds::dds::TypeSupport  typeAir;
	eprosima::fastdds::dds::Topic       *topicPsu;
	eprosima::fastdds::dds::DataReader  *readerPsu;
	eprosima::fastdds::dds::TypeSupport  typePsu;
	eprosima::fastdds::dds::Topic       *topicCtrl;
	eprosima::fastdds::dds::DataReader  *readerCtrl;
	eprosima::fastdds::dds::TypeSupport  typeCtrl;
	eprosima::fastdds::dds::Topic       *topicDownlink;
	eprosima::fastdds::dds::DataReader  *readerDownlink;
	eprosima::fastdds::dds::TypeSupport  typeDownlink;

	Timer  timer;

	/***PYTHON_GEN_FILES*/
	std::fstream raiInFile;
	std::fstream raiOutFile;
	std::fstream sFusionFile;
	std::fstream ahrsFile;
	std::fstream airFile;
	std::fstream psuFile;
	std::fstream ctrlFile;
	std::fstream downlinkFile;
};

#endif // LOG_H
