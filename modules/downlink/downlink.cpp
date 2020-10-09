#include "downlink.h"

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
                       publisher(nullptr),
                       subscriber(nullptr),
                       topicDownlink(nullptr),
                       writerDownlink(nullptr),
                       typeDownlink(new DataDownlinkPubSubType()),
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

	if (writerDownlink != nullptr) {
		publisher->delete_datawriter(writerDownlink);
	}
	if (topicDownlink != nullptr) {
		participant->delete_topic(topicDownlink);
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
	typeDownlink.register_type(participant);
	// Create the publications Topic
	topicDownlink = participant->create_topic("DataDownlink", "DataDownlink", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicDownlink == nullptr) {
		return false;
	}
	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}
	// Create the DataWriter
	writerDownlink = publisher->create_datawriter(topicDownlink, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerDownlink == nullptr) {
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

	aliveTime = timer.getSysTime();

	if (serial.init(TELEMETRY_COM_PORT,B115200) != true) {
		return false;
	}

	return true;
}

void Downlink::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataDownlinkLock {dataDownlinkMutex};
		dataDownlink.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataDownlink.alive(true);
		} else {
			dataDownlink.alive(false);
		}

		writerDownlink->write(&dataDownlink);
		dataDownlinkLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Downlink::run() {

	// Set the interval time [in seconds], 0.0 is deactivate
	const double dataRaiInInterval = 0.5;
	const double dataRaiOutInterval = 0.5;
	const double dataSFusionInterval = 0.0;
	const double dataAhrsInterval = 0.1;
	const double dataAirInterval = 0.2;
	const double dataPsuInterval = 1.0;
	const double dataCtrlInterval = 0.0;

	static double dataRaiInTime = timer.getSysTimeS();
	static double dataRaiOutTime = timer.getSysTimeS();
	static double dataSFusionTime = timer.getSysTimeS();
	static double dataAhrsTime = timer.getSysTimeS();
	static double dataAirTime = timer.getSysTimeS();
	static double dataPsuTime = timer.getSysTimeS();
	static double dataCtrlTime = timer.getSysTimeS();

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataRaiIn &&
		    timer.getSysTimeS()-dataRaiInTime > dataRaiInInterval &&
		    dataRaiInInterval > 0.0) {

			dataRaiInTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			// std::cout << "send DataRaiIn" << std::endl;

			mavlink_message_t msg;
			mavlink_dataraiin_t msg_raiIn;
			uint8_t buf[200];
			uint16_t len;
			msg_raiIn.time = listener.dataRaiIn.time();
			msg_raiIn.senseTime = listener.dataRaiIn.senseTime();
			for (int i=0; i<12; i++) {
				msg_raiIn.chnl[i] = listener.dataRaiIn.chnl().at(i);
			}
			msg_raiIn.roll = listener.dataRaiIn.roll();
			msg_raiIn.pitch = listener.dataRaiIn.pitch();
			msg_raiIn.yaw = listener.dataRaiIn.yaw();
			msg_raiIn.thr = listener.dataRaiIn.thr();
			msg_raiIn.fltMode = listener.dataRaiIn.fltMode();
			msg_raiIn.alive = listener.dataRaiIn.alive();
			mavlink_msg_dataraiin_encode(sysid, compid, &msg, &msg_raiIn);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataRaiIn" << std::endl;
			}

			dataRaiInLock.unlock();
			listener.newDataRaiIn = false;
		}

		if (listener.newDataRaiOut &&
			timer.getSysTimeS()-dataRaiOutTime > dataRaiOutInterval &&
			dataRaiOutInterval > 0.0) {

			dataRaiOutTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataRaiOutLock {listener.dataRaiOutMutex};
			// std::cout << "send DataRaiOut" << std::endl;

			mavlink_message_t msg;
			mavlink_dataraiout_t msg_raiOut;
			uint8_t buf[200];
			uint16_t len;
			msg_raiOut.time = listener.dataRaiOut.time();
			for (int i=0; i<12; i++) {
				msg_raiOut.chnl[i] = listener.dataRaiOut.chnl().at(i);
			}
			msg_raiOut.roll = listener.dataRaiOut.roll();
			msg_raiOut.pitch = listener.dataRaiOut.pitch();
			msg_raiOut.yaw = listener.dataRaiOut.yaw();
			msg_raiOut.thr = listener.dataRaiOut.thr();
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

		if (listener.newDataSFusion &&
			timer.getSysTimeS()-dataSFusionTime > dataSFusionInterval &&
			dataSFusionInterval > 0.0) {

			dataSFusionTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
			// std::cout << "send DataSFusion" << std::endl;

			mavlink_message_t msg;
			mavlink_datasfusion_t msg_sfusion;
			uint8_t buf[200];
			uint16_t len;
			msg_sfusion.time = listener.dataSFusion.time();
			msg_sfusion.gyrX = listener.dataSFusion.gyrX();
			msg_sfusion.gyrY = listener.dataSFusion.gyrY();
			msg_sfusion.gyrZ = listener.dataSFusion.gyrZ();
			msg_sfusion.accX = listener.dataSFusion.accX();
			msg_sfusion.accY = listener.dataSFusion.accY();
			msg_sfusion.accZ = listener.dataSFusion.accZ();
			msg_sfusion.magX = listener.dataSFusion.magX();
			msg_sfusion.magY = listener.dataSFusion.magY();
			msg_sfusion.magZ = listener.dataSFusion.magZ();
			msg_sfusion.temp = listener.dataSFusion.temp();
			msg_sfusion.press = listener.dataSFusion.press();
			msg_sfusion.phi = listener.dataSFusion.phi();
			msg_sfusion.the = listener.dataSFusion.the();
			msg_sfusion.psi = listener.dataSFusion.psi();
			msg_sfusion.q0 = listener.dataSFusion.q0();
			msg_sfusion.q1 = listener.dataSFusion.q1();
			msg_sfusion.q2 = listener.dataSFusion.q2();
			msg_sfusion.q3 = listener.dataSFusion.q3();
			msg_sfusion.posN = listener.dataSFusion.posN();
			msg_sfusion.posE = listener.dataSFusion.posE();
			msg_sfusion.posD = listener.dataSFusion.posD();
			msg_sfusion.speedN = listener.dataSFusion.speedN();
			msg_sfusion.speedE = listener.dataSFusion.speedE();
			msg_sfusion.speedD = listener.dataSFusion.speedD();
			msg_sfusion.windN = listener.dataSFusion.windN();
			msg_sfusion.windE = listener.dataSFusion.windE();
			msg_sfusion.windD = listener.dataSFusion.windD();
			msg_sfusion.ssa = listener.dataSFusion.ssa();
			msg_sfusion.aoa = listener.dataSFusion.aoa();
			msg_sfusion.gamma = listener.dataSFusion.gamma();
			msg_sfusion.alive = listener.dataSFusion.alive();
			mavlink_msg_datasfusion_encode(sysid, compid, &msg, &msg_sfusion);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataSFusion" << std::endl;
			}

			dataSFusionLock.unlock();
			listener.newDataSFusion = false;
		}

		if (listener.newDataAhrs &&
			timer.getSysTimeS()-dataAhrsTime > dataAhrsInterval &&
			dataAhrsInterval > 0.0) {

			dataAhrsTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			// std::cout << "send DataAhrs" << std::endl;

			mavlink_message_t msg;
			mavlink_dataahrs_t msg_ahrs;
			uint8_t buf[200];
			uint16_t len;
			msg_ahrs.time = listener.dataAhrs.time();
			msg_ahrs.senseTime = listener.dataAhrs.senseTime();
			msg_ahrs.gyrX = listener.dataAhrs.gyrX();
			msg_ahrs.gyrY = listener.dataAhrs.gyrY();
			msg_ahrs.gyrZ = listener.dataAhrs.gyrZ();
			msg_ahrs.accX = listener.dataAhrs.accX();
			msg_ahrs.accY = listener.dataAhrs.accY();
			msg_ahrs.accZ = listener.dataAhrs.accZ();
			msg_ahrs.magX = listener.dataAhrs.magX();
			msg_ahrs.magY = listener.dataAhrs.magY();
			msg_ahrs.magZ = listener.dataAhrs.magZ();
			msg_ahrs.temp = listener.dataAhrs.temp();
			msg_ahrs.press = listener.dataAhrs.press();
			msg_ahrs.phi = listener.dataAhrs.phi();
			msg_ahrs.the = listener.dataAhrs.the();
			msg_ahrs.psi = listener.dataAhrs.psi();
			msg_ahrs.q0 = listener.dataAhrs.q0();
			msg_ahrs.q1 = listener.dataAhrs.q1();
			msg_ahrs.q2 = listener.dataAhrs.q2();
			msg_ahrs.q3 = listener.dataAhrs.q3();
			msg_ahrs.alive = listener.dataAhrs.alive();
			mavlink_msg_dataahrs_encode(sysid, compid, &msg, &msg_ahrs);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataAhrs" << std::endl;
			}

			dataAhrsLock.unlock();
			listener.newDataAhrs = false;
		}

		if (listener.newDataAir &&
			timer.getSysTimeS()-dataAirTime > dataAirInterval &&
			dataAirInterval > 0.0) {

			dataAirTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			// std::cout << "send DataAir" << std::endl;

			mavlink_message_t msg;
			mavlink_dataair_t msg_air;
			uint8_t buf[200];
			uint16_t len;
			msg_air.time = listener.dataAir.time();
			msg_air.senseTime = listener.dataAir.senseTime();
			msg_air.dynamicPress = listener.dataAir.dynamicPress();
			msg_air.velocity = listener.dataAir.velocity();
			msg_air.baroPress = listener.dataAir.baroPress();
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

		if (listener.newDataCtrl &&
			timer.getSysTimeS()-dataCtrlTime > dataCtrlInterval &&
			dataCtrlInterval > 0.0) {

			dataCtrlTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			// std::cout << "send DataCtrl" << std::endl;

			mavlink_message_t msg;
			mavlink_datactrl_t msg_ctrl;
			uint8_t buf[200];
			uint16_t len;
			msg_ctrl.time = listener.dataCtrl.time();
			msg_ctrl.xi = listener.dataCtrl.xi();
			msg_ctrl.eta = listener.dataCtrl.eta();
			msg_ctrl.zeta = listener.dataCtrl.zeta();
			msg_ctrl.etaT = listener.dataCtrl.etaT();
			msg_ctrl.etaF = listener.dataCtrl.etaF();
			msg_ctrl.alive = listener.dataCtrl.alive();
			mavlink_msg_datactrl_encode(sysid, compid, &msg, &msg_ctrl);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataCtrl" << std::endl;
			}

			dataCtrlLock.unlock();
			listener.newDataCtrl = false;
		}

		if (listener.newDataPsu &&
			timer.getSysTimeS()-dataPsuTime > dataPsuInterval &&
			dataPsuInterval > 0.0) {

			dataPsuTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataPsuLock {listener.dataPsuMutex};
			// std::cout << "send DataPsu" << std::endl;

			mavlink_message_t msg;
			mavlink_datapsu_t msg_psu;
			uint8_t buf[200];
			uint16_t len;
			msg_psu.time = listener.dataPsu.time();
			msg_psu.senseTime = listener.dataPsu.senseTime();
			msg_psu.mainVolt = listener.dataPsu.mainVolt();
			msg_psu.mainCurr = listener.dataPsu.mainCurr();
			msg_psu.mainPow = listener.dataPsu.mainPow();
			msg_psu.pwrVolt = listener.dataPsu.pwrVolt();
			msg_psu.pwrCurr = listener.dataPsu.pwrCurr();
			msg_psu.pwrPow = listener.dataPsu.pwrPow();
			msg_psu.sysVolt = listener.dataPsu.sysVolt();
			msg_psu.sysCurr = listener.dataPsu.sysCurr();
			msg_psu.sysPow = listener.dataPsu.sysPow();
			msg_psu.alive = listener.dataPsu.alive();
			mavlink_msg_datapsu_encode(sysid, compid, &msg, &msg_psu);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataPsu" << std::endl;
			}

			dataPsuLock.unlock();
			listener.newDataPsu = false;
		}

		aliveTime = timer.getSysTime();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Downlink::print() {

	std::cout << "--- " << this->name << " " << dataDownlink.time() << " ---" << std::endl;

	std::cout << "alive   " << dataDownlink.alive() << std::endl;

}
