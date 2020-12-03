#include "log.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include <cstdint>
#include <endian.h> // todo: implement plafform independent endianess (host to little endian)

#include <boost/filesystem.hpp>


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
			/***PYTHON_GEN_ON_DATA_CALLBACK*/
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
			} else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
				std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
				reader->take_next_sample(&dataCtrl, &info);
				dataCtrlLock.unlock();
				newDataCtrl = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataDownlink") == 0) {
				std::unique_lock<std::mutex> dataDownlinkLock {dataDownlinkMutex};
				reader->take_next_sample(&dataDownlink, &info);
				dataDownlinkLock.unlock();
				newDataDownlink = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataGps") == 0) {
				std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};
				reader->take_next_sample(&dataGps, &info);
				dataGpsLock.unlock();
				newDataGps = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataPsu") == 0) {
				std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};
				reader->take_next_sample(&dataPsu, &info);
				dataPsuLock.unlock();
				newDataPsu = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {
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
			} else if (reader->get_topicdescription()->get_name().compare("DataWatchdog") == 0) {
				std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
				reader->take_next_sample(&dataWatchdog, &info);
				dataWatchdogLock.unlock();
				newDataWatchdog = true;
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

Log::Log() : participant(nullptr),
             publisher(nullptr),
             subscriber(nullptr),
             topicLog(nullptr),
             writerLog(nullptr),
             typeLog(new DataLogPubSubType()),
             /***PYTHON_GEN_CONSTR*/
             topicAhrs(nullptr),
             readerAhrs(nullptr),
             typeAhrs(new DataAhrsPubSubType()),
             topicAir(nullptr),
             readerAir(nullptr),
             typeAir(new DataAirPubSubType()),
             topicCtrl(nullptr),
             readerCtrl(nullptr),
             typeCtrl(new DataCtrlPubSubType()),
             topicDownlink(nullptr),
             readerDownlink(nullptr),
             typeDownlink(new DataDownlinkPubSubType()),
             topicGps(nullptr),
             readerGps(nullptr),
             typeGps(new DataGpsPubSubType()),
             topicPsu(nullptr),
             readerPsu(nullptr),
             typePsu(new DataPsuPubSubType()),
             topicRaiIn(nullptr),
             readerRaiIn(nullptr),
             typeRaiIn(new DataRaiInPubSubType()),
             topicRaiOut(nullptr),
             readerRaiOut(nullptr),
             typeRaiOut(new DataRaiOutPubSubType()),
             topicSFusion(nullptr),
             readerSFusion(nullptr),
             typeSFusion(new DataSFusionPubSubType()),
             topicWatchdog(nullptr),
             readerWatchdog(nullptr),
             typeWatchdog(new DataWatchdogPubSubType()) {

}

Log::~Log() {

	if (writerLog != nullptr) {
		publisher->delete_datawriter(writerLog);
	}
	if (topicLog != nullptr) {
		participant->delete_topic(topicLog);
	}
	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	/***PYTHON_GEN_DELETE*/
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
	if (readerCtrl != nullptr) {
		subscriber->delete_datareader(readerCtrl);
	}
	if (topicCtrl != nullptr) {
		participant->delete_topic(topicCtrl);
	}
	if (readerDownlink != nullptr) {
		subscriber->delete_datareader(readerDownlink);
	}
	if (topicDownlink != nullptr) {
		participant->delete_topic(topicDownlink);
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

	/***PYTHON_GEN_CLOSE_FILES*/
	ahrsFile.close();
	airFile.close();
	ctrlFile.close();
	downlinkFile.close();
	gpsFile.close();
	psuFile.close();
	raiInFile.close();
	raiOutFile.close();
	sFusionFile.close();
	watchdogFile.close();
}

bool Log::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("LogParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeLog.register_type(participant);
	// Create the publications Topic
	topicLog = participant->create_topic("DataLog", "DataLog", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicLog == nullptr) {
		return false;
	}
	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}
	// Create the DataWriter
	writerLog = publisher->create_datawriter(topicLog, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerLog == nullptr) {
		return false;
	}

	/***PYTHON_GEN_REGISTER_TYPE*/
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
	typeCtrl.register_type(participant);
	// Create the subscriptions Topic
	topicCtrl = participant->create_topic("DataCtrl", "DataCtrl", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicCtrl == nullptr) {
		return false;
	}
	// Register the Type
	typeDownlink.register_type(participant);
	// Create the subscriptions Topic
	topicDownlink = participant->create_topic("DataDownlink", "DataDownlink", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicDownlink == nullptr) {
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

	/***PYTHON_GEN_CREATE_DATAREADER*/
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
	readerCtrl = subscriber->create_datareader(topicCtrl, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerCtrl == nullptr) {
		return false;
	}
	// Create the DataReader
	readerDownlink = subscriber->create_datareader(topicDownlink, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerDownlink == nullptr) {
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
	readerWatchdog = subscriber->create_datareader(topicWatchdog, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerWatchdog == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	time_t t_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm local_tm_now = *localtime(&t_now);

	std::stringstream logdir;
	logdir << "../logs/" << std::flush;

	// Create log directory
	if (!boost::filesystem::exists(logdir.str())) {
		boost::filesystem::create_directory(logdir.str());
	}

	logdir << local_tm_now.tm_year + 1900 << "-"
	       << local_tm_now.tm_mon + 1 << "-"
	       << local_tm_now.tm_mday << "-"
	       << local_tm_now.tm_hour << "-"
	       << local_tm_now.tm_min << "-"
	       << local_tm_now.tm_sec << std::flush;

	// Create sub directory with date and time
	if (!boost::filesystem::exists(logdir.str())) {
		boost::filesystem::create_directory(logdir.str());
	}

	/***PYTHON_GEN_OPEN_FILES*/
	ahrsFile.open(logdir.str() + "/ahrs.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	airFile.open(logdir.str() + "/air.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	ctrlFile.open(logdir.str() + "/ctrl.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	downlinkFile.open(logdir.str() + "/downlink.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	gpsFile.open(logdir.str() + "/gps.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	psuFile.open(logdir.str() + "/psu.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	raiInFile.open(logdir.str() + "/raiIn.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	raiOutFile.open(logdir.str() + "/raiOut.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	sFusionFile.open(logdir.str() + "/sFusion.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);
	watchdogFile.open(logdir.str() + "/watchdog.log", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);

	return true;
}

void Log::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataLogLock {dataLogMutex};
		dataLog.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataLog.alive(true);
		} else {
			dataLog.alive(false);
		}

		writerLog->write(&dataLog);
		dataLogLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Log::run() {

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		/***PYTHON_GEN_WRITE_FILES*/
		if (listener.newDataAhrs) {
			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			// std::cout << "newDataAhrs" << std::endl;
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.time()), sizeof(listener.dataAhrs.time()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.senseTime()), sizeof(listener.dataAhrs.senseTime()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.gyrX()), sizeof(listener.dataAhrs.gyrX()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.gyrY()), sizeof(listener.dataAhrs.gyrY()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.gyrZ()), sizeof(listener.dataAhrs.gyrZ()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.accX()), sizeof(listener.dataAhrs.accX()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.accY()), sizeof(listener.dataAhrs.accY()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.accZ()), sizeof(listener.dataAhrs.accZ()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.magX()), sizeof(listener.dataAhrs.magX()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.magY()), sizeof(listener.dataAhrs.magY()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.magZ()), sizeof(listener.dataAhrs.magZ()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.temp()), sizeof(listener.dataAhrs.temp()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.press()), sizeof(listener.dataAhrs.press()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.phi()), sizeof(listener.dataAhrs.phi()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.the()), sizeof(listener.dataAhrs.the()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.psi()), sizeof(listener.dataAhrs.psi()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.q0()), sizeof(listener.dataAhrs.q0()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.q1()), sizeof(listener.dataAhrs.q1()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.q2()), sizeof(listener.dataAhrs.q2()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.q3()), sizeof(listener.dataAhrs.q3()));
			ahrsFile.write(reinterpret_cast<const char*>(&listener.dataAhrs.alive()), sizeof(listener.dataAhrs.alive()));
			ahrsFile.flush();
			listener.newDataAhrs = false;
			dataAhrsLock.unlock();
		}
		if (listener.newDataAir) {
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			// std::cout << "newDataAir" << std::endl;
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.time()), sizeof(listener.dataAir.time()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.senseTime()), sizeof(listener.dataAir.senseTime()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.dynamicPress()), sizeof(listener.dataAir.dynamicPress()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.velocity()), sizeof(listener.dataAir.velocity()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.baroPress()), sizeof(listener.dataAir.baroPress()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.density()), sizeof(listener.dataAir.density()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.temp()), sizeof(listener.dataAir.temp()));
			airFile.write(reinterpret_cast<const char*>(&listener.dataAir.alive()), sizeof(listener.dataAir.alive()));
			airFile.flush();
			listener.newDataAir = false;
			dataAirLock.unlock();
		}
		if (listener.newDataCtrl) {
			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			// std::cout << "newDataCtrl" << std::endl;
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.time()), sizeof(listener.dataCtrl.time()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.xi()), sizeof(listener.dataCtrl.xi()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.eta()), sizeof(listener.dataCtrl.eta()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.zeta()), sizeof(listener.dataCtrl.zeta()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.etaT()), sizeof(listener.dataCtrl.etaT()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.etaF()), sizeof(listener.dataCtrl.etaF()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.fltMode()), sizeof(listener.dataCtrl.fltMode()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.fltFunc()), sizeof(listener.dataCtrl.fltFunc()));
			ctrlFile.write(reinterpret_cast<const char*>(&listener.dataCtrl.alive()), sizeof(listener.dataCtrl.alive()));
			ctrlFile.flush();
			listener.newDataCtrl = false;
			dataCtrlLock.unlock();
		}
		if (listener.newDataDownlink) {
			std::unique_lock<std::mutex> dataDownlinkLock {listener.dataDownlinkMutex};
			// std::cout << "newDataDownlink" << std::endl;
			downlinkFile.write(reinterpret_cast<const char*>(&listener.dataDownlink.time()), sizeof(listener.dataDownlink.time()));
			downlinkFile.write(reinterpret_cast<const char*>(&listener.dataDownlink.alive()), sizeof(listener.dataDownlink.alive()));
			downlinkFile.flush();
			listener.newDataDownlink = false;
			dataDownlinkLock.unlock();
		}
		if (listener.newDataGps) {
			std::unique_lock<std::mutex> dataGpsLock {listener.dataGpsMutex};
			// std::cout << "newDataGps" << std::endl;
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.time()), sizeof(listener.dataGps.time()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.senseTime()), sizeof(listener.dataGps.senseTime()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.lat()), sizeof(listener.dataGps.lat()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.lon()), sizeof(listener.dataGps.lon()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.alt()), sizeof(listener.dataGps.alt()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.speed()), sizeof(listener.dataGps.speed()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.cog()), sizeof(listener.dataGps.cog()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.dopP()), sizeof(listener.dataGps.dopP()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.dopH()), sizeof(listener.dataGps.dopH()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.dopV()), sizeof(listener.dataGps.dopV()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.sats()), sizeof(listener.dataGps.sats()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.satsInView()), sizeof(listener.dataGps.satsInView()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.fix()), sizeof(listener.dataGps.fix()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.fixMode()), sizeof(listener.dataGps.fixMode()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.second()), sizeof(listener.dataGps.second()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.minute()), sizeof(listener.dataGps.minute()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.hour()), sizeof(listener.dataGps.hour()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.day()), sizeof(listener.dataGps.day()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.month()), sizeof(listener.dataGps.month()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.year()), sizeof(listener.dataGps.year()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.variation()), sizeof(listener.dataGps.variation()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.magX()), sizeof(listener.dataGps.magX()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.magY()), sizeof(listener.dataGps.magY()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.magZ()), sizeof(listener.dataGps.magZ()));
			gpsFile.write(reinterpret_cast<const char*>(&listener.dataGps.alive()), sizeof(listener.dataGps.alive()));
			gpsFile.flush();
			listener.newDataGps = false;
			dataGpsLock.unlock();
		}
		if (listener.newDataPsu) {
			std::unique_lock<std::mutex> dataPsuLock {listener.dataPsuMutex};
			// std::cout << "newDataPsu" << std::endl;
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.time()), sizeof(listener.dataPsu.time()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.senseTime()), sizeof(listener.dataPsu.senseTime()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.mainVolt()), sizeof(listener.dataPsu.mainVolt()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.mainCurr()), sizeof(listener.dataPsu.mainCurr()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.mainPow()), sizeof(listener.dataPsu.mainPow()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.pwrVolt()), sizeof(listener.dataPsu.pwrVolt()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.pwrCurr()), sizeof(listener.dataPsu.pwrCurr()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.pwrPow()), sizeof(listener.dataPsu.pwrPow()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.sysVolt()), sizeof(listener.dataPsu.sysVolt()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.sysCurr()), sizeof(listener.dataPsu.sysCurr()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.sysPow()), sizeof(listener.dataPsu.sysPow()));
			psuFile.write(reinterpret_cast<const char*>(&listener.dataPsu.alive()), sizeof(listener.dataPsu.alive()));
			psuFile.flush();
			listener.newDataPsu = false;
			dataPsuLock.unlock();
		}
		if (listener.newDataRaiIn) {
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			// std::cout << "newDataRaiIn" << std::endl;
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.time()), sizeof(listener.dataRaiIn.time()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.senseTime()), sizeof(listener.dataRaiIn.senseTime()));
			for (unsigned int i=0; i<listener.dataRaiIn.chnl().size(); i++) {
				raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.chnl().at(i)), sizeof(listener.dataRaiIn.chnl().at(i)));
			}
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.roll()), sizeof(listener.dataRaiIn.roll()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.pitch()), sizeof(listener.dataRaiIn.pitch()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.yaw()), sizeof(listener.dataRaiIn.yaw()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.thr()), sizeof(listener.dataRaiIn.thr()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.fltMode()), sizeof(listener.dataRaiIn.fltMode()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.fltFunc()), sizeof(listener.dataRaiIn.fltFunc()));
			raiInFile.write(reinterpret_cast<const char*>(&listener.dataRaiIn.alive()), sizeof(listener.dataRaiIn.alive()));
			raiInFile.flush();
			listener.newDataRaiIn = false;
			dataRaiInLock.unlock();
		}
		if (listener.newDataRaiOut) {
			std::unique_lock<std::mutex> dataRaiOutLock {listener.dataRaiOutMutex};
			// std::cout << "newDataRaiOut" << std::endl;
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.time()), sizeof(listener.dataRaiOut.time()));
			for (unsigned int i=0; i<listener.dataRaiOut.chnl().size(); i++) {
				raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.chnl().at(i)), sizeof(listener.dataRaiOut.chnl().at(i)));
			}
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.roll()), sizeof(listener.dataRaiOut.roll()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.pitch()), sizeof(listener.dataRaiOut.pitch()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.yaw()), sizeof(listener.dataRaiOut.yaw()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.thr()), sizeof(listener.dataRaiOut.thr()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.fltMode()), sizeof(listener.dataRaiOut.fltMode()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.fltFunc()), sizeof(listener.dataRaiOut.fltFunc()));
			raiOutFile.write(reinterpret_cast<const char*>(&listener.dataRaiOut.alive()), sizeof(listener.dataRaiOut.alive()));
			raiOutFile.flush();
			listener.newDataRaiOut = false;
			dataRaiOutLock.unlock();
		}
		if (listener.newDataSFusion) {
			std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
			// std::cout << "newDataSFusion" << std::endl;
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.time()), sizeof(listener.dataSFusion.time()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.gyrX()), sizeof(listener.dataSFusion.gyrX()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.gyrY()), sizeof(listener.dataSFusion.gyrY()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.gyrZ()), sizeof(listener.dataSFusion.gyrZ()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.accX()), sizeof(listener.dataSFusion.accX()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.accY()), sizeof(listener.dataSFusion.accY()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.accZ()), sizeof(listener.dataSFusion.accZ()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.magX()), sizeof(listener.dataSFusion.magX()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.magY()), sizeof(listener.dataSFusion.magY()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.magZ()), sizeof(listener.dataSFusion.magZ()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.temp()), sizeof(listener.dataSFusion.temp()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.press()), sizeof(listener.dataSFusion.press()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.phi()), sizeof(listener.dataSFusion.phi()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.the()), sizeof(listener.dataSFusion.the()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.psi()), sizeof(listener.dataSFusion.psi()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.q0()), sizeof(listener.dataSFusion.q0()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.q1()), sizeof(listener.dataSFusion.q1()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.q2()), sizeof(listener.dataSFusion.q2()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.q3()), sizeof(listener.dataSFusion.q3()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.posN()), sizeof(listener.dataSFusion.posN()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.posE()), sizeof(listener.dataSFusion.posE()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.posD()), sizeof(listener.dataSFusion.posD()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.speedN()), sizeof(listener.dataSFusion.speedN()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.speedE()), sizeof(listener.dataSFusion.speedE()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.speedD()), sizeof(listener.dataSFusion.speedD()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.windN()), sizeof(listener.dataSFusion.windN()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.windE()), sizeof(listener.dataSFusion.windE()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.windD()), sizeof(listener.dataSFusion.windD()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.ssa()), sizeof(listener.dataSFusion.ssa()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.aoa()), sizeof(listener.dataSFusion.aoa()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.gamma()), sizeof(listener.dataSFusion.gamma()));
			sFusionFile.write(reinterpret_cast<const char*>(&listener.dataSFusion.alive()), sizeof(listener.dataSFusion.alive()));
			sFusionFile.flush();
			listener.newDataSFusion = false;
			dataSFusionLock.unlock();
		}
		if (listener.newDataWatchdog) {
			std::unique_lock<std::mutex> dataWatchdogLock {listener.dataWatchdogMutex};
			// std::cout << "newDataWatchdog" << std::endl;
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.time()), sizeof(listener.dataWatchdog.time()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.allAlive()), sizeof(listener.dataWatchdog.allAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.ahrsAlive()), sizeof(listener.dataWatchdog.ahrsAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.airAlive()), sizeof(listener.dataWatchdog.airAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.ctrlAlive()), sizeof(listener.dataWatchdog.ctrlAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.downlinkAlive()), sizeof(listener.dataWatchdog.downlinkAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.gpsAlive()), sizeof(listener.dataWatchdog.gpsAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.logAlive()), sizeof(listener.dataWatchdog.logAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.psuAlive()), sizeof(listener.dataWatchdog.psuAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.raiInAlive()), sizeof(listener.dataWatchdog.raiInAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.raiOutAlive()), sizeof(listener.dataWatchdog.raiOutAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.sFusionAlive()), sizeof(listener.dataWatchdog.sFusionAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.uplinkAlive()), sizeof(listener.dataWatchdog.uplinkAlive()));
			watchdogFile.write(reinterpret_cast<const char*>(&listener.dataWatchdog.alive()), sizeof(listener.dataWatchdog.alive()));
			watchdogFile.flush();
			listener.newDataWatchdog = false;
			dataWatchdogLock.unlock();
		}

		// reset the alive timer
		aliveTime = timer.getSysTime();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}
}

void Log::print() {

	std::cout << "--- " << this->name << " " << dataLog.time() << " ---" << std::endl;

	std::cout << "alive   " << dataLog.alive() << std::endl;

}
