#ifndef GPS_H
#define GPS_H

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

#include "./idl/DataGpsPubSubTypes.h"

#include "../../util/gpsCom/gpsCom.h"
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


class Gps
{

public:
	const std::string name = std::string("Gps");

	Gps();
	virtual ~Gps();

	bool init();
	void run();
	void publish();
	bool print();

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicGps;
	eprosima::fastdds::dds::DataWriter  *writerGps;
	eprosima::fastdds::dds::TypeSupport  typeGps;
	DataGps      dataGps;
	std::mutex   dataGpsMutex;

	GpsCom gpsCom;
	Timer   timer;

};

#endif // GPS_H
