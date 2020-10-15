#ifndef PSU_H
#define PSU_H

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

#include "./idl/DataPsuPubSubTypes.h"

#include "../../util/psuCom/psuCom.h"
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


class Psu
{

public:
	const std::string name = std::string("Psu");

	Psu();
	virtual ~Psu();

	bool init();
	void run();
	void publish();
	void print();

	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicPsu;
	eprosima::fastdds::dds::DataWriter  *writerPsu;
	eprosima::fastdds::dds::TypeSupport  typePsu;
	DataPsu      dataPsu;
	std::mutex   dataPsuMutex;

	PsuCom psuCom;
	Timer   timer;

};

#endif // PSU_H
