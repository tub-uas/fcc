#ifndef AHRS_H
#define AHRS_H

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

#include "./idl/DataAhrsPubSubTypes.h"

#include "../../util/ahrsCom/ahrsCom.h"
#include "../../util/timer/timer.h"

using namespace eprosima::fastdds::dds;

class Listener : public DataWriterListener
{

public:

	Listener();

	~Listener() override;

	void on_publication_matched(DataWriter*,
	                            const PublicationMatchedStatus& info) override;

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
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Listener           listener;

	Topic       *topicAhrs;
	DataWriter  *writerAhrs;
	TypeSupport  typeAhrs;
	DataAhrs     dataAhrs;
	std::mutex   dataAhrsMutex;

	AhrsCom ahrsCom;
	Timer   timer;

};

#endif // AHRS_H
