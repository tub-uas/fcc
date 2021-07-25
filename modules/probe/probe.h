#ifndef PROBE_H
#define PROBE_H

#include <iostream>
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

#include "./idl/DataDownlinkPubSubTypes.h"
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../raiOut/idl/DataRaiOutPubSubTypes.h"
#include "./../sFusion/idl/DataSFusionPubSubTypes.h"
#include "./../ahrs/idl/DataAhrsPubSubTypes.h"
#include "./../air/idl/DataAirPubSubTypes.h"
#include "./../gps/idl/DataGpsPubSubTypes.h"
#include "./../psu/idl/DataPsuPubSubTypes.h"
#include "./../ctrl/idl/DataCtrlPubSubTypes.h"
#include "./../watchdog/idl/DataWatchdogPubSubTypes.h"


#define PRINT_DATA(stringname,data) (std::cout << "["stringname "] " << data << std::endl; )



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
	DataGps dataGps;
	std::mutex dataGpsMutex;
	std::atomic_bool newDataGps;
	DataPsu dataPsu;
	std::mutex dataPsuMutex;
	std::atomic_bool newDataPsu;
	DataCtrl dataCtrl;
	std::mutex dataCtrlMutex;
	std::atomic_bool newDataCtrl;
	DataWatchdog dataWatchdog;
	std::mutex dataWatchdogMutex;
	std::atomic_bool newDataWatchdog;

private:
	std::atomic_int publication_matched;
	std::atomic_int subscription_matched;

};


class Probe
{

public:
	const std::string name = std::string("Probe");

	const uint8_t sysid  = 0;
	const uint8_t compid = 0;

	Probe(std::string to_listen);
	virtual ~Probe();

	bool init();
	void run();
	
	void print();

	void print_RaiOut();
	void print_RaiIn();
	void print_SFusion();
	void print_Ahrs();
	void print_Air();
	void print_Gps();
	void print_Psu();
	void print_Ctrl();
	void print_Watchdog();
	
	const unsigned long long aliveReset = 1e5; // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener                                   listener;

	eprosima::fastdds::dds::Topic       *topic_probe;
	eprosima::fastdds::dds::DataReader  *reader_probe;
	eprosima::fastdds::dds::TypeSupport  type_probe;

	std::string _topicname;
	std::string _data_topic_name{"Data"};
	bool _run{true};	
};

#endif // DOWNLINK_H
