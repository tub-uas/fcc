#include "raiIn.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : publication_matched(0) {
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

RaiIn::RaiIn() : participant(nullptr),
                 publisher(nullptr),
                 topicRaiIn(nullptr),
                 writerRaiIn(nullptr),
                 typeRaiIn(new DataRaiInPubSubType()) {
}

RaiIn::~RaiIn() {

	if (writerRaiIn != nullptr) {
		publisher->delete_datawriter(writerRaiIn);
	}

	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);
}


bool RaiIn::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("RaiInParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeRaiIn.register_type(participant);

	// Create the publications Topic
	topicRaiIn = participant->create_topic("DataRaiIn", "DataRaiIn", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicRaiIn == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerRaiIn = publisher->create_datawriter(topicRaiIn, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerRaiIn == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (raiCom.init() == false) {
		return false;
	}

	// == INIT MIXER ===========================================================
	mixer.init(1000,2000);


	return true;
}


void RaiIn::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
		dataRaiIn.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataRaiIn.alive(true);
		} else {
			dataRaiIn.alive(false);
			std::cerr << "RAIIN NOT ALIVE" << std::endl;
		}
		if(_publish_now) {
			writerRaiIn->write(&dataRaiIn);
			_publish_now = false;
		}
		dataRaiInLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}

}


void RaiIn::run() {

	// std::cout << this->name << " run" << std::endl;

	while (1) {

		if (raiCom.receive()) {

			std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};

			// == MIXER SETTING ================================================
			mixer.set_flight_mode(raiCom.channel[6]);
			mixer.set_flight_fct(raiCom.channel[5]);
			mixer.set_thr_setpoint(raiCom.channel[0]);
			mixer.set_ail_right_setpoint(raiCom.channel[1]);
			mixer.set_ele_setpoint(raiCom.channel[2]);
			mixer.set_rud_setpoint(raiCom.channel[3]);
			mixer.set_ail_left_setpoint(raiCom.channel[4]);




			// == PUBLISH DATA =================================================
			dataRaiIn.flight_mode(mixer.get_flight_mode());
			dataRaiIn.flight_fct(mixer.get_flight_fct());

			dataRaiIn.senseTime(raiCom.time);
			dataRaiIn.chnl(raiCom.channel);
			
			// == DIRECT CONTROL == MODE - MANUAL         | FCT - 0 ============ 
			dataRaiIn.xi_setpoint(mixer.get_ail_setpoint());
			dataRaiIn.eta_setpoint(mixer.get_ele_setpoint());
			dataRaiIn.zeta_setpoint(mixer.get_rud_setpoint());
			
			// == ATTITUDE CONTROL == MODE - MANUAL       | FCT - 1 ============
			dataRaiIn.roll_setpoint(mixer.get_roll_setpoint()); // we are assuming ail is symmetrical
			dataRaiIn.pitch_setpoint(mixer.get_pitch_setpoint());
			dataRaiIn.yaw_rate_setpoint(mixer.get_yaw_rate_setpoint());
			
			dataRaiIn.throttle_setpoint(mixer.get_thr_setpoint());

			// == AUTOPILOT CONTROL == MODE - MANUAL      | FCT - 2 ============
			dataRaiIn.hgt_setpoint(mixer.get_hgt_setpoint());
			dataRaiIn.tas_setpoint(mixer.get_spd_setpoint());
			dataRaiIn.yaw_setpoint(mixer.get_yaw_setpoint());

			// =================================================================
			// == AUTONOMOUS CONTROL == MODE - NAVIGATION | FCT - 0 ============

			// == AUTONOMOUS CONTROL == MODE - MISSION    | FCT - 1 ============

			// == AUTONOMOUS CONTROL == MODE - AI         | FCT - 2 ============

			// =================================================================
			// == EXPERIMENTAL CONTROL == MODE - EXP 1      | FCT - 0 ==========

			// == EXPERIMENTAL CONTROL == MODE - EXP 2      | FCT - 1 ==========

			// == EXPERIMENTAL CONTROL == MODE - EXP 3      | FCT - 2 ==========

			// print();
			// == UPDATE ALIVE TIMER ===========================================
			_publish_now = true;
			aliveTime = timer.getSysTime();
			dataRaiInLock.unlock();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);

	}

}

void RaiIn::print() {

	std::cout << "--- " << this->name << " " << dataRaiIn.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataRaiIn.senseTime() << std::endl;
	for (int i=0; i<CAN_META_RAI_CHNL_NUM; i++) {
		std::cout << "chnl[" << i << "]" << "   " << dataRaiIn.chnl().at(i) << std::endl;
	}
	std::cout << "roll_sp      " << dataRaiIn.roll_setpoint() << std::endl;
	std::cout << "pitch_sp     " << dataRaiIn.pitch_setpoint() << std::endl;
	std::cout << "yaw_sp       " << dataRaiIn.yaw_setpoint() << std::endl;
	std::cout << "thr_sp       " << dataRaiIn.throttle_setpoint() << std::endl;
	std::cout << "flight_mode  " << dataRaiIn.flight_mode() << std::endl;
	std::cout << "flight_fct   " << dataRaiIn.flight_fct() << std::endl;
	std::cout << "alive        " << dataRaiIn.alive() << std::endl;

}
