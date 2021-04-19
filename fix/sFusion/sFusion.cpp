#include "sFusion.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

#include <fastrtps/participant/Participant.h>
#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/Domain.h>

Listener::Listener() : publication_matched(0),
                       subscription_matched(0) {
}

Listener::~Listener() {
}


void Listener::onSubscriptionMatched(eprosima::fastrtps::Subscriber *sub,
                                       const eprosima::fastrtps::rtps::MatchingInfo& info) {

	eprosima::fastrtps::Subscriber *nsub =sub;
	nsub = nsub;
	eprosima::fastrtps::rtps::MatchingInfo bla = info;
	/*if (info.current_count_change == 1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber matched." << std::endl;
	} else if (info.current_count_change == -1) {
		subscription_matched = info.total_count;
		std::cout << "Subscriber unmatched." << std::endl;
	} else {
		std::cout << info.current_count_change
		          << " is not a valid value for SubscriptionMatchedStatus current count change" << std::endl;
	}*/
}

void Listener::onNewDataMessage(eprosima::fastrtps::Subscriber *sub) {

	eprosima::fastrtps::SampleInfo_t info;
	if(sub->takeNextData((void *)&dataAhrs,&info)) {
		std::cout << dataAhrs.gyrX() << std::endl;
		std::cout << dataAhrs.senseTime() << std::endl;
	}


	// TODO why does this cause a segfault ?!?
	// reader->type().delete_data(data);
}

SFusion::SFusion() : participant(nullptr),
                     subscriber(nullptr)
{
}

SFusion::~SFusion() {

	eprosima::fastrtps::Domain::removeParticipant(participant);
}


bool SFusion::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastrtps::ParticipantAttributes PParam;
	PParam.rtps.builtin.discovery_config.discoveryProtocol = eprosima::fastrtps::rtps::DiscoveryProtocol_t::SIMPLE;
	PParam.rtps.builtin.discovery_config.use_SIMPLE_EndpointDiscoveryProtocol = true;
	PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationReaderANDSubscriptionWriter = true;
	PParam.rtps.builtin.discovery_config.m_simpleEDP.use_PublicationWriterANDSubscriptionReader = true;
	PParam.rtps.builtin.discovery_config.leaseDuration = eprosima::fastrtps::c_TimeInfinite;
	PParam.rtps.setName("AhrsSubscriber");

	participant = eprosima::fastrtps::Domain::createParticipant(PParam);
	if(participant == nullptr) {
		return false;
	}

	eprosima::fastrtps::Domain::registerType(participant, &typeAhrs);

	eprosima::fastrtps::SubscriberAttributes Rparam;
	Rparam.topic.topicDataType = "DataAhrs";
	Rparam.topic.topicName = "DataAhrs";
	subscriber = eprosima::fastrtps::Domain::createSubscriber(participant,Rparam, (eprosima::fastrtps::SubscriberListener *)&listener);

	if(subscriber == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	return true;
}

/*
void SFusion::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
		dataSFusion.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataSFusion.alive(true);
		} else {
			dataSFusion.alive(false);
		}

		writerSFusion->write(&dataSFusion);
		dataSFusionLock.unlock();

		//print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}
*/

void SFusion::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;
		//std::cout << listener.newDataAhrs << "..." << listener.newDataAir << std::endl;
		
		if (1) {//listener.newDataAhrs) {

			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
			
			// todo: as soon as we are actually using air, remove comment
			if (listener.dataAhrs.alive() /* && listener.dataAir.alive()*/) {
				/*
				dataSFusion.gyrX(listener.dataAhrs.gyrX());
				dataSFusion.gyrY(listener.dataAhrs.gyrY());
				dataSFusion.gyrZ(listener.dataAhrs.gyrZ());
				dataSFusion.accX(listener.dataAhrs.accX());
				dataSFusion.accY(listener.dataAhrs.accY());
				dataSFusion.accZ(listener.dataAhrs.accZ());
				dataSFusion.magX(listener.dataAhrs.magX());
				dataSFusion.magY(listener.dataAhrs.magY());
				dataSFusion.magZ(listener.dataAhrs.magZ());
				dataSFusion.temp(listener.dataAhrs.temp());
				dataSFusion.press(listener.dataAhrs.press());
				dataSFusion.phi(listener.dataAhrs.phi());
				dataSFusion.the(listener.dataAhrs.the());
				dataSFusion.psi(listener.dataAhrs.psi());
				dataSFusion.q0(listener.dataAhrs.q0());
				dataSFusion.q1(listener.dataAhrs.q1());
				dataSFusion.q2(listener.dataAhrs.q2());
				dataSFusion.q3(listener.dataAhrs.q3());

				dataSFusion.posN(-1.0);
				dataSFusion.posE(-1.0);
				dataSFusion.posD(-1.0);
				dataSFusion.speedN(-1.0);
				dataSFusion.speedE(-1.0);
				dataSFusion.speedD(-1.0);
				dataSFusion.windN(-1.0);
				dataSFusion.windE(-1.0);
				dataSFusion.windD(-1.0);
				dataSFusion.ssa(-1.0);
				dataSFusion.aoa(-1.0);
				dataSFusion.gamma(-1.0);
				std::cout << listener.dataAir.density() << std::endl;
				// reset the alive timer
				aliveTime = timer.getSysTime();
				*/
			}
			
			listener.newDataAhrs = false;
			listener.newDataAir = false;

			dataAhrsLock.unlock();
			dataAirLock.unlock();
			dataSFusionLock.unlock();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);

	}

}

/*
void SFusion::print() {

	std::cout << "--- " << this->name << " " << dataSFusion.time() << " ---" << std::endl;

	std::cout << "gyrX   " << dataSFusion.gyrX() << std::endl;
	std::cout << "gyrY   " << dataSFusion.gyrY() << std::endl;
	std::cout << "gyrZ   " << dataSFusion.gyrZ() << std::endl;
	std::cout << "accX   " << dataSFusion.accX() << std::endl;
	std::cout << "accY   " << dataSFusion.accY() << std::endl;
	std::cout << "accZ   " << dataSFusion.accZ() << std::endl;
	std::cout << "magX   " << dataSFusion.magX() << std::endl;
	std::cout << "magY   " << dataSFusion.magY() << std::endl;
	std::cout << "magZ   " << dataSFusion.magZ() << std::endl;
	std::cout << "temp   " << dataSFusion.temp() << std::endl;
	std::cout << "press  " << dataSFusion.press() << std::endl;
	std::cout << "phi    " << dataSFusion.phi() << std::endl;
	std::cout << "the    " << dataSFusion.the() << std::endl;
	std::cout << "psi    " << dataSFusion.psi() << std::endl;
	std::cout << "q0     " << dataSFusion.q0() << std::endl;
	std::cout << "q1     " << dataSFusion.q1() << std::endl;
	std::cout << "q2     " << dataSFusion.q2() << std::endl;
	std::cout << "q3     " << dataSFusion.q3() << std::endl;
	std::cout << "posN   " << dataSFusion.posN() << std::endl;
	std::cout << "posE   " << dataSFusion.posE() << std::endl;
	std::cout << "posD   " << dataSFusion.posD() << std::endl;
	std::cout << "speedN " << dataSFusion.speedN() << std::endl;
	std::cout << "speedE " << dataSFusion.speedE() << std::endl;
	std::cout << "speedD " << dataSFusion.speedD() << std::endl;
	std::cout << "windN  " << dataSFusion.windN() << std::endl;
	std::cout << "windE  " << dataSFusion.windE() << std::endl;
	std::cout << "windD  " << dataSFusion.windD() << std::endl;
	std::cout << "ssa    " << dataSFusion.ssa() << std::endl;
	std::cout << "aoa    " << dataSFusion.aoa() << std::endl;
	std::cout << "gamma  " << dataSFusion.gamma() << std::endl;
	std::cout << "alive  " << dataSFusion.alive() << std::endl;

}
*/