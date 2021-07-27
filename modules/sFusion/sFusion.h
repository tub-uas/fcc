#ifndef SFUSION_H
#define SFUSION_H

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

#include "./idl/DataSFusionPubSubTypes.h"
#include "./../ahrs/idl/DataAhrsPubSubTypes.h"
#include "./../air/idl/DataAirPubSubTypes.h"
#include "./../gps/idl/DataGpsPubSubTypes.h"
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"

#include "../../util/timer/timer.h"
#include "../../util/mixer/mixer.h"
// #include "../../lib/ecf/ecf_aoa_ssa/aoa_ssa.h"
#include "../../lib/ecf/ecf_height/height.h"
// #include "../../lib/ecf/ecf_wind/wind.h"

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

	DataAhrs dataAhrs;
	std::mutex dataAhrsMutex;
	std::atomic_bool newDataAhrs;

	DataAir dataAir;
	std::mutex dataAirMutex;
	std::atomic_bool newDataAir;

	DataRaiIn dataRaiIn;
	std::mutex dataRaiInMutex;
	std::atomic_bool newDataRaiIn;

	DataGps dataGps;
	std::mutex dataGpsMutex;
	std::atomic_bool newDataGps;

private:
	std::atomic_int publication_matched;
	std::atomic_int subscription_matched;

};


class SFusion
{

public:
	const std::string name = std::string("SFusion");

	SFusion();
	virtual ~SFusion();

	bool init();
	void run();
	void publish();
	void print();

	bool update_raiIn_data();
	bool update_ahrs_data();
	bool update_air_data();
	bool update_gps_data();

	double get_z_accel(double a_x, double a_y, double a_z, double phi, double the);
	Height estimator_height;

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicSFusion;
	eprosima::fastdds::dds::DataWriter  *writerSFusion;
	eprosima::fastdds::dds::TypeSupport  typeSFusion;
	DataSFusion  dataSFusion;
	std::mutex   dataSFusionMutex;

	eprosima::fastdds::dds::Topic       *topicAhrs;
	eprosima::fastdds::dds::DataReader  *readerAhrs;
	eprosima::fastdds::dds::TypeSupport  typeAhrs;

	eprosima::fastdds::dds::Topic       *topicAir;
	eprosima::fastdds::dds::DataReader  *readerAir;
	eprosima::fastdds::dds::TypeSupport  typeAir;

	eprosima::fastdds::dds::Topic       *topicRaiIn;
	eprosima::fastdds::dds::DataReader  *readerRaiIn;
	eprosima::fastdds::dds::TypeSupport  typeRaiIn;

	eprosima::fastdds::dds::Topic       *topicGps;
	eprosima::fastdds::dds::DataReader  *readerGps;
	eprosima::fastdds::dds::TypeSupport  typeGps;

	Timer  timer;

	// RAI IN
	DataRaiIn _raiIn_data;
	bool _raiIn_alive{false};

	// AHRS
	DataAhrs _ahrs_data;
	bool _ahrs_alive{false};

	// AIR
	DataAir _air_data;
	bool _air_alive{false};
	

	// GPS
	DataGps _gps_data;
	bool _gps_alive{false};

	bool _publish_now{false};
};

#endif // SFUSION_H
