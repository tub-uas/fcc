#ifndef RAIIN_H
#define RAIIN_H

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

#include "./idl/DataRaiInPubSubTypes.h"

#include "../../util/raiCom/raiCom.h"
#include "../../util/mixer/mixer.h"
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


class RaiIn
{

public:
	const std::string name = std::string("RaiIn");

	RaiIn();
	virtual ~RaiIn();

	bool init();
	void run();
	void publish();
	bool print();

private:

	DomainParticipant *participant;
	Publisher         *publisher;
	Listener           listener;

	Topic       *topicRaiIn;
	DataWriter  *writerRaiIn;
	TypeSupport  typeRaiIn;
	DataRaiIn    dataRaiIn;
	std::mutex   dataRaiInMutex;

	RaiCom raiCom;
	Mixer  mixer;
	Timer  timer;

};

#endif // RAIIN_H