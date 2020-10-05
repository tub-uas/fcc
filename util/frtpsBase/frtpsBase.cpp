#include "frtpsBase.h"


FrtpsBase::FrtpsBase(int32_t _domainId, char *participantName) {
    std::cout << "Create Participant - " << participantName << std::endl; 
    std::cout << "Domain ID - " << _domainId << std::endl;

    _par_att.rtps.builtin.domainId      = _domainId;
    _par_att.rtps.builtin.leaseDuration = c_TimeInfinite;
    _par_att.rtps.setName(participantName);
    
    // == CREATE PARTICIPANT
    
    _participant = Domain::createParticipant(_par_att);
    if(_participant == nullptr) {
        std::cerr << "Participant creation ... [FAILED]" << std::endl;
        return;
    }      
}


FrtpsBase::~FrtpsBase() {
    Domain::removeParticipant(_participant);
}



Participant * FrtpsBase::getParticipant(void) {
    return _participant;
}
    

void FrtpsBase::addPublisher(Publisher *pub, char *topicName, static eprosima::fastrtps::TopicDataType type , eprosima::fastrtps::PublisherListener *pubListener) {
    PublisherAttributes pub_att;
    pub_att.topic.topicKind     = NO_KEY;
    pub_att.topic.topicDataType = type.getName();
    pub_att.topic.topicName     = topicName;
    
    Domain::registerType(   _participant,
                            static_cast<TopicDataType*>(&type));
    pub = Domain::createPublisher(  _participant,
                                    pub_att,
                                    static_cast<PublisherListener*>(pubListener));
    if(pub == nullptr) {
        std::cerr << "Publisher " << topicName << " creation ... [FAILED]" << std::endl;
    }
}


void FrtpsBase::addSubscriber(Subscriber *sub, char *topicName, TopicDataType &type, SubscriberListener &subListener) {
    SubscriberAttributes sub_att;
    sub_att.topic.topicKind     = NO_KEY;
    sub_att.topic.topicDataType = type.getName();
    sub_att.topic.topicName     = topicName;

    sub = Domain::createSubscriber( _participant,
                                    sub_att,
                                    static_cast<SubscriberListener*>(&subListener));
    
    if(sub == nullptr) {
        std::cerr << "Subscriber " << topicName << " creation ... [FAILED]" << std::endl;
    }
}