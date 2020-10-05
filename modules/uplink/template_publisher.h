#ifndef TEMPLATE_PUBLISHER_H
#define TEMPLATE_PUBLISHER_H

#include <fastDDS_publisher.h>


// INSERT TOPIC PUBSUBTYPE HERE


class Plistener : public DataWriterListener
{
public:

    std::atomic_int _matched;

    Plistener();
    ~Plistener() override;
    void on_publication_matched(DataWriter *, const PublicationMAtchedStatus &info) override;

};
typedef class Plistener Plistener_t;


class templatePub
{
public:
    templatePub();
    virtual ~templatePub();

    bool init();
    bool run();
    bool publish();

private:

    // BASEATTRIBUTES
    DomainParticipant   *_participant;
    Publisher           *_pub;
    Topic               *_topic;
    DataWriter          *_writer;
    TypeSupport         _type;
    Plistener_t         _plistener;

    // INSERT PUBLISHERTOPIC HERE
    // <topic_xy> ... _xyTopic;
    

};

#endif // TEMPLATE_PUBLISHER_H
