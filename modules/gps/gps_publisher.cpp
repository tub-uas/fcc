

#include "gps_publisher.h"



// == LISTENER CLASS ==========================================================
Plistener::Plistener() : _matched(0) {

}

Plistener::~Plistener() {

}

void Plistener::on_publication_matched(DataWriter *, const PublicationMatchedStatus& info) {

    // INSERT INFO HERE
}


// == AHRS CLASS ==============================================================
AlxSys_gps::AlxSys_gps() : _participant(nullptr)
                            ,_gpsPub(nullptr)
                            ,_gpsTopic(nullptr)
                            ,_gpsWriter(nullptr)
                            ,_gpsType(new topic_gpsPubSubType()) {

}


AlxSys_gps::~AlxSys_gps() {
    
    if(_gpsWriter != nullptr) {
        _gpsPub->delete_datawriter(_gpsWriter);
    }
    if(_gpsPub != nullptr) {
        _participant->delete_publisher(_gpsPub);
    }
    if(_gpsTopic != nullptr) {
        _participant->delete_topic(_gpsTopic);
    }

    DomainParticipantFactory::get_instance()->delete_participant(_participant);
}


bool AlxSys_gps::init() {

    DomainParticipantQos pQos;
    pQos.name("GPS_Participant");
    _participant = DomainParticipantFactory::get_instance()->create_participant(0,pQos);
    if(_participant == nullptr) {
        return false;
    }

    // == TYPE REGISTRATION ===================================================
    _gpsType.register_type(_participant);
    _gpsTopic = _participant->create_topic("TOPIC_GPS","topic_gps",TOPIC_QOS_DEFAULT);
    if(_gpsTopic == nullptr) {
        return false;
    }

    // == PUBLISHER CREATION ==================================================
    _gpsPub = _participant->create_publisher(PUBLISHER_QOS_DEFAULT,nullptr);
    if(_gpsPub == nullptr) {
        return false;
    }

    // == WRITER CREATION =====================================================
    _gpsWriter = _gpsPub->create_datawriter(_gpsTopic,DATAWRITER_QOS_DEFAULT,&_plistener);
    if(_gpsWriter == nullptr) {
        return false;
    }

    // ToDo: INSERT AHRS INIT HERE
}


bool AlxSys_gps::run() {
    
    while(true) {
        
    }
}

bool AlxSys_gps::publish() {
    
    return true;
}



