#ifndef CTRL_H
#define CTRL_H

#include <iostream>
#include <mutex>
#include <atomic>
#include <string>
#include <cstdint>
#include <thread>
#include <chrono>

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

#include "./idl/DataCtrlPubSubTypes.h"
#include "./../raiIn/idl/DataRaiInPubSubTypes.h"
#include "./../sFusion/idl/DataSFusionPubSubTypes.h"

#include "../../lib/ecf/ecf_pid/pid.h"
#include "../../lib/ecf/ecf_highpass/highpass.h"
#include "../../lib/ecf/ecf_lowpass/lowpass.h"

#include "../../util/mixer/mixer.h"
#include "../../util/timer/timer.h"

typedef enum {
	MANUAL_MODE = 0,
	STABILIZED_MODE,
	AUTOPILOT_MODE
} manual_modes_t;

typedef enum {
	FLIGHTPLAN_MODE = 0,
	MISSION_MODE,
	AI_MODE
} autonomous_mode_t;



class Listener : public eprosima::fastdds::dds::DataWriterListener, public eprosima::fastdds::dds::DataReaderListener
{
public:

	Listener();

	~Listener() override;

	void on_publication_matched(eprosima::fastdds::dds::DataWriter*,
	                            const eprosima::fastdds::dds::PublicationMatchedStatus& info) override;

	void on_subscription_matched(eprosima::fastdds::dds::DataReader*,
	                             const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

    void on_data_available(eprosima::fastdds::dds::DataReader *reader) override;

	DataRaiIn dataRaiIn;
	std::mutex dataRaiInMutex;
	std::atomic_bool newDataRaiIn;

	DataSFusion dataSFusion;
	std::mutex dataSFusionMutex;
	std::atomic_bool newDataSFusion;

private:
	std::atomic_int publication_matched;
	std::atomic_int subscription_matched;

};


class Ctrl
{

public:
	const std::string name = std::string("Ctrl");

	Ctrl();
	virtual ~Ctrl();

	bool init();
	void run();
	void publish();
	void print();

	bool update_raiIn_data();
	bool update_sfusion_data();

	double ctrl_pitch_damper(double k_eta_q);
	double ctrl_roll_damper(double k_xi_p);
	double ctrl_yaw_damper(double k_zeta_r, double tc_hp);

	double ctrl_att_pitch(double k_p, double k_i, double k_d, double dt);
	double ctrl_att_roll(double k_p, double k_i, double k_d, double dt);

	



	const unsigned long long aliveReset = 1e5;  // in us
	std::atomic_ullong aliveTime;

private:

	eprosima::fastdds::dds::DomainParticipant *participant;
	eprosima::fastdds::dds::Publisher         *publisher;
	eprosima::fastdds::dds::Subscriber        *subscriber;
	Listener     listener;

	eprosima::fastdds::dds::Topic       *topicCtrl;
	eprosima::fastdds::dds::DataWriter  *writerCtrl;
	eprosima::fastdds::dds::TypeSupport  typeCtrl;
	DataCtrl     dataCtrl;
	std::mutex   dataCtrlMutex;

	eprosima::fastdds::dds::Topic       *topicRaiIn;
	eprosima::fastdds::dds::DataReader  *readerRaiIn;
	eprosima::fastdds::dds::TypeSupport  typeRaiIn;

	eprosima::fastdds::dds::Topic       *topicSFusion;
	eprosima::fastdds::dds::DataReader  *readerSFusion;
	eprosima::fastdds::dds::TypeSupport  typeSFusion;

	Timer  timer;
	
	Pid    _pid_att_roll;
	Pid    _pid_att_pitch;
	Highpass _yaw_damper_hp;
	
	
	double _p;
	double _q;
	double _r;

	double _a_x;
	double _a_y;
	double _a_z;

	double _true_airspeed;
	double _indicated_airspeed;
	double _density;
	double _dynamic_pressure;
	double _barometric_pressure;
	
	double _height_rate;
	double _height;
	
	double _aoa;
	double _ssa;
	double _gamma;
	double _phi;
	double _the;
	double _psi;

	double _latitude;
	double _longitude;
	double _posN;
	double _posE;
	double _posD;

	double _speedN;
	double _speedE;
	double _speedD;

	double _windN;
	double _windE;
	double _windD;

	double _xi_setpoint;
	double _eta_setpoint;
	double _zeta_setpoint;
	double _throttle_setpoint;
	double _flaps_setpoint;
	double _roll_setpoint;
	double _pitch_setpoint;
	double _yaw_setpoint;
	double _hgt_setpoint;
	double _tas_setpoint;
	double _roll_rate_setpoint;
	double _pitch_rate_setpoint;
	double _yaw_rate_setpoint;
	double _hgt_rate_setpoint;
	double _tas_rate_setpoint;
	flight_mode_t _flight_mode;
	flight_fct_t _flight_fct;

	bool _publish_now{false};
	bool _raiIn_alive{false};
	bool _sfusion_alive{false};
	
	// double _turn_compensation();
	// double _turn_coordination();

};

#endif // CTRL_H
