#ifndef FRTPSBASE_H
#define FRTPSBASE_H

#include <cstdint>
#include <iostream>
// PARTICIPANT
#include <fastrtps/Domain.h>
#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>

// PUBLISHER
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/attributes/PublisherAttributes.h>

// SUBSCRIBER
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/attributes/SubscriberAttributes.h>

// DOMAIN


using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

class FrtpsBase
{
public:
    FrtpsBase(int32_t _domainId, char *participantName);
    virtual ~FrtpsBase();

    Participant *getParticipant(void);
    void addPublisher(Publisher *pub, char *topicName, eprosima::fastrtps::TopicDataType type, eprosima::fastrtps::PublisherListener *pubListener);
    void addSubscriber(Subscriber *sub, char *topicName, TopicDataType &type, SubscriberListener &subListener);

private:  
    DomainParticipant   *_participant;
};



#endif // FRTPSBASE_H