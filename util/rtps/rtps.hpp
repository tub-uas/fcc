#ifndef RTPS_H
#define RTPS_H

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <mutex>

#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>


template<class T>
class RtpsWriter
{

public:
    eprosima::fastdds::dds::Topic *topic;
    eprosima::fastdds::dds::DataWriter *writer;
    eprosima::fastdds::dds::TypeSupport type;
    T data;

private:
};

template<class T> 
class RtpsReader
{
public:
    eprosima::fastdds::dds::Topic *topic;
    eprosima::fastdds::dds::DataReader *writer;
    eprosima::fastdds::dds::TypeSupport *type;
    T data;
private:

};


template<class T>
class RtpsListener : public eprosima::fastdds::dds::DataWriterListener, 
                     public eprosima::fastdds::dds::DataReaderListener
{
public:
    RtpsListener();
    ~RtpsListener() override;

    void on_publication_matched(eprosima::fastdds::dds::DataWriter *,
                                const eprosima::fastdds::dds::PublicationMatchedStatus& info) override;
    void on_subscription_matched(eprosima::fastdds::dds::DataReader *,
                                 const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;
    void on_data_available(eprosima::fastdds::dds::DataReader *reader) override;

    T data;
    std::mutex mutex;
    std::atomic_bool new_data_available;
private:
    std::atomic_int _pub_match;
    std::atomic_int sub_match;

};



#endif // RTPS_H