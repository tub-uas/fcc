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

	DataAhrs dataAhrs;
	std::mutex dataAhrsMutex;
	std::atomic_bool newDataAhrs;

	DataAir dataAir;
	std::mutex dataAirMutex;
	std::atomic_bool newDataAir;

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
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Subscriber        *subscriber;
	Listener           listener;

	Topic       *topicSFusion;
	DataWriter  *writerSFusion;
	TypeSupport  typeSFusion;
	DataSFusion  dataSFusion;
	std::mutex   dataSFusionMutex;

	Topic       *topicAhrs;
	DataReader  *readerAhrs;
	TypeSupport  typeAhrs;

	Topic       *topicAir;
	DataReader  *readerAir;
	TypeSupport  typeAir;

	Timer  timer;

};

#endif // SFUSION_H
