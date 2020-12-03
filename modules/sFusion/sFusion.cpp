#include "sFusion.h"

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
	void* data = reader->type().create_data();

	while (reader->read_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK) {
		if (info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) {
			if (reader->get_topicdescription()->get_name().compare("DataAhrs") == 0) {
				std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
				reader->take_next_sample(&dataAhrs, &info);
				dataAhrsLock.unlock();
				newDataAhrs = true;

			} else if (reader->get_topicdescription()->get_name().compare("DataAir") == 0) {
				std::unique_lock<std::mutex> dataAirLock {dataAirMutex};
				reader->take_next_sample(&dataAir, &info);
				dataAirLock.unlock();
				newDataAir = true;

			} else {
				reader->take_next_sample(&data, &info);
			}
		} else {
			reader->take_next_sample(&data, &info);
		}
	}

	// TODO why does this cause a segfault ?!?
	// reader->type().delete_data(data);
}

SFusion::SFusion() : participant(nullptr),
                     publisher(nullptr),
                     subscriber(nullptr),
                     topicSFusion(nullptr),
                     writerSFusion(nullptr),
                     typeSFusion(new DataSFusionPubSubType()),
                     topicAhrs(nullptr),
                     readerAhrs(nullptr),
                     typeAhrs(new DataAhrsPubSubType()),
                     topicAir(nullptr),
                     readerAir(nullptr),
                     typeAir(new DataAirPubSubType()) {

}

SFusion::~SFusion() {

	if (writerSFusion != nullptr) {
		publisher->delete_datawriter(writerSFusion);
	}

	if (topicSFusion != nullptr) {
		participant->delete_topic(topicSFusion);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	if (readerAhrs != nullptr) {
		subscriber->delete_datareader(readerAhrs);
	}

	if (topicAhrs != nullptr) {
		participant->delete_topic(topicAhrs);
	}

	if (readerAir != nullptr) {
		subscriber->delete_datareader(readerAir);
	}

	if (topicAir != nullptr) {
		participant->delete_topic(topicAir);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool SFusion::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("SFusionParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeSFusion.register_type(participant);

	// Create the publications Topic
	topicSFusion = participant->create_topic("DataSFusion", "DataSFusion", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicSFusion == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerSFusion = publisher->create_datawriter(topicSFusion, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerSFusion == nullptr) {
		return false;
	}

	// Register the Type
	typeAhrs.register_type(participant);

	// Create the subscriptions Topic
	topicAhrs = participant->create_topic("DataAhrs", "DataAhrs", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicAhrs == nullptr) {
		return false;
	}

	// Register the Type
	typeAir.register_type(participant);

	// Create the subscriptions Topic
	topicAir = participant->create_topic("DataAir", "DataAir", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicAir == nullptr) {
		return false;
	}

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	readerAhrs = subscriber->create_datareader(topicAhrs, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerAhrs == nullptr) {
		return false;
	}

	// Create the DataReader
	readerAir = subscriber->create_datareader(topicAir, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerAir == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	return true;
}


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

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}

}


void SFusion::run() {

	while (1) {

		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataAhrs || listener.newDataAir) {

			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};

			// todo: as soon as we are actually using air, remove comment
			if (listener.dataAhrs.alive() /* && listener.dataAir.alive()*/) {

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

				// reset the alive timer
				aliveTime = timer.getSysTime();
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
