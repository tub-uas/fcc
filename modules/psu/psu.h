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


class Psu
{

public:
	const std::string name = std::string("Psu");

	Psu();
	virtual ~Psu();

	bool init();
	void run();
	void publish();
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Listener           listener;

	Topic       *topicPsu;
	DataWriter  *writerPsu;
	TypeSupport  typePsu;
	DataPsu      dataPsu;
	std::mutex   dataPsuMutex;

	PsuCom psuCom;
	Timer   timer;

};

#endif // PSU_H
