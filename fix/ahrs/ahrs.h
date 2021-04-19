#ifndef AHRS_H
#define AHRS_H

#include <iostream>
#include <mutex>
#include <atomic>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>



#include "./idl/DataAhrsPubSubTypes.h"

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/PublisherListener.h>

#include "../../util/ahrsCom/ahrsCom.h"
#include "../../util/timer/timer.h"

class Listener : public eprosima::fastrtps::PublisherListener
{

public:

	Listener();

	~Listener() override;

	void onPublicationMatched(eprosima::fastrtps::Publisher *pub,
	                            const eprosima::fastrtps::rtps::MatchingInfo& info);

private:
	std::atomic_int publication_matched;
};


class Ahrs
{

public:
	const std::string name = std::string("Ahrs");

	Ahrs();
	virtual ~Ahrs();

	bool init();
	void run();
	void publish();
	void print();

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:
	std::mutex                       dataAhrsMutex;
	eprosima::fastrtps::Participant *participant;
	eprosima::fastrtps::Publisher   *publisher;
	Listener                         listener;

	DataAhrsPubSubType               typeAhrs;
	DataAhrs                         dataAhrs;


	AhrsCom ahrsCom;
	Timer   timer;

};

#endif // AHRS_H
