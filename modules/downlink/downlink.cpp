
#include "downlink.h"


Listener::Listener() : subscription_matched(0)
{

}

Listener::~Listener()
{

}

void Listener::on_subscription_matched(DataReader *,
                                       const SubscriptionMatchedStatus& info) {
    if(info.current_count_change == 1) {
        subscription_matched = info.total_count;
        std::cout << "Subscriber matched." << std::endl;
    } else if (info.current_count_change == -1) {
        subscription_matched = info.total_count;
        std::cout << "Subscriber unmatched." << std::endl;
    }
    
}

void Listener::on_data_available(DataReader* reader) {

    SampleInfo info;
    void *data = reader->type().create_data();

    const TopicDescription *descr = reader->get_topicdescription();
    std::string topicName(descr->get_name());  
    
    
    if (reader->get_topicdescription()->get_name().compare("DataAir") == 0) {
        
        newDataAir = true;
        reader->take_next_sample(&dataAir, &info);

    } else if (reader->get_topicdescription()->get_name().compare("DataAhrs") == 0) {

        newDataAhrs = true;
        reader->take_next_sample(&dataAhrs, &info);

    } else if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {

        newDataRaiIn = true;
        reader->take_next_sample(&dataRaiIn, &info);

    } else if (reader->get_topicdescription()->get_name().compare("DataRaiOut") == 0) {

        newDataRaiOut = true;
        reader->take_next_sample(&dataRaiOut, &info);

    } else if (reader->get_topicdescription()->get_name().compare("DataSFusion") == 0) {

        newDataSFusion = true;
        reader->take_next_sample(&dataSFusion, &info);

    } else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {

        newDataCtrl = true;
        reader->take_next_sample(&dataCtrl, &info);

    } else {
        reader->take_next_sample(&data, &info);
    }

}


Downlink::Downlink() :  participant(nullptr),
                        subscriber(nullptr),
                        topicAir(nullptr),
                        typeAir(new DataAirPubSubType()),
                        readerAir(nullptr),
                        topicAhrs(nullptr),
                        typeAhrs(new DataAhrsPubSubType()),
                        readerAhrs(nullptr),
                        topicRaiIn(nullptr),
                        typeRaiIn(new DataRaiInPubSubType()),
                        readerRaiIn(nullptr),
                        topicRaiOut(nullptr),
                        typeRaiOut(new DataRaiOutPubSubType()),
                        readerRaiOut(nullptr),
                        topicSFusion(nullptr),
                        typeSFusion(new DataSFusionPubSubType()),
                        readerSFusion(nullptr),
                        topicCtrl(nullptr),
                        typeCtrl(new DataCtrlPubSubType()),
                        readerCtrl(nullptr) {

}

Downlink::~Downlink()
{
    if (readerAir != nullptr) {
        subscriber->delete_datareader(readerAir);
    }
    if (topicAir != nullptr) {
        participant->delete_topic(topicAir);
    }
    

    if (readerAhrs != nullptr) {
        subscriber->delete_datareader(readerAhrs);
    }
    if (topicAhrs != nullptr) {
        participant->delete_topic(topicAhrs);
    }


    if (readerRaiIn != nullptr) {
        subscriber->delete_datareader(readerRaiIn);
    }
    if (topicRaiIn != nullptr) {
        participant->delete_topic(topicRaiIn);
    }


    if (readerRaiOut != nullptr) {
        subscriber->delete_datareader(readerRaiOut);
    }
    if (topicRaiOut != nullptr) {
        participant->delete_topic(topicRaiOut);
    }


    if (readerSFusion != nullptr) {
        subscriber->delete_datareader(readerSFusion);
    }
    if (topicSFusion != nullptr) {
        participant->delete_topic(topicSFusion);
    }



    if (readerCtrl != nullptr) {
        subscriber->delete_datareader(readerCtrl);
    }
    if (topicCtrl != nullptr) {
        participant->delete_topic(topicCtrl);
    }

    if (subscriber != nullptr) {
        participant->delete_subscriber(subscriber);
    }

    DomainParticipantFactory::get_instance()->delete_participant(participant);
}


bool Downlink::init() {
    
    std::cout << this->name << " init" << std::endl;

    std::cout << std::setprecision(4) << std::fixed;

    DomainParticipantQos participantQos;
    participantQos.name("DownlinkParticipant");
    participant = DomainParticipantFactory::get_instance()->create_participant(0,participantQos);

    if (participant == nullptr) {
        return false;
    }

    // Register the Type
    typeAir.register_type(participant);
    
    // Create the subscriptions Topic
    topicAir = participant->create_topic("DataAir","DataAir",TOPIC_QOS_DEFAULT);
    if (topicAir == nullptr) {
        return false;
    }

    // Register the Type
    typeAhrs.register_type(participant);
    
    // Create the subscriptions Topic
    topicAhrs = participant->create_topic("DataAhrs","DataAhrs",TOPIC_QOS_DEFAULT);
    if (topicAhrs == nullptr) {
        return false;
    }
    
    
    // Register the Type
    typeRaiIn.register_type(participant);
    
    // Create the subscriptions Topic
    topicRaiIn = participant->create_topic("DataRaiIn","DataRaiIn",TOPIC_QOS_DEFAULT);
    if (topicRaiIn == nullptr) {
        return false;
    }

    // Register the Type
    typeRaiOut.register_type(participant);
    
    // Create the subscriptions Topic
    topicRaiOut = participant->create_topic("DataRaiOut","DataRaiOut",TOPIC_QOS_DEFAULT);
    if (topicRaiOut == nullptr) {
        return false;
    }

    // Register the Type
    typeSFusion.register_type(participant);
    
    // Create the subscriptions Topic
    topicSFusion = participant->create_topic("DataSFusion","DataSFusion",TOPIC_QOS_DEFAULT);
    if (topicSFusion == nullptr) {
        return false;
    }

    // Register the Type
    typeCtrl.register_type(participant);
    
    // Create the subscriptions Topic
    topicCtrl = participant->create_topic("DataCtrl","DataCtrl",TOPIC_QOS_DEFAULT);
    if (topicCtrl == nullptr) {
        return false;
    }

    // Create the Subscriber
    subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
    if (subscriber == nullptr) {
        return false;
    }

    // Create the DataReader
    readerAir = subscriber->create_datareader(topicAir, DATAREADER_QOS_DEFAULT, &listener);
    if (readerAir == nullptr) {
        return false;
    }

    readerAhrs = subscriber->create_datareader(topicAhrs, DATAREADER_QOS_DEFAULT, &listener);
    if (readerAhrs == nullptr) {
        return false;
    }

    readerRaiIn = subscriber->create_datareader(topicRaiIn, DATAREADER_QOS_DEFAULT, &listener);
    if (readerRaiIn == nullptr) {
        return false;
    }

    readerRaiOut = subscriber->create_datareader(topicRaiOut, DATAREADER_QOS_DEFAULT, &listener);
    if (readerRaiOut == nullptr) {
        return false;
    }

    readerSFusion = subscriber->create_datareader(topicSFusion, DATAREADER_QOS_DEFAULT, &listener);
    if (readerSFusion == nullptr) {
        return false;
    }

    readerCtrl = subscriber->create_datareader(topicCtrl, DATAREADER_QOS_DEFAULT, &listener);
    if (readerCtrl == nullptr) {
        return false;
    }

    if (serial.init(TELEMETRY_COM_PORT,B115200) != true) {
        return false;
    }
    
    return true;
}


bool Downlink::run() {

    static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
    
    while(1) {
        std::this_thread::sleep_until(next_wakeup);
        next_wakeup += std::chrono::milliseconds(20);

        if(listener.newDataAir) {
            if(sendmsg_Air()) {
                listener.newDataAir = false;
            }
        }

        if(listener.newDataAhrs) {
            if(sendmsg_Ahrs()) {
                listener.newDataAhrs = false;
            }
        }

        if(listener.newDataRaiIn) {
            if(sendmsg_RaiIn()) {
                listener.newDataRaiIn = false;
            }
        }

        if(listener.newDataRaiOut) {
            if(sendmsg_RaiOut()) {
                listener.newDataRaiOut = false;
            }
        }

        if(listener.newDataSFusion) {
            if(sendmsg_SFusion()) {
                listener.newDataSFusion = false;
            }
        }

        if(listener.newDataCtrl) {
            if(sendmsg_Ctrl()) {
                listener.newDataCtrl = false;
            }
        }

        
    }
}


bool Downlink::sendmsg_Air() {
    
    mavlink_message_t msg;
    mavlink_dataair_t msg_air;
    uint8_t buf[200];
    uint16_t len;

    msg_air.time      = listener.dataAir.time();
    msg_air.senseTime = listener.dataAir.senseTime();
    msg_air.TAS       = listener.dataAir.velocity();
    msg_air.baro_air  = listener.dataAir.baroPress();
    msg_air.density   = listener.dataAir.density();
    msg_air.temp      = listener.dataAir.temp();
    msg_air.alive     = listener.dataAir.alive();
    mavlink_msg_dataair_encode(sysid,compid,&msg,&msg_air);
    len = mavlink_msg_to_send_buffer(buf,&msg);
    
    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}

bool Downlink::sendmsg_Ahrs() {

    mavlink_message_t msg;
    mavlink_dataahrs_t msg_ahrs;
    uint8_t buf[200];
    uint16_t len;

    msg_ahrs.time      = listener.dataAhrs.time();
    msg_ahrs.senseTime = listener.dataAhrs.senseTime();
    msg_ahrs.gX        = listener.dataAhrs.gyrX();
    msg_ahrs.gY        = listener.dataAhrs.gyrY();
    msg_ahrs.gZ        = listener.dataAhrs.gyrZ();
    msg_ahrs.aX        = listener.dataAhrs.accX();
    msg_ahrs.aY        = listener.dataAhrs.accY();
    msg_ahrs.aZ        = listener.dataAhrs.accZ();
    msg_ahrs.mX        = listener.dataAhrs.magX();
    msg_ahrs.mY        = listener.dataAhrs.magY();
    msg_ahrs.mZ        = listener.dataAhrs.magZ();
    msg_ahrs.phi       = listener.dataAhrs.phi();
    msg_ahrs.the       = listener.dataAhrs.the();
    msg_ahrs.psi       = listener.dataAhrs.psi();
    msg_ahrs.temp      = listener.dataAhrs.temp();
    msg_ahrs.baro_ahrs = listener.dataAhrs.press();
    msg_ahrs.q0        = listener.dataAhrs.p0();
    msg_ahrs.q1        = listener.dataAhrs.p1();
    msg_ahrs.q2        = listener.dataAhrs.p2();
    msg_ahrs.q3        = listener.dataAhrs.p3();
    msg_ahrs.alive     = listener.dataAhrs.alive();

    mavlink_msg_dataahrs_encode(sysid,compid,&msg,&msg_ahrs);
    len = mavlink_msg_to_send_buffer(buf,&msg);

    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}

bool Downlink::sendmsg_RaiIn() {
    mavlink_message_t msg;
    mavlink_dataraiin_t msg_raiIn;
    uint8_t buf[200];
    uint16_t len;
    
    msg_raiIn.time = listener.dataRaiIn.time();
    msg_raiIn.senseTime = listener.dataRaiIn.senseTime();
    // msg_raiIn.channels.... to do
    msg_raiIn.roll = listener.dataRaiIn.roll();
    msg_raiIn.pitch = listener.dataRaiIn.pitch();
    msg_raiIn.yaw = listener.dataRaiIn.yaw();
    msg_raiIn.fltmode = listener.dataRaiIn.fltMode();
    msg_raiIn.alive = listener.dataRaiIn.alive();

    mavlink_msg_dataraiin_encode(sysid,compid,&msg,&msg_raiIn);
    len = mavlink_msg_to_send_buffer(buf,&msg);

    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}

bool Downlink::sendmsg_RaiOut() {

    mavlink_message_t msg;
    mavlink_dataraiout_t msg_raiOut;
    uint8_t buf[200];
    uint16_t len;
    
    msg_raiOut.time = listener.dataRaiOut.time();
    // msg_raiOut.chnls ... to do
    msg_raiOut.roll = listener.dataRaiOut.roll();
    msg_raiOut.pitch = listener.dataRaiOut.pitch();
    msg_raiOut.yaw = listener.dataRaiOut.yaw();
    msg_raiOut.fltMode = listener.dataRaiOut.fltMode();
    msg_raiOut.alive = listener.dataRaiOut.alive();

    mavlink_msg_dataraiout_encode(sysid,compid,&msg,&msg_raiOut);
    len = mavlink_msg_to_send_buffer(buf,&msg);

    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}

bool Downlink::sendmsg_SFusion() {
    
    mavlink_message_t msg;
    mavlink_datasfusion_t msg_sfusion;
    uint8_t buf[200];
    uint16_t len;
 
    msg_sfusion.time = listener.dataSFusion.time();
    msg_sfusion.posN = listener.dataSFusion.posN();
    msg_sfusion.posE = listener.dataSFusion.posE();
    msg_sfusion.posD = listener.dataSFusion.posD();
    msg_sfusion.speedN = listener.dataSFusion.speedX();
    msg_sfusion.speedE = listener.dataSFusion.speedY();
    msg_sfusion.speedD = listener.dataSFusion.speedZ();
    msg_sfusion.WindN = listener.dataSFusion.windX();
    msg_sfusion.WindE = listener.dataSFusion.windY();
    msg_sfusion.WindD = listener.dataSFusion.windZ();
    msg_sfusion.phi = listener.dataSFusion.phi();
    msg_sfusion.the = listener.dataSFusion.the();
    msg_sfusion.psi = listener.dataSFusion.psi();
    msg_sfusion.baro_fused = listener.dataSFusion.press();
    msg_sfusion.temp_fused = listener.dataSFusion.temp();
    msg_sfusion.ssa = listener.dataSFusion.ssa();
    msg_sfusion.aoa = listener.dataSFusion.aoa();
    msg_sfusion.gamma = listener.dataSFusion.gamma();
    msg_sfusion.q0 = listener.dataSFusion.p0();
    msg_sfusion.q1 = listener.dataSFusion.p1();
    msg_sfusion.q2 = listener.dataSFusion.p2();
    msg_sfusion.q3 = listener.dataSFusion.p3();
    msg_sfusion.alive = listener.dataSFusion.alive();

    mavlink_msg_datasfusion_encode(sysid,compid,&msg,&msg_sfusion);
    len = mavlink_msg_to_send_buffer(buf,&msg);

    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}

bool Downlink::sendmsg_Ctrl() {

    mavlink_message_t msg;
    mavlink_datactrl_t msg_ctrl;
    uint8_t buf[200];
    uint16_t len;

    msg_ctrl.time = listener.dataCtrl.time();
    msg_ctrl.xi = listener.dataCtrl.xi();
    msg_ctrl.eta = listener.dataCtrl.eta();
    msg_ctrl.zeta = listener.dataCtrl.zeta();
    msg_ctrl.etaT = listener.dataCtrl.etaT();
    msg_ctrl.etaF = listener.dataCtrl.etaF();
    msg_ctrl.alive = listener.dataCtrl.alive();

    mavlink_msg_datactrl_encode(sysid,compid,&msg,&msg_ctrl);
    len = mavlink_msg_to_send_buffer(buf,&msg);

    if (serial.send(buf,len) != true) {
        return false;
    }

    return true;
}