
#include "downlink_subscriber.h"
#include <iostream>

Slistener::Slistener()
{

}

Slistener::~Slistener()
{

}

void Slistener::on_subscription_matched(DataReader *, const SubscriptionMatchedStatus& info) {

}

void Slistener::on_data_available(DataReader* reader) {

    SampleInfo info;
    const TopicDescription *descr = reader->get_topicdescription();
    std::string topicName(descr->get_name());  
    
    // MAVLINK
    mavlink_message_t msg;
    uint8_t buffer[500] = {0};
    uint16_t len;
    
    if(!topicName.compare("TOPIC_MAININ")) {
        
        //mavlink_msg_ahrs_pack_chan(1,200,MAVLINK_COMM_0,&msg,);
        len = mavlink_msg_to_send_buffer(buffer,&msg);
        if(!_comSerial.send(buffer,len)) {
            std::cout << "sending failed" << std::endl;
        }
    }

    else if(!topicName.compare("TOPIC_AIR")) {

        //mavlink_msg_air_pack_chan(1,200,MAVLINK_COMM_0,&msg,9999,12.0,50.0,1);
        len = mavlink_msg_to_send_buffer(buffer,&msg);
        if(!_comSerial.send(buffer,len)) {
            std::cerr << "sending failed" << std::endl;
        }
    }
    else if(!topicName.compare("TOPIC_AHRS")) {
        
        //mavlink_msg_ahrs_pack_chan(1,200,MAVLINK_COMM_0,&msg,);
        len = mavlink_msg_to_send_buffer(buffer,&msg);
        if(!_comSerial.send(buffer,len)) {
            std::cerr << "sending failed" << std::endl;
        }
    }
    else if(!topicName.compare("TOPIC_GPS")) {

    }
    else if(!topicName.compare("TOPIC_SFUSION")) {
        //mavlink_msg_sfusion_pack_chan(1,200,MAVLINK_COMM_0,&msg);
        
    }
    else if(!topicName.compare("TOPIC_CTRL")) {
        // NO TOPIC 
    }
    else if(!topicName.compare("TOPIC_MAINOUT")) {
        
        //mavlink_msg_rc2sout_pack_chan(1,200,MAVLINK_COMM_0,&msg,);
        len = mavlink_msg_to_send_buffer(buffer,&msg);
        if(!_comSerial.send(buffer,len)) {
            std::cerr << "sending failed" << std::endl;
        }
    }
    else {
        // EMPTY
    }
}


AlxSys_downlink::AlxSys_downlink() : _participant(nullptr)
                                , _sub(nullptr)
                                , _airTopic(nullptr)
                                , _airType(new topic_airPubSubType())
                                , _ahrsTopic(nullptr)
                                , _ahrsType(new topic_ahrsPubSubType())
                                , _gpsTopic(nullptr)
                                , _gpsType(new topic_gpsPubSubType())
                                , _maininTopic(nullptr)
                                , _maininType(new topic_maininPubSubType())
                                , _sfusionTopic(nullptr)
                                , _sfusionType(new topic_sfusionPubSubType())
                                , _ctrlTopic(nullptr)
                                , _ctrlType(new topic_ctrlPubSubType())
                                , _mainoutTopic(nullptr)
                                , _mainoutType(new topic_mainoutPubSubType())
                                , _reader(nullptr) 
{

}

AlxSys_downlink::~AlxSys_downlink()
{
    if(_reader != nullptr) {
        _sub->delete_datareader(_reader);
    }

    if(_airTopic != nullptr) {
        _participant->delete_topic(_airTopic);
    }

    if(_ahrsTopic != nullptr) {
        _participant->delete_topic(_ahrsTopic);
    }

    if(_gpsTopic != nullptr) {
        _participant->delete_topic(_gpsTopic);
    }

    if(_maininTopic != nullptr) {
        _participant->delete_topic(_maininTopic);
    }

    if(_sfusionTopic != nullptr) {
        _participant->delete_topic(_sfusionTopic);
    }

    if(_ctrlTopic != nullptr) {
        _participant->delete_topic(_ctrlTopic);
    }

    if(_mainoutTopic != nullptr) {
        _participant->delete_topic(_mainoutTopic);
    }

    if(_sub != nullptr) {
        _participant->delete_subscriber(_sub);
    }

    DomainParticipantFactory::get_instance()->delete_participant(_participant);
}


bool AlxSys_downlink::init() {
    
    DomainParticipantQos qos;
    qos.name("DOWNLINK_SUB");
    _participant = DomainParticipantFactory::get_instance()->create_participant(0,qos);

    if(_participant == nullptr) {
        return false;
    }

    std::cout << "REGISTER AIR" << std::endl;
    _airType.register_type(_participant);
    _airTopic = _participant->create_topic("TOPIC_AIR","topic_air",TOPIC_QOS_DEFAULT);
    if(_airTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER AHRS" << std::endl;
    _ahrsType.register_type(_participant);
    _ahrsTopic = _participant->create_topic("TOPIC_AHRS","topic_ahrs",TOPIC_QOS_DEFAULT);
    if(_ahrsTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER GPS" << std::endl;
    _gpsType.register_type(_participant);
    _gpsTopic = _participant->create_topic("TOPIC_GPS","topic_gps",TOPIC_QOS_DEFAULT);
    if(_gpsTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER mainIN" << std::endl;
    _maininType.register_type(_participant);
    _maininTopic = _participant->create_topic("TOPIC_MAININ","topic_mainin",TOPIC_QOS_DEFAULT);
    if(_maininTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER SFUSION" << std::endl;
    _sfusionType.register_type(_participant);
    _sfusionTopic = _participant->create_topic("TOPIC_SFUSION","topic_sfusion",TOPIC_QOS_DEFAULT);
    if(_sfusionTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER CTRL" << std::endl;
    _ctrlType.register_type(_participant);
    _ctrlTopic = _participant->create_topic("TOPIC_CTRL","topic_ctrl",TOPIC_QOS_DEFAULT);
    if(_ctrlTopic == nullptr) {
        return false;
    }

    std::cout << "REGISTER mainOUT" << std::endl;
    _mainoutType.register_type(_participant);
    _mainoutTopic = _participant->create_topic("TOPIC_MAINOUT","topic_mainout",TOPIC_QOS_DEFAULT);
    if(_mainoutTopic == nullptr) {
        return false;
    }

    std::cout << "CREATE SUBSCRIBER" << std::endl;
    _sub = _participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
    if(_sub == nullptr) {
        return false;
    }

    std::cout << "CREATE READER" << std::endl;
    _reader = _sub->create_datareader(_airTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_ahrsTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_gpsTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_maininTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_sfusionTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_ctrlTopic, DATAREADER_QOS_DEFAULT, &_listener);
    _reader = _sub->create_datareader(_mainoutTopic, DATAREADER_QOS_DEFAULT, &_listener);
    if(_reader == nullptr) {
        return false;
    }

    std::cout << "INIT SERIAL" << std::endl;
    // SERIAL INITIALIZATION
    _listener._comSerial.init("/dev/ttyUSB0",B115200);
    std::cout << "INIT SERIAL FINISHED" << std::endl;
    return true;
}


bool AlxSys_downlink::run() {

    while(true) {
        //std::cout << "running ..." << std::endl;
        
    }
}