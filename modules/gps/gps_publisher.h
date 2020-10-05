#ifndef GPS_PUBLISHER_H
#define GPS_PUBLISHER_H

#include "../../fastDDS/fastDDS_publisher.h"

// GPS TOPIC
#include "./idl/topic_gpsPubSubTypes.h"


class Plistener : public DataWriterListener
{
public:

    std::atomic_int _matched;

    Plistener();
    ~Plistener() override;
    void on_publication_matched(DataWriter *, const PublicationMatchedStatus &info) override;

};
typedef class Plistener Plistener_t;


class AlxSys_gps
{
public:
    AlxSys_gps();
    virtual ~AlxSys_gps();

    bool init();
    bool run();
    bool publish();

private:

    // BASEATTRIBUTES
    DomainParticipant   *_participant;
    Publisher           *_gpsPub;
    Topic               *_gpsTopic;
    DataWriter          *_gpsWriter;
    TypeSupport         _gpsType;
    Plistener_t         _plistener;
    
    // INSERT PUBLISHERTOPIC HERE
    topic_gps          _gpsData;

    // CAN ATTRIBUTES

    // PRIVATE METHODS
    bool initCan();
    
};

#endif // GPS_PUBLISHER_H
