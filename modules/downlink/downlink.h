#ifndef DOWNLINK_H
#define DOWNLINK_H

#include <iostream>
#include <atomic>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>


// == IDL DATA ================================================================
#include "./../air/idl/DataAirPubSubTypes.h"
#include "./../ahrs/idl/DataAhrsPubSubTypes.h"
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../raiOut/idl/DataRaiOutPubSubTypes.h"
#include "./../sFusion/idl/DataSFusionPubSubTypes.h"
#include "./../ctrl/idl/DataCtrlPubSubTypes.h"

// To Do
//#include "./../gps/idl/topic_gps.idl"

// == DRV SERIAL + MAVLINK ====================================================
#include "../../driver/drv_serial/drv_serial.h"
#include "mavlink/alxSys/mavlink.h"

// == UTIL ====================================================================
#include "../../util/timer/timer.h"

using namespace eprosima::fastdds::dds;


class Listener : public DataReaderListener
{
public:
    
    Listener();
    
    ~Listener() override;
    
    void on_subscription_matched(DataReader *,
                                 const SubscriptionMatchedStatus &info) override;
    
    void on_data_available(DataReader *reader) override;

    
    // DATA
    DataAir dataAir;
    std::atomic_bool newDataAir;
    
    DataAhrs    dataAhrs;
    std::atomic_bool newDataAhrs;
    
    DataRaiIn   dataRaiIn;
    std::atomic_bool newDataRaiIn;
    
    DataRaiOut  dataRaiOut;
    std::atomic_bool newDataRaiOut;
    
    DataSFusion dataSFusion;
    std::atomic_bool newDataSFusion;
    
    DataCtrl    dataCtrl;
    std::atomic_bool newDataCtrl;

    
private:
    std::atomic_int subscription_matched;
};


class Downlink
{
public:
    const std::string name = std::string("Downlink");
    const uint8_t sysid  = 0;
    const uint8_t compid = 0;
    Downlink();
    virtual ~Downlink();
    
    bool init();
    bool run();
    bool print();
    

private:
    // BASEATTRIBUTES
    DomainParticipant   *participant;
    Subscriber          *subscriber;
    Listener            listener;
    
    

    // AIR
    Topic               *topicAir;
    DataReader          *readerAir;
    TypeSupport         typeAir;

    // AHRS
    Topic               *topicAhrs;
    DataReader          *readerAhrs;
    TypeSupport         typeAhrs;

    // RAIIN
    Topic               *topicRaiIn;
    DataReader          *readerRaiIn;
    TypeSupport         typeRaiIn;

    // RAIOUT
    Topic               *topicRaiOut;
    DataReader          *readerRaiOut;
    TypeSupport         typeRaiOut;

    // SFUSION
    Topic               *topicSFusion;
    DataReader          *readerSFusion;
    TypeSupport         typeSFusion;

    // CTRL
    Topic               *topicCtrl;
    DataReader          *readerCtrl;
    TypeSupport         typeCtrl;

    Timer      timer;
    drv_serial serial;

    bool sendmsg_Air();
    bool sendmsg_Ahrs();
    bool sendmsg_RaiIn();
    bool sendmsg_RaiOut();
    bool sendmsg_SFusion();
    bool sendmsg_Ctrl();
    
};


#endif // DOWNLINK_SUBSCRIBER_H