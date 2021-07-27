#include "raiOut.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

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

	if(topic.compare("DataCtrl") == 0)
	{

		std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
		if(reader->take_next_sample(&dataCtrl,&info) == ReturnCode_t::RETCODE_OK)
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data)
			{
				newDataCtrl = true;
			}
		}
		dataCtrlLock.unlock();		
	}
	else
	{
		// DO NOTHING
	}

	// TODO why does this cause a segfault ?!?
	// reader->type().delete_data(data);
}

RaiOut::RaiOut() : participant(nullptr),
                   publisher(nullptr),
                   subscriber(nullptr),
                   topicRaiOut(nullptr),
                   writerRaiOut(nullptr),
                   typeRaiOut(new DataRaiOutPubSubType()),
                   topicCtrl(nullptr),
                   readerCtrl(nullptr),
                   typeCtrl(new DataCtrlPubSubType()) {

}

RaiOut::~RaiOut() {

	if (writerRaiOut != nullptr) {
		publisher->delete_datawriter(writerRaiOut);
	}

	if (topicRaiOut != nullptr) {
		participant->delete_topic(topicRaiOut);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
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

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool RaiOut::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("RaiOutParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiOut.register_type(participant);

	// Create the publications Topic
	topicRaiOut = participant->create_topic("DataRaiOut", "DataRaiOut", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicRaiOut == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerRaiOut = publisher->create_datawriter(topicRaiOut, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerRaiOut == nullptr) {
		return false;
	}

	// Register the Type
	typeCtrl.register_type(participant);

	// Create the subscriptions Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	readerCtrl = subscriber->create_datareader(topicCtrl, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerCtrl == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (raiCom.init() == false) {
		return false;
	}
	mixer.init(1000,2000);
	return true;
}


void RaiOut::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};
		dataRaiOut.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataRaiOut.alive(true);
			 // Send the commands to RAI over CAN
			
		} else {
			dataRaiOut.alive(false);
			std::cout << "timeout..." << std::endl;
		}

		if(_publish_now) {
			writerRaiOut->write(&dataRaiOut);
			raiCom.send();
			_publish_now = false;
		}
		dataRaiOutLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}
	
}


void RaiOut::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if(update_ctrl_data()) {
			std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};

			dataRaiOut.chnl(raiCom.channel);
			dataRaiOut.xi_setpoint(_xi);
			dataRaiOut.eta_setpoint(_eta);
			dataRaiOut.zeta_setpoint(_zeta);
			dataRaiOut.throttle_setpoint(_throttle);
			dataRaiOut.flaps_setpoint(_flaps);
			dataRaiOut.flight_mode((uint16_t)_flight_mode);
			dataRaiOut.flight_fct((uint16_t)_flight_fct);

			raiCom.time = timer.getSysTimeS();
			raiCom.channel[0] = 1000; //
			raiCom.channel[1] = mixer.get_ail_right_pwm_setpoint(dataRaiOut.xi_setpoint()/mixer.get_ail_max());
			raiCom.channel[2] = mixer.get_ele_pwm_setpoint(dataRaiOut.eta_setpoint()/mixer.get_ele_max());
			raiCom.channel[3] = mixer.get_rud_pwm_setpoint(dataRaiOut.zeta_setpoint()/mixer.get_rud_max());
			raiCom.channel[4] = mixer.get_ail_left_pwm_setpoint(dataRaiOut.xi_setpoint()/mixer.get_ail_max());
			raiCom.channel[5] = mixer.get_flight_fct_pwm((flight_fct_t)dataRaiOut.flight_fct());
			raiCom.channel[6] = mixer.get_flight_mode_pwm((flight_mode_t)dataRaiOut.flight_mode());
			raiCom.channel[7] = 1500;
			raiCom.channel[8] = 1500;
			raiCom.channel[9] = 1500;
			raiCom.channel[10] = 1500;
			raiCom.channel[11] = 1500;

			// reset the alive timer
			aliveTime = timer.getSysTime();

			_publish_now = true;
			dataRaiOutLock.unlock();

		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}

}


bool RaiOut::update_ctrl_data()
{
	if(listener.newDataCtrl)
	{
		std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
		_xi = listener.dataCtrl.xi_setpoint();
		_eta = listener.dataCtrl.eta_setpoint();
		_zeta = listener.dataCtrl.zeta_setpoint();
		_throttle = listener.dataCtrl.throttle_setpoint();
		_flaps = listener.dataCtrl.flaps_setpoint();
		_roll = listener.dataCtrl.roll_setpoint();
		_pitch = listener.dataCtrl.pitch_setpoint();
		_yaw = listener.dataCtrl.yaw_setpoint();
		_hgt = listener.dataCtrl.hgt_setpoint();
		_tas = listener.dataCtrl.tas_setpoint();
		_roll_rate = listener.dataCtrl.roll_rate_setpoint();
		_pitch_rate = listener.dataCtrl.pitch_rate_setpoint();
		_yaw_rate = listener.dataCtrl.yaw_rate_setpoint();
		_hgt_rate = listener.dataCtrl.hgt_rate_setpoint();
		_tas_rate = listener.dataCtrl.tas_rate_setpoint();

		_flight_mode = (flight_mode_t)listener.dataCtrl.flight_mode();
		_flight_fct = (flight_fct_t)listener.dataCtrl.flight_fct();

		_ctrl_alive = listener.dataCtrl.alive();

		listener.newDataCtrl = false;
		return true;
	}
	return false;
}

void RaiOut::print() {

	std::cout << "--- " << this->name << " " << dataRaiOut.time() << " ---" << std::endl;

	for (int i=0; i<CAN_META_RAI_CHNL_NUM; i++) {
		std::cout << "chnl[" << i << "]" << " " << dataRaiOut.chnl().at(i) << std::endl;
	}

	std::cout << "xi_sp       " << dataRaiOut.xi_setpoint() << std::endl;
	std::cout << "eta_sp      " << dataRaiOut.eta_setpoint() << std::endl;
	std::cout << "zeta_sp     " << dataRaiOut.zeta_setpoint() << std::endl;
	std::cout << "throttle_sp " << dataRaiOut.throttle_setpoint() << std::endl;
	std::cout << "flaps_sp    " << dataRaiOut.flaps_setpoint() << std::endl;
	std::cout << "flight_mode " << dataRaiOut.flight_mode() << std::endl;
	std::cout << "flight_fct  " << dataRaiOut.flight_fct() << std::endl;
	std::cout << "alive       " << dataRaiOut.alive() << std::endl;

}
