#ifndef SFUSION_H
#define SFUSION_H

#include <iostream>
#include <mutex>
#include <atomic>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>


#include "./idl/DataSFusionPubSubTypes.h"
#include "./../ahrs/idl/DataAhrsPubSubTypes.h"
#include "./../air/idl/DataAirPubSubTypes.h"

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/SubscriberListener.h>
#include <fastrtps/subscriber/SampleInfo.h>

#include "../../util/timer/timer.h"

class Listener : public eprosima::fastrtps::SubscriberListener
{
public:

	Listener();

	~Listener() override;

	void onSubscriptionMatched(eprosima::fastrtps::Subscriber *sub,
	                             const eprosima::fastrtps::rtps::MatchingInfo& info);

	void onNewDataMessage(eprosima::fastrtps::Subscriber *sub);

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
	//void publish();
	void print();

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastrtps::Participant *participant;
	eprosima::fastrtps::Subscriber  *subscriber;
	Listener     listener;

	std::mutex   dataSFusionMutex;

	DataAhrsPubSubType typeAhrs;
	Timer  timer;

};

#endif // SFUSION_H
