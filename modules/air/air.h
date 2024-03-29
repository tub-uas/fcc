#ifndef AIR_H
#define AIR_H

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

#include "./idl/DataAirPubSubTypes.h"

// == SITL RUN 
#ifdef SITL
	#include "../../../airComSitl/airComSitl.h"
#else
	#include "../../util/airCom/airCom.h"
#endif

#include "../../util/timer/timer.h"

class Listener : public eprosima::fastdds::dds::DataWriterListener
{

public:

	Listener();

	~Listener() override;

	void on_publication_matched(eprosima::fastdds::dds::DataWriter*,
	                            const eprosima::fastdds::dds::PublicationMatchedStatus& info) override;

private:
	std::atomic_int publication_matched;

};


class Air
{

public:
	const std::string name = std::string("Air");

	Air();
	virtual ~Air();

	bool init();
	void run();
	void publish();
	void print();

	double get_barometric_height();
	double get_indicated_airspeed();
	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	Listener           listener;

	eprosima::fastdds::dds::Topic       *topicAir;
	eprosima::fastdds::dds::DataWriter  *writerAir;
	eprosima::fastdds::dds::TypeSupport  typeAir;
	DataAir      dataAir;
	std::mutex   dataAirMutex;


	AirCom  airCom;
	Timer   timer;

	bool _publish_now{false};
};

#endif // AIR_H
