#include "ctrl.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <cmath>

Listener::Listener() : publication_matched(0),
                       subscription_matched(0) {
}

Listener::~Listener() {
}

void Listener::on_publication_matched(eprosima::fastdds::dds::DataWriter*,
                                      const eprosima::fastdds::dds::PublicationMatchedStatus& info) {

	if (info.current_count_change == 1) {
		publication_matched = info.total_count;
		std::cout << "Publisher matched." << std::endl;
	} else if (info.current_count_change == -1) {
		publication_matched = info.total_count;
		std::cout << "Publisher unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
	}
}

void Listener::on_subscription_matched(eprosima::fastdds::dds::DataReader*,
                                       const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) {

	if (info.current_count_change == 1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber matched." << std::endl;
	} else if (info.current_count_change == -1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
	}
}

void Listener::on_data_available(eprosima::fastdds::dds::DataReader* reader) {

	eprosima::fastdds::dds::SampleInfo info;
	std::string topic = reader->get_topicdescription()->get_name();
	
	if(topic.compare("DataRaiIn") == 0) 
	{
		std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
		if(reader->take_next_sample(&dataRaiIn,&info) == ReturnCode_t::RETCODE_OK)
		{
			if (info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				newDataRaiIn = true;
			}
		}
		dataRaiInLock.unlock();
	}
	else if(topic.compare("DataSFusion") == 0) 
	{
		std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
		if(reader->take_next_sample(&dataSFusion,&info) == ReturnCode_t::RETCODE_OK)
		{
			if (info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				newDataSFusion = true;
			}
		}
		dataSFusionLock.unlock();
	}
	else
	{
		// DO NOTHING
	}
	// TODO why does this cause a segfault ?!?
	// reader->type().delete_data(data);
}

Ctrl::Ctrl() : participant(nullptr),
               publisher(nullptr),
               subscriber(nullptr),
               topicCtrl(nullptr),
               writerCtrl(nullptr),
               typeCtrl(new DataCtrlPubSubType()),
               topicRaiIn(nullptr),
               readerRaiIn(nullptr),
               typeRaiIn(new DataRaiInPubSubType()),
               topicSFusion(nullptr),
               readerSFusion(nullptr),
               typeSFusion(new DataSFusionPubSubType()) {

}

Ctrl::~Ctrl() {

	if (writerCtrl != nullptr) {
		publisher->delete_datawriter(writerCtrl);
	}

	if (topicCtrl != nullptr) {
		participant->delete_topic(topicCtrl);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	if (readerRaiIn != nullptr) {
		subscriber->delete_datareader(readerRaiIn);
	}

	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
	}

	if (readerSFusion != nullptr) {
		subscriber->delete_datareader(readerSFusion);
	}

	if (topicSFusion != nullptr) {
		participant->delete_topic(topicSFusion);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}

bool Ctrl::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("CtrlParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeCtrl.register_type(participant);

	// Create the publications Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerCtrl = publisher->create_datawriter(topicCtrl, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerCtrl == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiIn.register_type(participant);

	// Create the subscriptions Topic
	topicRaiIn = participant->create_topic("DataRaiIn", "DataRaiIn", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicRaiIn == nullptr) {
		return false;
	}

	// Register the Type
	typeSFusion.register_type(participant);

	// Create the subscriptions Topic
	topicSFusion = participant->create_topic("DataSFusion", "DataSFusion", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicSFusion == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	readerRaiIn = subscriber->create_datareader(topicRaiIn, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerRaiIn == nullptr) {
		return false;
	}

	// Create the DataReader
	readerSFusion = subscriber->create_datareader(topicSFusion, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerSFusion == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	

	return true;
}

void Ctrl::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
		dataCtrl.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataCtrl.alive(true);
		} else {
			dataCtrl.alive(false);
			std::cerr << "CTRL NOT ALIVE" << std::endl;
		}
		if(_publish_now) {
			writerCtrl->write(&dataCtrl);
			_publish_now = false;
		}
		dataCtrlLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}
}

void Ctrl::run() {

	static double last_time = timer.getSysTimeS();

	while (1) {

		// == RUN CONTROLLER IF NEW DATA AVAILABLE
		if (update_raiIn_data()) {

			
			std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};


			double dt = timer.getSysTimeS()-last_time;
			last_time = timer.getSysTimeS();
			dataCtrl.flight_fct(_flight_fct);
			dataCtrl.flight_mode(_flight_mode);

			if(_flight_mode == MANUAL || _flight_mode == AUTONOMOUS) 
			{
				if(_flight_mode == AUTONOMOUS)
				{
					_flight_fct = FCT_2;
				}
				switch(_flight_fct) {
					// == AUTOPILOT ============================================
					case FCT_2:

						// == NO BREAK ==

					// == STABILIZED ===========================================
					case FCT_1:
						if(update_sfusion_data()) {
							// ONLY ATTITUDE SETPOINTS FOR ROLL AND PITCH
							dataCtrl.roll_setpoint(_roll_setpoint);
							dataCtrl.pitch_setpoint(_pitch_setpoint);
							// _xi_setpoint = ctrl_att_roll(0.3,0.0,0.0,dt);
							// _eta_setpoint = ctrl_att_pitch(0.3,0.0,0.0,dt);

							// DAMPER SETPOINT 
							_xi_setpoint = ctrl_roll_damper(-0.05);
							_eta_setpoint = ctrl_pitch_damper(-0.05);
							_zeta_setpoint = ctrl_yaw_damper(-0.05,3.183e-02);
							dataCtrl.xi_setpoint(_xi_setpoint);
							dataCtrl.eta_setpoint(_eta_setpoint);
							
						}
						break;

					// == MANUAL ===============================================
					case FCT_0:

						dataCtrl.xi_setpoint(_xi_setpoint);
						dataCtrl.eta_setpoint(_eta_setpoint);
						dataCtrl.zeta_setpoint(_zeta_setpoint);
						dataCtrl.throttle_setpoint(_throttle_setpoint);
						break;
					default:
						
						break;

				}
			}
			else if(_flight_mode == EXPERIMENTAL)
			{

			}
			else {
				std::cout << "no valid flight mode!" << std::endl;
			}
			aliveTime = timer.getSysTime();
			_publish_now = true;
			dataCtrlLock.unlock();

			
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

void Ctrl::print() {

	std::cout << "--- " << this->name << " " << dataCtrl.time() << " ---" << std::endl;

	std::cout << "aileron_sp      " << dataCtrl.xi_setpoint() << std::endl;
	std::cout << "elevator_sp     " << dataCtrl.eta_setpoint() << std::endl;
	std::cout << "rudder_sp       " << dataCtrl.zeta_setpoint() << std::endl;
	std::cout << "throttle_sp     " << dataCtrl.throttle_setpoint() << std::endl;
	std::cout << "flaps_sp        " << dataCtrl.flaps_setpoint() << std::endl;
	std::cout << "roll_sp         " << dataCtrl.roll_setpoint() << std::endl;
	std::cout << "pitch_sp        " << dataCtrl.pitch_setpoint() << std::endl;
	std::cout << "yaw_sp          " << dataCtrl.yaw_setpoint() << std::endl;
	std::cout << "tas_sp          " << dataCtrl.tas_setpoint() << std::endl;
	std::cout << "height_sp       " << dataCtrl.hgt_setpoint() << std::endl;
	std::cout << "roll_rate_sp    " << dataCtrl.roll_rate_setpoint() << std::endl;
	std::cout << "pitch_rate_sp   " << dataCtrl.pitch_rate_setpoint() << std::endl;
	std::cout << "yaw_rate_sp     " << dataCtrl.yaw_rate_setpoint() << std::endl;
	std::cout << "tas_rate_sp     " << dataCtrl.tas_rate_setpoint() << std::endl;
	std::cout << "height_rate_sp  " << dataCtrl.hgt_rate_setpoint() << std::endl;
	std::cout << "fligt_mode      " << dataCtrl.flight_mode() << std::endl;
	std::cout << "fligt_fct       " << dataCtrl.flight_fct() << std::endl;
	std::cout << "alive           " << dataCtrl.alive() << std::endl;
}


bool Ctrl::update_raiIn_data()
{
	if(listener.newDataRaiIn) 
	{
		std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
		_xi_setpoint = listener.dataRaiIn.xi_setpoint();
		_eta_setpoint = listener.dataRaiIn.eta_setpoint();
		_zeta_setpoint = listener.dataRaiIn.zeta_setpoint();
		_throttle_setpoint = listener.dataRaiIn.throttle_setpoint();
		_flaps_setpoint = listener.dataRaiIn.flaps_setpoint();
		_roll_setpoint = listener.dataRaiIn.roll_setpoint();
		_pitch_setpoint = listener.dataRaiIn.pitch_setpoint();
		_yaw_setpoint = listener.dataRaiIn.yaw_setpoint();
		_hgt_setpoint = listener.dataRaiIn.hgt_setpoint();
		_tas_setpoint = listener.dataRaiIn.tas_setpoint();
		_roll_rate_setpoint = listener.dataRaiIn.roll_rate_setpoint();
		_pitch_rate_setpoint = listener.dataRaiIn.pitch_rate_setpoint();
		_yaw_rate_setpoint = listener.dataRaiIn.yaw_rate_setpoint();
		_hgt_rate_setpoint = listener.dataRaiIn.hgt_rate_setpoint();
		_tas_rate_setpoint = listener.dataRaiIn.tas_rate_setpoint();

		_flight_mode = (flight_mode_t)listener.dataRaiIn.flight_mode();
		_flight_fct = (flight_fct_t)listener.dataRaiIn.flight_fct();
		
		_raiIn_alive = listener.dataRaiIn.alive();
		listener.newDataRaiIn = false;
		dataRaiInLock.unlock();
		

		return true;
	}
	
	return false;
}

bool Ctrl::update_sfusion_data()
{
	if(listener.newDataSFusion)
	{
		std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
		_p = listener.dataSFusion.p();
		_q = listener.dataSFusion.q();
		_r = listener.dataSFusion.r();
		_a_x = listener.dataSFusion.a_x();
		_a_y = listener.dataSFusion.a_y();
		_a_z = listener.dataSFusion.a_z();
		_true_airspeed = listener.dataSFusion.true_airspeed();
		_indicated_airspeed = listener.dataSFusion.indicated_airspeed();
		_density = listener.dataSFusion.density();
		_dynamic_pressure = listener.dataSFusion.dynamic_pressure();
		_barometric_pressure = listener.dataSFusion.barometric_pressure();
		_height_rate = listener.dataSFusion.height_rate();
		_height = listener.dataSFusion.height();
		_aoa = listener.dataSFusion.aoa();
		_ssa = listener.dataSFusion.ssa();
		_gamma = listener.dataSFusion.gamma();
		_phi = listener.dataSFusion.phi();
		_the = listener.dataSFusion.the();
		_psi = listener.dataSFusion.psi();
		_latitude = listener.dataSFusion.latitude();
		_longitude = listener.dataSFusion.longitude();
		_posN = listener.dataSFusion.posN();
		_posE = listener.dataSFusion.posE();
		_posD = listener.dataSFusion.posD();
		_speedN = listener.dataSFusion.speedN();
		_speedE = listener.dataSFusion.speedE();
		_speedD = listener.dataSFusion.speedD();
		_windN = listener.dataSFusion.windN();
		_windE = listener.dataSFusion.windE();
		_windD = listener.dataSFusion.windD();

		_sfusion_alive = listener.dataSFusion.alive();
		listener.newDataSFusion = false;
		dataSFusionLock.unlock();
		return true;
	}
	return false;
}


double Ctrl::ctrl_pitch_damper(double k_eta_q)
{
	return _eta_setpoint-k_eta_q*_q;
}

double Ctrl::ctrl_roll_damper(double k_xi_p)
{
	return _xi_setpoint-k_xi_p*_p;
}

double Ctrl::ctrl_yaw_damper(double k_zeta_r, double tc_hp)
{
	if(_yaw_damper_hp.get_init_state() == false) {
		_yaw_damper_hp.init(tc_hp,0.01);
	}
	return _zeta_setpoint-k_zeta_r*_yaw_damper_hp.update(_r);
}

double Ctrl::ctrl_att_pitch(double k_p, double k_i, double k_d, double dt)
{
	if(_pid_att_pitch.get_init_state() == false) {
		_pid_att_pitch.init(k_p,k_i,k_d,M_PI/180.0*30,-M_PI/180.0*30);
	}
	return _pid_att_pitch.update(_pitch_setpoint,_the,dt);
}

double Ctrl::ctrl_att_roll(double k_p, double k_i, double k_d, double dt)
{
	if(_pid_att_roll.get_init_state() == false) {
		_pid_att_roll.init(k_p,k_i,k_d,M_PI/180.0*30,-M_PI/180.0*30);
	}
	return _pid_att_pitch.update(_roll_setpoint,_phi,dt);
}