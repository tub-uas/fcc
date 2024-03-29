#ifndef RAIOUT_H
#define RAIOUT_H

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

#include "./idl/DataRaiOutPubSubTypes.h"
#include "./../ctrl/idl/DataCtrlPubSubTypes.h"

#ifdef SITL
	#include "../../../raiComSitl/raiComSitl.h"
#else
	#include "../../util/raiCom/raiCom.h"
#endif
#include "../../util/can_util/can_meta.h"

#include "../../util/mixer/mixer.h"
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

	DataCtrl dataCtrl;
	std::mutex dataCtrlMutex;
	std::atomic_bool newDataCtrl;

private:
	std::atomic_int publication_matched;
	std::atomic_int subscription_matched;

};


class RaiOut
{

public:
	const std::string name = std::string("RaiOut");

	RaiOut();
	virtual ~RaiOut();

	bool init();
	void run();
	void publish();
	void print();

	bool update_ctrl_data();

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicRaiOut;
	eprosima::fastdds::dds::DataWriter  *writerRaiOut;
	eprosima::fastdds::dds::TypeSupport  typeRaiOut;
	DataRaiOut   dataRaiOut;
	std::mutex   dataRaiOutMutex;

	eprosima::fastdds::dds::Topic       *topicCtrl;
	eprosima::fastdds::dds::DataReader  *readerCtrl;
	eprosima::fastdds::dds::TypeSupport  typeCtrl;

	RaiCom raiCom;
	Mixer  mixer;
	Timer  timer;

	double _xi;
	double _eta;
	double _zeta;
	double _throttle;
	double _flaps;
	double _roll;
	double _pitch;
	double _yaw;
	double _tas;
	double _hgt;
	double _roll_rate;
	double _pitch_rate;
	double _yaw_rate;
	double _tas_rate;
	double _hgt_rate;
	flight_mode_t _flight_mode;
	flight_fct_t _flight_fct;
	
	bool _ctrl_alive{false};
	bool _publish_now{false};

};

#endif // RAIOUT_H
