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
#include "../../util/timer/timer.h"

using namespace eprosima::fastdds::dds;

class Listener : public DataWriterListener, public DataReaderListener
{
public:

	Listener();

	~Listener() override;

	void on_publication_matched(DataWriter*,
	                            const PublicationMatchedStatus& info) override;

	void on_subscription_matched(DataReader*,
	                             const SubscriptionMatchedStatus& info) override;

    void on_data_available(DataReader *reader) override;

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
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Subscriber        *subscriber;
	Listener           listener;

	Topic       *topicCtrl;
	DataWriter  *writerCtrl;
	TypeSupport  typeCtrl;
	DataCtrl     dataCtrl;
	std::mutex   dataCtrlMutex;

	Topic       *topicRaiIn;
	DataReader  *readerRaiIn;
	TypeSupport  typeRaiIn;

	Topic       *topicSFusion;
	DataReader  *readerSFusion;
	TypeSupport  typeSFusion;

	Timer  timer;
	Pid    pidRoll;
	Pid    pidPitch;
	Pid    pidYaw;

};

#endif // CTRL_H
