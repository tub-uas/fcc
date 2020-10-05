#ifndef DOWNLINK_SUBSCRIBER_H
#define DOWNLINK_SUBSCRIBER_H

#include "../../fastDDS/fastDDS_subscriber.h"

// INSERT TOPIC PUBSUBTYPE(S) HERE
#include "downlink_subTopics.h"


// DRV SERIAL PORT
#include "../../driver/drv_serial/drv_serial.h"

// MAVLINK UTIL
//#include "mavlink/common/mavlink.h"
#include "mavlink/alxSys/mavlink.h"


class Slistener : public DataReaderListener
{
public:
    Slistener();
    ~Slistener() override;
    void on_subscription_matched(DataReader *, const SubscriptionMatchedStatus &info) override;
    void on_data_available(DataReader *reader) override;

    // INSERT TOPICS HERE TO READ FROM
    topic_air       _airData;
    topic_ahrs      _ahrsData;
    topic_gps       _gpsData;
    topic_mainin    _maininData;
    topic_sfusion   _sfusionData;
    topic_ctrl      _ctrlData;
    topic_mainout   _mainoutData;

    drv_serial      _comSerial;
};

typedef class Slistener Slistener_t;


class AlxSys_downlink
{
public:
    AlxSys_downlink();
    virtual ~AlxSys_downlink();
    bool init();
    bool run();
    // SERIAL HANDLER
private:
    // BASEATTRIBUTES
    DomainParticipant   *_participant;
    Subscriber          *_sub;
    DataReader          *_reader;

    // AIR
    Topic               *_airTopic;
    TypeSupport         _airType;

    // AHRS
    Topic               *_ahrsTopic;
    TypeSupport         _ahrsType;

    // GPS
    Topic               *_gpsTopic;
    TypeSupport         _gpsType;

    // MAININ
    Topic               *_maininTopic;
    TypeSupport         _maininType;

    // SFUSION
    Topic               *_sfusionTopic;
    TypeSupport         _sfusionType;

    // CTRL
    Topic               *_ctrlTopic;
    TypeSupport         _ctrlType;

    // MAINOUT
    Topic               *_mainoutTopic;
    TypeSupport         _mainoutType;

    // Listener
    Slistener_t         _listener;


    
};


#endif // DOWNLINK_SUBSCRIBER_H