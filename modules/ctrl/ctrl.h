#ifndef CTRL_H
#define CTRL_H

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

#include "./idl/DataCtrlPubSubTypes.h"
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../sFusion/idl/DataSFusionPubSubTypes.h"

#include "../../util/pid/pid.h"
#include "../../util/mixer/mixer.h"
#include "../../util/sigGen/sigGen.h"
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

	DataRaiIn dataRaiIn;
	std::mutex dataRaiInMutex;
	std::atomic_bool newDataRaiIn;

	DataSFusion dataSFusion;
	std::mutex dataSFusionMutex;
	std::atomic_bool newDataSFusion;

private:
	std::atomic_int publication_matched;
	std::atomic_int subscription_matched;

};


class Ctrl
{

public:
	const std::string name = std::string("Ctrl");

	Ctrl();
	virtual ~Ctrl();

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
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicCtrl;
	eprosima::fastdds::dds::DataWriter  *writerCtrl;
	eprosima::fastdds::dds::TypeSupport  typeCtrl;
	DataCtrl     dataCtrl;
	std::mutex   dataCtrlMutex;

	eprosima::fastdds::dds::Topic       *topicRaiIn;
	eprosima::fastdds::dds::DataReader  *readerRaiIn;
	eprosima::fastdds::dds::TypeSupport  typeRaiIn;

	eprosima::fastdds::dds::Topic       *topicSFusion;
	eprosima::fastdds::dds::DataReader  *readerSFusion;
	eprosima::fastdds::dds::TypeSupport  typeSFusion;

	Timer  timer;
	Pid    pidRoll;
	Pid    pidPitch;
	Pid    pidYaw;
	SigGen sigGen;

};

#endif // CTRL_H
