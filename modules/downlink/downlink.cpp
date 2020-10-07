#include "downlink.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : subscription_matched(0) {
}

Listener::~Listener() {
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
		if (info.instance_state == eprosima::fastdds::dds::ALIVE && info.valid_data) {
			if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {
				std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
				reader->take_next_sample(&dataRaiIn, &info);
				dataRaiInLock.unlock();
				newDataRaiIn = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataRaiOut") == 0) {
				std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};
				reader->take_next_sample(&dataRaiOut, &info);
				dataRaiOutLock.unlock();
				newDataRaiOut = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataSFusion") == 0) {
				std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
				reader->take_next_sample(&dataSFusion, &info);
				dataSFusionLock.unlock();
				newDataSFusion = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataAhrs") == 0) {
				std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
				reader->take_next_sample(&dataAhrs, &info);
				dataAhrsLock.unlock();
				newDataAhrs = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataAir") == 0) {
				std::unique_lock<std::mutex> dataAirLock {dataAirMutex};
				reader->take_next_sample(&dataAir, &info);
				dataAirLock.unlock();
				newDataAir = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataPsu") == 0) {
				std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};
				reader->take_next_sample(&dataPsu, &info);
				dataPsuLock.unlock();
				newDataPsu = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
				std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
				reader->take_next_sample(&dataCtrl, &info);
				dataCtrlLock.unlock();
				newDataCtrl = true;
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

Downlink::Downlink() : participant(nullptr),
                       subscriber(nullptr),
                       topicRaiIn(nullptr),
                       readerRaiIn(nullptr),
                       typeRaiIn(new DataRaiInPubSubType()),
                       topicRaiOut(nullptr),
                       readerRaiOut(nullptr),
                       typeRaiOut(new DataRaiOutPubSubType()),
                       topicSFusion(nullptr),
                       readerSFusion(nullptr),
                       typeSFusion(new DataSFusionPubSubType()),
                       topicAhrs(nullptr),
                       readerAhrs(nullptr),
                       typeAhrs(new DataAhrsPubSubType()),
                       topicAir(nullptr),
                       readerAir(nullptr),
                       typeAir(new DataAirPubSubType()),
                       topicPsu(nullptr),
                       readerPsu(nullptr),
                       typePsu(new DataPsuPubSubType()),
                       topicCtrl(nullptr),
                       readerCtrl(nullptr),
                       typeCtrl(new DataCtrlPubSubType()) {

}

Downlink::~Downlink() {

	if (readerRaiIn != nullptr) {
		subscriber->delete_datareader(readerRaiIn);
	}
	if (topicRaiIn != nullptr) {
		participant->delete_topic(topicRaiIn);
	}
	if (readerRaiOut != nullptr) {
		subscriber->delete_datareader(readerRaiOut);
	}
	if (topicRaiOut != nullptr) {
		participant->delete_topic(topicRaiOut);
	}
	if (readerSFusion != nullptr) {
		subscriber->delete_datareader(readerSFusion);
	}
	if (topicSFusion != nullptr) {
		participant->delete_topic(topicSFusion);
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
	if (readerPsu != nullptr) {
		subscriber->delete_datareader(readerPsu);
	}
	if (topicPsu != nullptr) {
		participant->delete_topic(topicPsu);
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

bool Downlink::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("DownlinkParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
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
	typeRaiOut.register_type(participant);
	// Create the subscriptions Topic
	topicRaiOut = participant->create_topic("DataRaiOut", "DataRaiOut", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicRaiOut == nullptr) {
		return false;
	}
	// Register the Type
	typeSFusion.register_type(participant);
	// Create the subscriptions Topic
	topicSFusion = participant->create_topic("DataSFusion", "DataSFusion", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicSFusion == nullptr) {
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
	// Register the Type
	typePsu.register_type(participant);
	// Create the subscriptions Topic
	topicPsu = participant->create_topic("DataPsu", "DataPsu", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicPsu == nullptr) {
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
	readerRaiIn = subscriber->create_datareader(topicRaiIn, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerRaiIn == nullptr) {
		return false;
	}
	// Create the DataReader
	readerRaiOut = subscriber->create_datareader(topicRaiOut, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerRaiOut == nullptr) {
		return false;
	}
	// Create the DataReader
	readerSFusion = subscriber->create_datareader(topicSFusion, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerSFusion == nullptr) {
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
	// Create the DataReader
	readerPsu = subscriber->create_datareader(topicPsu, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerPsu == nullptr) {
		return false;
	}
	// Create the DataReader
	readerCtrl = subscriber->create_datareader(topicCtrl, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerCtrl == nullptr) {
		return false;
	}

	if (serial.init(TELEMETRY_COM_PORT,B115200) != true) {
        return false;
    }

	return true;
}

void Downlink::run() {

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataRaiIn) {
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			std::cout << "newDataRaiIn" << std::endl;

			mavlink_message_t msg;
			mavlink_dataraiin_t msg_raiIn;
			uint8_t buf[200];
			uint16_t len;
			msg_raiIn.time = listener.dataRaiIn.time();
			msg_raiIn.senseTime = listener.dataRaiIn.senseTime();
			// TODO chnl
			msg_raiIn.roll = listener.dataRaiIn.roll();
			msg_raiIn.pitch = listener.dataRaiIn.pitch();
			msg_raiIn.yaw = listener.dataRaiIn.yaw();
			msg_raiIn.fltmode = listener.dataRaiIn.fltMode();
			msg_raiIn.alive = listener.dataRaiIn.alive();
			mavlink_msg_dataraiin_encode(sysid, compid, &msg, &msg_raiIn);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataRaiIn" << std::endl;
			}

			dataRaiInLock.unlock();
			listener.newDataRaiIn = false;
		}
		if (listener.newDataRaiOut) {
			std::unique_lock<std::mutex> dataRaiOutLock {listener.dataRaiOutMutex};
			std::cout << "newDataRaiOut" << std::endl;

			mavlink_message_t msg;
			mavlink_dataraiout_t msg_raiOut;
			uint8_t buf[200];
			uint16_t len;
			msg_raiOut.time = listener.dataRaiOut.time();
			// TODO chnl
			msg_raiOut.roll = listener.dataRaiOut.roll();
			msg_raiOut.pitch = listener.dataRaiOut.pitch();
			msg_raiOut.yaw = listener.dataRaiOut.yaw();
			msg_raiOut.fltMode = listener.dataRaiOut.fltMode();
			msg_raiOut.alive = listener.dataRaiOut.alive();
			mavlink_msg_dataraiout_encode(sysid, compid, &msg, &msg_raiOut);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataRaiOut" << std::endl;
			}

			dataRaiOutLock.unlock();
			listener.newDataRaiOut = false;
		}
		// if (listener.newDataSFusion) {
		// 	std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
		// 	std::cout << "newDataSFusion" << std::endl;
		//
		// 	// TODO
		//
		// 	dataSFusionLock.unlock();
		// 	listener.newDataSFusion = false;
		// }
		if (listener.newDataAhrs) {
			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			std::cout << "newDataAhrs" << std::endl;

			mavlink_message_t msg;
			mavlink_dataahrs_t msg_ahrs;
			uint8_t buf[200];
			uint16_t len;
			msg_ahrs.time = listener.dataAhrs.time();
			msg_ahrs.senseTime = listener.dataAhrs.senseTime();
			msg_ahrs.gX = listener.dataAhrs.gyrX();
			msg_ahrs.gY = listener.dataAhrs.gyrY();
			msg_ahrs.gZ = listener.dataAhrs.gyrZ();
			msg_ahrs.aX = listener.dataAhrs.accX();
			msg_ahrs.aY = listener.dataAhrs.accY();
			msg_ahrs.aZ = listener.dataAhrs.accZ();
			msg_ahrs.mX = listener.dataAhrs.magX();
			msg_ahrs.mY = listener.dataAhrs.magY();
			msg_ahrs.mZ = listener.dataAhrs.magZ();
			msg_ahrs.phi = listener.dataAhrs.phi();
			msg_ahrs.the = listener.dataAhrs.the();
			msg_ahrs.psi = listener.dataAhrs.psi();
			msg_ahrs.temp = listener.dataAhrs.temp();
			msg_ahrs.baro_ahrs = listener.dataAhrs.press();
			msg_ahrs.q0 = listener.dataAhrs.p0();
			msg_ahrs.q1 = listener.dataAhrs.p1();
			msg_ahrs.q2 = listener.dataAhrs.p2();
			msg_ahrs.q3 = listener.dataAhrs.p3();
			msg_ahrs.alive = listener.dataAhrs.alive();
			mavlink_msg_dataahrs_encode(sysid, compid, &msg, &msg_ahrs);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataAhrs" << std::endl;
			}

			dataAhrsLock.unlock();
			listener.newDataAhrs = false;
		}
		if (listener.newDataAir) {
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			std::cout << "newDataAir" << std::endl;

			mavlink_message_t msg;
			mavlink_dataair_t msg_air;
			uint8_t buf[200];
			uint16_t len;
			msg_air.time = listener.dataAir.time();
			msg_air.senseTime = listener.dataAir.senseTime();
			msg_air.TAS = listener.dataAir.velocity();
			msg_air.baro_air = listener.dataAir.baroPress();
			msg_air.density = listener.dataAir.density();
			msg_air.temp = listener.dataAir.temp();
			msg_air.alive = listener.dataAir.alive();
			mavlink_msg_dataair_encode(sysid, compid, &msg, &msg_air);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataAir" << std::endl;
			}

			dataAirLock.unlock();
			listener.newDataAir = false;
		}
		// if (listener.newDataPsu) {
		// 	std::unique_lock<std::mutex> dataPsuLock {listener.dataPsuMutex};
		// 	std::cout << "newDataPsu" << std::endl;
		//
		// 	// TODO
		//
		// 	dataPsuLock.unlock();
		// 	listener.newDataPsu = false;
		// }
		// if (listener.newDataCtrl) {
		// 	std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
		// 	std::cout << "newDataCtrl" << std::endl;
		//
		// 	// TODO
		//
		// 	dataCtrlLock.unlock();
		// 	listener.newDataCtrl = false;
		// }

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(100);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(100);
	}
}