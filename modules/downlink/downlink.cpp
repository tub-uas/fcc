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
	std::string topic = reader->get_topicdescription()->get_name();

	/***PYTHON_GEN_ON_DATA_CALLBACK*/
	if (topic.compare("DataAhrs") == 0)
	{
		std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
		if(reader->take_next_sample(&dataAhrs, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataAhrs = true;
			}
		}
		dataAhrsLock.unlock();
	}
	else if (topic.compare("DataAir") == 0)
	{
		std::unique_lock<std::mutex> dataAirLock {dataAirMutex};
		if(reader->take_next_sample(&dataAir, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataAir = true;
			}
		}
		dataAirLock.unlock();
	}
	else if (topic.compare("DataCtrl") == 0)
	{
		std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
		if(reader->take_next_sample(&dataCtrl, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataCtrl = true;
			}
		}
		dataCtrlLock.unlock();
	}
	else if (topic.compare("DataGps") == 0)
	{
		std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};
		if(reader->take_next_sample(&dataGps, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataGps = true;
			}
		}
		dataGpsLock.unlock();
	}
	else if (topic.compare("DataPsu") == 0)
	{
		std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};
		if(reader->take_next_sample(&dataPsu, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataPsu = true;
			}
		}
		dataPsuLock.unlock();
	}
	else if (topic.compare("DataRaiIn") == 0)
	{
		std::unique_lock<std::mutex> dataRaiInLock {dataRaiInMutex};
		if(reader->take_next_sample(&dataRaiIn, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataRaiIn = true;
			}
		}
		dataRaiInLock.unlock();
	}
	else if (topic.compare("DataRaiOut") == 0)
	{
		std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};
		if(reader->take_next_sample(&dataRaiOut, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataRaiOut = true;
			}
		}
		dataRaiOutLock.unlock();
	}
	else if (topic.compare("DataSFusion") == 0)
	{
		std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
		if(reader->take_next_sample(&dataSFusion, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataSFusion = true;
			}
		}
		dataSFusionLock.unlock();
	}
	else if (topic.compare("DataWatchdog") == 0)
	{
		std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
		if(reader->take_next_sample(&dataWatchdog, &info) == ReturnCode_t::RETCODE_OK) 
		{
			if(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) 
			{
				 newDataWatchdog = true;
			}
		}
		dataWatchdogLock.unlock();
	} else {
		
	}

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
                       topicGps(nullptr),
                       readerGps(nullptr),
                       typeGps(new DataGpsPubSubType()),
                       topicPsu(nullptr),
                       readerPsu(nullptr),
                       typePsu(new DataPsuPubSubType()),
                       topicCtrl(nullptr),
                       readerCtrl(nullptr),
                       typeCtrl(new DataCtrlPubSubType()),
                       topicWatchdog(nullptr),
                       readerWatchdog(nullptr),
                       typeWatchdog(new DataWatchdogPubSubType()) {

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
	if (readerGps != nullptr) {
		subscriber->delete_datareader(readerGps);
	}
	if (topicGps != nullptr) {
		participant->delete_topic(topicGps);
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
	if (readerWatchdog != nullptr) {
		subscriber->delete_datareader(readerWatchdog);
	}
	if (topicWatchdog != nullptr) {
		participant->delete_topic(topicWatchdog);
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
	typeGps.register_type(participant);
	// Create the subscriptions Topic
	topicGps = participant->create_topic("DataGps", "DataGps", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicGps == nullptr) {
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
	// Register the Type
	typeWatchdog.register_type(participant);
	// Create the subscriptions Topic
	topicWatchdog = participant->create_topic("DataWatchdog", "DataWatchdog", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicWatchdog == nullptr) {
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
	readerGps = subscriber->create_datareader(topicGps, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerGps == nullptr) {
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
	// Create the DataReader
	readerWatchdog = subscriber->create_datareader(topicWatchdog, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerWatchdog == nullptr) {
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
	const double dataGpsInterval = 1.0;
	const double dataPsuInterval = 1.0;
	const double dataCtrlInterval = 0.0;
	const double dataWatchdogInterval = 1.0;

	static double dataRaiInTime = timer.getSysTimeS();
	static double dataRaiOutTime = timer.getSysTimeS();
	static double dataSFusionTime = timer.getSysTimeS();
	static double dataAhrsTime = timer.getSysTimeS();
	static double dataAirTime = timer.getSysTimeS();
	static double dataGpsTime = timer.getSysTimeS();
	static double dataPsuTime = timer.getSysTimeS();
	static double dataCtrlTime = timer.getSysTimeS();
	static double dataWatchdogTime = timer.getSysTimeS();

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
			msg_raiIn.xi_setpoint = listener.dataRaiIn.xi_setpoint();
			msg_raiIn.eta_setpoint = listener.dataRaiIn.eta_setpoint();
			msg_raiIn.zeta_setpoint = listener.dataRaiIn.zeta_setpoint();
			msg_raiIn.throttle_setpoint = listener.dataRaiIn.throttle_setpoint();
			msg_raiIn.flaps_setpoint = listener.dataRaiIn.flaps_setpoint();
			msg_raiIn.roll_setpoint = listener.dataRaiIn.roll_setpoint();
			msg_raiIn.roll_rate_setpoint = listener.dataRaiIn.roll_rate_setpoint();
			msg_raiIn.pitch_setpoint = listener.dataRaiIn.pitch_setpoint();
			msg_raiIn.pitch_rate_setpoint = listener.dataRaiIn.pitch_rate_setpoint();
			msg_raiIn.yaw_setpoint = listener.dataRaiIn.yaw_setpoint();
			msg_raiIn.yaw_rate_setpoint = listener.dataRaiIn.yaw_rate_setpoint();
			msg_raiIn.tas_setpoint = listener.dataRaiIn.tas_setpoint();
			msg_raiIn.tas_rate_setpoint = listener.dataRaiIn.tas_rate_setpoint();
			msg_raiIn.hgt_setpoint = listener.dataRaiIn.hgt_setpoint();
			msg_raiIn.hgt_rate_setpoint = listener.dataRaiIn.hgt_rate_setpoint();
			msg_raiIn.flight_mode = listener.dataRaiIn.flight_mode();
			msg_raiIn.flight_fct = listener.dataRaiIn.flight_fct();
			msg_raiIn.alive = listener.dataRaiIn.alive();
			mavlink_msg_dataraiin_encode(sysid, compid, &msg, &msg_raiIn);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataRaiIn" << std::endl;
			}

			listener.newDataRaiIn = false;
			dataRaiInLock.unlock();
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
			msg_raiOut.xi_setpoint = listener.dataRaiOut.xi_setpoint();
			msg_raiOut.eta_setpoint = listener.dataRaiOut.eta_setpoint();
			msg_raiOut.zeta_setpoint = listener.dataRaiOut.zeta_setpoint();
			msg_raiOut.throttle_setpoint = listener.dataRaiOut.throttle_setpoint();
			msg_raiOut.flaps_setpoint = listener.dataRaiOut.flaps_setpoint();
			msg_raiOut.flight_mode = listener.dataRaiOut.flight_mode();
			msg_raiOut.flight_fct = listener.dataRaiOut.flight_fct();
			msg_raiOut.alive = listener.dataRaiOut.alive();
			mavlink_msg_dataraiout_encode(sysid, compid, &msg, &msg_raiOut);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataRaiOut" << std::endl;
			}

			listener.newDataRaiOut = false;
			dataRaiOutLock.unlock();
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
			msg_sfusion.gyrX = listener.dataSFusion.p();
			msg_sfusion.gyrY = listener.dataSFusion.q();
			msg_sfusion.gyrZ = listener.dataSFusion.r();
			msg_sfusion.a_x = listener.dataSFusion.a_x();
			msg_sfusion.a_y = listener.dataSFusion.a_y();
			msg_sfusion.a_z = listener.dataSFusion.a_z();
			msg_sfusion.magX = listener.dataSFusion.true_airspeed();
			msg_sfusion.magY = listener.dataSFusion.indicated_airspeed();
			msg_sfusion.magZ = listener.dataSFusion.density();
			msg_sfusion.dynamic_pressure = listener.dataSFusion.dynamic_pressure();
			msg_sfusion.barometric_pressure = listener.dataSFusion.barometric_pressure();
			msg_sfusion.height_rate = listener.dataSFusion.height_rate();
			msg_sfusion.height = listener.dataSFusion.height();
			msg_sfusion.ssa = listener.dataSFusion.ssa();
			msg_sfusion.aoa = listener.dataSFusion.aoa();
			msg_sfusion.gamma = listener.dataSFusion.gamma();
			msg_sfusion.phi = listener.dataSFusion.phi();
			msg_sfusion.the = listener.dataSFusion.the();
			msg_sfusion.psi = listener.dataSFusion.psi();
			msg_sfusion.latitude = listener.dataSFusion.latitude();
			msg_sfusion.longitude = listener.dataSFusion.longitude();
			msg_sfusion.posN = listener.dataSFusion.posN();
			msg_sfusion.posE = listener.dataSFusion.posE();
			msg_sfusion.posD = listener.dataSFusion.posD();
			msg_sfusion.speedN = listener.dataSFusion.speedN();
			msg_sfusion.speedE = listener.dataSFusion.speedE();
			msg_sfusion.speedD = listener.dataSFusion.speedD();
			msg_sfusion.windN = listener.dataSFusion.windN();
			msg_sfusion.windE = listener.dataSFusion.windE();
			msg_sfusion.windD = listener.dataSFusion.windD();
			
			msg_sfusion.alive = listener.dataSFusion.alive();
			mavlink_msg_datasfusion_encode(sysid, compid, &msg, &msg_sfusion);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataSFusion" << std::endl;
			}

			listener.newDataSFusion = false;
			dataSFusionLock.unlock();
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
			msg_ahrs.temperature = listener.dataAhrs.temperature();
			msg_ahrs.barometric_pressure = listener.dataAhrs.barometric_pressure();
			msg_ahrs.phi = listener.dataAhrs.phi();
			msg_ahrs.the = listener.dataAhrs.the();
			msg_ahrs.psi = listener.dataAhrs.psi();
			msg_ahrs.alive = listener.dataAhrs.alive();
			mavlink_msg_dataahrs_encode(sysid, compid, &msg, &msg_ahrs);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataAhrs" << std::endl;
			}

			listener.newDataAhrs = false;
			dataAhrsLock.unlock();
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
			msg_air.dynamicPress = listener.dataAir.dynamic_pressure();
			msg_air.true_airspeed = listener.dataAir.true_airspeed();
			msg_air.indicated_airspeed = listener.dataAir.indicated_airspeed();
			msg_air.barometric_pressure = listener.dataAir.barometric_pressure();
			msg_air.barometric_height = listener.dataAir.barometric_height();
			msg_air.density = listener.dataAir.density();
			msg_air.temperature = listener.dataAir.temperature();
			msg_air.alive = listener.dataAir.alive();
			mavlink_msg_dataair_encode(sysid, compid, &msg, &msg_air);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataAir" << std::endl;
			}

			listener.newDataAir = false;
			dataAirLock.unlock();
		}

		if (listener.newDataGps &&
		    timer.getSysTimeS()-dataGpsTime > dataGpsInterval &&
		    dataGpsInterval > 0.0) {

			dataGpsTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataGpsLock {listener.dataGpsMutex};
			// std::cout << "send DataGps" << std::endl;

			mavlink_message_t msg;
			mavlink_datagps_t msg_gps;
			uint8_t buf[200];
			uint16_t len;
			msg_gps.time = listener.dataGps.time();
			msg_gps.senseTime = listener.dataGps.senseTime();
			msg_gps.lat = listener.dataGps.latitude();
			msg_gps.lon = listener.dataGps.longitude();
			msg_gps.alt = listener.dataGps.alt_msl();
			msg_gps.groundspeed = listener.dataGps.groundspeed();
			msg_gps.course_over_ground = listener.dataGps.course_over_ground();
			msg_gps.sats = listener.dataGps.sats();
			msg_gps.sats_in_view = listener.dataGps.sats_in_view();
			msg_gps.fix = listener.dataGps.fix();
			msg_gps.fix_mode = listener.dataGps.fix_mode();
			msg_gps.dop_position = listener.dataGps.dop_position();
			msg_gps.dop_horizontal = listener.dataGps.dop_horizontal();
			msg_gps.dop_velocity = listener.dataGps.dop_velocity();
			msg_gps.alive = listener.dataGps.alive();
			mavlink_msg_datagps_encode(sysid, compid, &msg, &msg_gps);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataGps" << std::endl;
			}

			listener.newDataGps = false;
			dataGpsLock.unlock();
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
			msg_ctrl.xi = listener.dataCtrl.xi_setpoint();
			msg_ctrl.eta = listener.dataCtrl.eta_setpoint();
			msg_ctrl.zeta = listener.dataCtrl.zeta_setpoint();
			msg_ctrl.etaT = listener.dataCtrl.throttle_setpoint();
			msg_ctrl.etaF = listener.dataCtrl.flaps_setpoint();
			msg_ctrl.alive = listener.dataCtrl.alive();
			mavlink_msg_datactrl_encode(sysid, compid, &msg, &msg_ctrl);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataCtrl" << std::endl;
			}

			listener.newDataCtrl = false;
			dataCtrlLock.unlock();
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
			msg_psu.main_volt = listener.dataPsu.main_volt();
			msg_psu.main_curr = listener.dataPsu.main_curr();
			msg_psu.main_pwr = listener.dataPsu.main_pwr();
			msg_psu.pwr_volt = listener.dataPsu.pwr_volt();
			msg_psu.pwr_curr = listener.dataPsu.pwr_curr();
			msg_psu.pwr_pwr = listener.dataPsu.pwr_pwr();
			msg_psu.sys_volt = listener.dataPsu.sys_volt();
			msg_psu.sys_curr = listener.dataPsu.sys_curr();
			msg_psu.sys_pwr = listener.dataPsu.sys_pwr();
			msg_psu.alive = listener.dataPsu.alive();
			mavlink_msg_datapsu_encode(sysid, compid, &msg, &msg_psu);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataPsu" << std::endl;
			}

			listener.newDataPsu = false;
			dataPsuLock.unlock();
		}

		if (listener.newDataWatchdog &&
		    timer.getSysTimeS()-dataWatchdogTime > dataWatchdogInterval &&
		    dataWatchdogInterval > 0.0) {

			dataWatchdogTime = timer.getSysTimeS();

			std::unique_lock<std::mutex> dataWatchdogLock {listener.dataWatchdogMutex};
			// std::cout << "send DataWatchdog" << std::endl;

			mavlink_message_t msg;
			mavlink_datawatchdog_t msg_watchdog;
			uint8_t buf[200];
			uint16_t len;
			msg_watchdog.time = listener.dataWatchdog.time();
			msg_watchdog.allAlive = listener.dataWatchdog.allAlive();
			msg_watchdog.ahrsAlive = listener.dataWatchdog.ahrsAlive();
			msg_watchdog.airAlive = listener.dataWatchdog.airAlive();
			msg_watchdog.ctrlAlive = listener.dataWatchdog.ctrlAlive();
			msg_watchdog.downlinkAlive = listener.dataWatchdog.downlinkAlive();
			msg_watchdog.gpsAlive = listener.dataWatchdog.gpsAlive();
			msg_watchdog.logAlive = listener.dataWatchdog.logAlive();
			msg_watchdog.psuAlive = listener.dataWatchdog.psuAlive();
			msg_watchdog.raiInAlive = listener.dataWatchdog.raiInAlive();
			msg_watchdog.raiOutAlive = listener.dataWatchdog.raiOutAlive();
			msg_watchdog.sFusionAlive = listener.dataWatchdog.sFusionAlive();
			msg_watchdog.uplinkAlive = listener.dataWatchdog.uplinkAlive();
			msg_watchdog.alive = listener.dataWatchdog.alive();
			mavlink_msg_datawatchdog_encode(sysid, compid, &msg, &msg_watchdog);
			len = mavlink_msg_to_send_buffer(buf, &msg);
			if (!serial.send(buf,len)) {
				std::cout << "ERROR: Could not send DataWatchdog" << std::endl;
			}

			listener.newDataWatchdog = false;
			dataWatchdogLock.unlock();
		}

		// reset the alive timer
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
