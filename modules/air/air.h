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

#include "../../util/airCom/airCom.h"
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


class Air
{

public:
	const std::string name = std::string("Air");

	Air();
	virtual ~Air();

	bool init();
	void run();
	void publish();
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Listener           listener;

	Topic       *topicAir;
	DataWriter  *writerAir;
	TypeSupport  typeAir;
	DataAir      dataAir;
	std::mutex   dataAirMutex;

	AirCom  airCom;
	Timer   timer;

};

#endif // AIR_H
