#include "ahrs.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/Domain.h>

Listener::Listener() : publication_matched(0) {
}

Listener::~Listener() {
}

void Listener::onPublicationMatched(eprosima::fastrtps::Publisher *pub,
                                      const eprosima::fastrtps::rtps::MatchingInfo& info) {

	eprosima::fastrtps::Publisher *test = pub;
	test = test;
	eprosima::fastrtps::rtps::MatchingInfo bla = info;
	/*if (info.status == 1) {
		publication_matched = info.total_count;
		std::cout << "Publisher matched." << std::endl;
	} else if (info.current_count_change == -1) {
		publication_matched = info.total_count;
		std::cout << "Publisher unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for PublicationMatchedStatus current count change." << std::endl;
	}*/
}

Ahrs::Ahrs() : participant(nullptr),
               publisher(nullptr) 
{
}

Ahrs::~Ahrs() {

	eprosima::fastrtps::Domain::removeParticipant(participant);

}


bool Ahrs::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastrtps::ParticipantAttributes PParam;
	PParam.rtps.builtin.discovery_config.discoveryProtocol = eprosima::fastrtps::rtps::DiscoveryProtocol_t::SIMPLE;
	PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
	PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
	PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
	PParam.rtps.builtin.discovery_config.leaseDuration = eprosima::fastrtps::c_TimeInfinite;
	PParam.rtps.setName("AhrsPublisher");
	// Register the Type
	participant = eprosima::fastrtps::Domain::createParticipant(PParam);

	if(participant == nullptr) {
		return false;
	}

	eprosima::fastrtps::Domain::registerType(participant, &typeAhrs);
	eprosima::fastrtps::PublisherAttributes Wparam;
	Wparam.topic.topicDataType = "DataAhrs";
	Wparam.topic.topicName = "DataAhrs";
	publisher = eprosima::fastrtps::Domain::createPublisher(participant, Wparam, (eprosima::fastrtps::PublisherListener *)&listener);
	if(publisher == nullptr) {
		return false;
	}
	return true;

}


void Ahrs::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
		dataAhrs.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataAhrs.alive(true);
		} else {
			dataAhrs.alive(false);
		}

		publisher->write((void *)&dataAhrs);
		dataAhrsLock.unlock();

		print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void Ahrs::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (1) { //ahrsCom.receive()) {

			std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};

			dataAhrs.senseTime(aliveTime);
			dataAhrs.gyrX(25); //ahrsCom.gyr[0]);
			dataAhrs.gyrY(ahrsCom.gyr[1]);
			dataAhrs.gyrZ(ahrsCom.gyr[2]);
			dataAhrs.accX(ahrsCom.acc[0]);
			dataAhrs.accY(ahrsCom.acc[1]);
			dataAhrs.accZ(ahrsCom.acc[2]);
			dataAhrs.magX(ahrsCom.mag[0]);
			dataAhrs.magY(ahrsCom.mag[1]);
			dataAhrs.magZ(ahrsCom.mag[2]);
			dataAhrs.temp(ahrsCom.temp);
			dataAhrs.press(ahrsCom.press);
			dataAhrs.phi(ahrsCom.att[0]);
			dataAhrs.the(ahrsCom.att[1]);
			dataAhrs.psi(ahrsCom.att[2]);
			dataAhrs.q0(-1.0);
			dataAhrs.q1(-2.0);
			dataAhrs.q2(-3.0);
			dataAhrs.q3(-4.0);

			// reset the alive timer
			aliveTime = timer.getSysTime();

			dataAhrsLock.unlock();

			print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

void Ahrs::print() {

	std::cout << "--- " << this->name << " " << dataAhrs.time() << " ---" << std::endl;

	std::cout << "senseTime " << dataAhrs.senseTime() << std::endl;
	std::cout << "gyrX      " << dataAhrs.gyrX() << std::endl;
	std::cout << "gyrY      " << dataAhrs.gyrY() << std::endl;
	std::cout << "gyrZ      " << dataAhrs.gyrZ() << std::endl;
	std::cout << "accX      " << dataAhrs.accX() << std::endl;
	std::cout << "accY      " << dataAhrs.accY() << std::endl;
	std::cout << "accZ      " << dataAhrs.accZ() << std::endl;
	std::cout << "magX      " << dataAhrs.magX() << std::endl;
	std::cout << "magY      " << dataAhrs.magY() << std::endl;
	std::cout << "magZ      " << dataAhrs.magZ() << std::endl;
	std::cout << "temp      " << dataAhrs.temp() << std::endl;
	std::cout << "press     " << dataAhrs.press() << std::endl;
	std::cout << "phi       " << dataAhrs.phi() << std::endl;
	std::cout << "the       " << dataAhrs.the() << std::endl;
	std::cout << "psi       " << dataAhrs.psi() << std::endl;
	std::cout << "q0        " << dataAhrs.q0() << std::endl;
	std::cout << "q1        " << dataAhrs.q1() << std::endl;
	std::cout << "q2        " << dataAhrs.q2() << std::endl;
	std::cout << "q3        " << dataAhrs.q3() << std::endl;
	std::cout << "alive     " << dataAhrs.alive() << std::endl;

}
