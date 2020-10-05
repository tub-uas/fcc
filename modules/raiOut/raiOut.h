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

#include "../../util/raiCom/raiCom.h"
#include "../../util/can_util/can_meta.h"
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
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Subscriber        *subscriber;
	Listener           listener;

	Topic       *topicRaiOut;
	DataWriter  *writerRaiOut;
	TypeSupport  typeRaiOut;
	DataRaiOut   dataRaiOut;
	std::mutex   dataRaiOutMutex;

	Topic       *topicCtrl;
	DataReader  *readerCtrl;
	TypeSupport  typeCtrl;

	RaiCom raiCom;
	Mixer  mixer;
	Timer  timer;

};

#endif // RAIOUT_H
