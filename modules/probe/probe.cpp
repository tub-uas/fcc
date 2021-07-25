#include "probe.h"

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
			} else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
				std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
				reader->take_next_sample(&dataCtrl, &info);
				dataCtrlLock.unlock();
				newDataCtrl = true;
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
}

Probe::Probe(std::string to_listen) : participant(nullptr),
                       subscriber(nullptr),
                       topic_probe(nullptr),
                       reader_probe(nullptr),
{

	_topicname = to_listen;
	_data_topic_name.append(to_listen);
	if(_topicname.compare("RaiIn") == 0) {
		type_probe = new DataRaiInPubSubType();
	}
	else if(_topicname.compare("RaiOut") == 0) {
		type_probe = new DataRaiOutPubSubType();
	}
	else if(_topicname.compare("SFusion") == 0) {
		type_probe = new DataSFusionPubSubType();
	}
	else if(_topicname.compare("Ahrs") == 0) {
		type_probe = new DataAhrsPubSubType();
	}
	else if(_topicname.compare("Air") == 0) {
		type_probe = new DataAirPubSubType();
	}
	else if(_topicname.compare("Gps") == 0) {
		type_probe = new DataGpsPubSubType();
	}
	else if(_topicname.compare("Psu") == 0) {
		type_probe = new DataPsuPubSubType();
	}
	else if(_topicname.compare("Watchdog") == 0) {
		type_probe = new DataWatchdogPubSubType();
	}
	else if(_topicname.compare("Downlink") == 0) {
		type_probe = new DataDownlinkPubSubType();
	}
	else if(_topicname.compare("Log") == 0) {
		type_probe = new DataLogPubSubType();
	}

}

Probe::~Probe() {

	if(reader_probe != nullptr) {
		subscriber->delete_datareader(reader_probe);
	} 

	if(topic_probe != nullptr) {
		participant->delete_topic(topic_probe);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);
}

bool Probe::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("ProbeParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	type_probe.register_type(participant);
	// Create the subscriptions Topic
	topic_probe = participant->create_topic(_data_topic_name, _data_topic_name, eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topic_probe == nullptr) {
		return false;
	}
	
	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}

	// Create the DataReader
	reader_probe = subscriber->create_datareader(topic_probe, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (reader_probe == nullptr) {
		return false;
	}

	return true;
}

void Probe::run() {

	
	while (_run) {
		

		if (listener.newDataRaiIn) {
		    
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			print_RaiIn();
			_run = false;
			listener.newDataRaiIn = false;
			dataRaiInLock.unlock();
			break;
		}

		if (listener.newDataRaiOut) {

			std::unique_lock<std::mutex> dataRaiOutLock {listener.dataRaiOutMutex};
			print_RaiOut();
			_run = false;
			listener.newDataRaiOut = false;
			dataRaiOutLock.unlock();
		}

		if (listener.newDataSFusion) {

			
			std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
			
			print_SFusion();
			_run = false;

			listener.newDataSFusion = false;
			dataSFusionLock.unlock();
		}

		if (listener.newDataAhrs) {
			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			
			print_Ahrs();
			_run = false;
			
			listener.newDataAhrs = false;
			dataAhrsLock.unlock();
		}

		if (listener.newDataAir) {
		    
			
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			
			print_Air();
			_run = false;

			listener.newDataAir = false;
			dataAirLock.unlock();
		}

		if (listener.newDataGps) {
			std::unique_lock<std::mutex> dataGpsLock {listener.dataGpsMutex};
			
			print_Gps();
			_run = false;

			listener.newDataGps = false;
			dataGpsLock.unlock();
		}

		if (listener.newDataCtrl) {
		    
			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			

			print_Ctrl();
			_run = false;

			listener.newDataCtrl = false;
			dataCtrlLock.unlock();
		}

		if (listener.newDataPsu) {

			std::unique_lock<std::mutex> dataPsuLock {listener.dataPsuMutex};
			
			print_Psu();
			_run = false;

			listener.newDataPsu = false;
			dataPsuLock.unlock();
		}

		if (listener.newDataWatchdog) {
			
			std::unique_lock<std::mutex> dataWatchdogLock {listener.dataWatchdogMutex};
			
			print_Watchdog();
			_run = false;

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

void Probe::print_RaiIn()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataRaiIn.time())
	PRINT_DATA("SENSE_TIME",listener.dataRaiIn.senseTime())
	PRINT_DATA("CH 01",listener.dataRaiIn.chnk().at(0))
	PRINT_DATA("CH 02",listener.dataRaiIn.chnk().at(1))
	PRINT_DATA("CH 03",listener.dataRaiIn.chnk().at(2))
	PRINT_DATA("CH 04",listener.dataRaiIn.chnk().at(3))
	PRINT_DATA("CH 05",listener.dataRaiIn.chnk().at(4))
	PRINT_DATA("CH 06",listener.dataRaiIn.chnk().at(5))
	PRINT_DATA("CH 07",listener.dataRaiIn.chnk().at(6))
	PRINT_DATA("CH 08",listener.dataRaiIn.chnk().at(7))
	PRINT_DATA("CH 09",listener.dataRaiIn.chnk().at(8))
	PRINT_DATA("CH 10",listener.dataRaiIn.chnk().at(9))
	PRINT_DATA("CH 11",listener.dataRaiIn.chnk().at(10))
	PRINT_DATA("CH 12",listener.dataRaiIn.chnk().at(11))
	PRINT_DATA("ROLL",listener.dataRaiIn.roll())
	PRINT_DATA("PITCH",listener.dataRaiIn.pitch())
	PRINT_DATA("YAW",listener.dataRaiIn.yaw())
	PRINT_DATA("FLIGHT_MODE",listener.dataRaiIn.fltMode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataRaiIn.fltfunc())
	PRINT_DATA("FLIGHT_ALIVE",listener.dataRaiIn.alive())

}

void Probe::print_RaiOut() 
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataRaiOut.time())
	PRINT_DATA("SENSE_TIME",listener.dataRaiOut.senseTime())
	PRINT_DATA("CH 01",listener.dataRaiOut.chnk().at(0))
	PRINT_DATA("CH 02",listener.dataRaiOut.chnk().at(1))
	PRINT_DATA("CH 03",listener.dataRaiOut.chnk().at(2))
	PRINT_DATA("CH 04",listener.dataRaiOut.chnk().at(3))
	PRINT_DATA("CH 05",listener.dataRaiOut.chnk().at(4))
	PRINT_DATA("CH 06",listener.dataRaiOut.chnk().at(5))
	PRINT_DATA("CH 07",listener.dataRaiOut.chnk().at(6))
	PRINT_DATA("CH 08",listener.dataRaiOut.chnk().at(7))
	PRINT_DATA("CH 09",listener.dataRaiOut.chnk().at(8))
	PRINT_DATA("CH 10",listener.dataRaiOut.chnk().at(9))
	PRINT_DATA("CH 11",listener.dataRaiOut.chnk().at(10))
	PRINT_DATA("CH 12",listener.dataRaiOut.chnk().at(11))
	PRINT_DATA("ROLL",listener.dataRaiOut.roll())
	PRINT_DATA("PITCH",listener.dataRaiOut.pitch())
	PRINT_DATA("YAW",listener.dataRaiOut.yaw())
	PRINT_DATA("FLIGHT_MODE",listener.dataRaiOut.fltMode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataRaiOut.fltfunc())
	PRINT_DATA("FLIGHT_ALIVE",listener.dataRaiOut.alive())
}

void Probe::print_SFusion()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataSFusion.time())
	PRINT_DATA("GYR_X",listener.dataSFusion.gyrX())
	PRINT_DATA("GYR_Y",listener.dataSFusion.gyrY())
	PRINT_DATA("GYR_Z",listener.dataSFusion.gyrZ())
	PRINT_DATA("ACC_X",listener.dataSFusion.accX())
	PRINT_DATA("ACC_Y",listener.dataSFusion.accY())
	PRINT_DATA("ACC_Z",listener.dataSFusion.accZ())
	PRINT_DATA("MAG_X",listener.dataSFusion.magX())
	PRINT_DATA("MAG_Y",listener.dataSFusion.magY())
	PRINT_DATA("MAG_Z",listener.dataSFusion.magZ())
	PRINT_DATA("TEMPERATURE",listener.dataSFusion.temp())
	PRINT_DATA("BAROMETRIC_PRESSURE",listener.dataSFusion.press())
	PRINT_DATA("PHI",listener.dataSFusion.phi())
	PRINT_DATA("THETA",listener.dataSFusion.the())
	PRINT_DATA("PSI",listener.dataSFusion.psi())
	PRINT_DATA("POSITION_NORTH",listener.dataSFusion.posN())
	PRINT_DATA("POSITION_EAST",listener.dataSFusion.posE())
	PRINT_DATA("POSITION_DOWN",listener.dataSFusion.posD())
	PRINT_DATA("VELOCITY_NORTH",listener.dataSFusion.speedN())
	PRINT_DATA("VELOCITY_EAST",listener.dataSFusion.speedE())
	PRINT_DATA("VELOCITY_DOWN",listener.dataSFusion.speedD())
	PRINT_DATA("WIND_NORTH",listener.dataSFusion.windN())
	PRINT_DATA("WIND_EAST",listener.dataSFusion.windE())
	PRINT_DATA("WIND_DOWN",listener.dataSFusion.windD())
	PRINT_DATA("SIDESLIP_ANGLE",listener.dataSFusion.ssa())
	PRINT_DATA("ANGLE_OF_ATTACK",listener.dataSFusion.aoa())
	PRINT_DATA("FLIGHT_PATH_ANGLE",listener.dataSFusion.gamma())
	PRINT_DATA("ALIVE",listener.dataSFusion.alive())

}

void Probe::print_Ahrs()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataAhrs.time())
	PRINT_DATA("SENSE_TIME",listener.dataAhrs.senseTime())
	PRINT_DATA("GYR_X",listener.dataAhrs.gyrX())
	PRINT_DATA("GYR_Y",listener.dataAhrs.gyrY())
	PRINT_DATA("GYR_Z",listener.dataAhrs.gyrZ())
	PRINT_DATA("ACC_X",listener.dataAhrs.accX())
	PRINT_DATA("ACC_Y",listener.dataAhrs.accY())
	PRINT_DATA("ACC_Z",listener.dataAhrs.accZ())
	PRINT_DATA("MAG_X",listener.dataAhrs.magX())
	PRINT_DATA("MAG_Y",listener.dataAhrs.magY())
	PRINT_DATA("MAG_Z",listener.dataAhrs.magZ())
	PRINT_DATA("TEMP",listener.dataAhrs.temp())
	PRINT_DATA("PRESS",listener.dataAhrs.press())
	PRINT_DATA("PHI",listener.dataAhrs.phi())
	PRINT_DATA("THETA",listener.dataAhrs.the())
	PRINT_DATA("PSI",listener.dataAhrs.psi())
	PRINT_DATA("ALIVE",listener.dataAhrs.alive())
}

void Probe::print_Air()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataAir.time())
	PRINT_DATA("SENSE_TIME",listener.dataAir.senseTime())
	PRINT_DATA("DYN_PRESSURE",listener.dataAir.dynamicPress())
	PRINT_DATA("TRUE_AIRSPEED",listener.dataAir.velocity())
	PRINT_DATA("BARO_PRESSURE",listener.dataAir.baroPress())
	PRINT_DATA("DENSITY",listener.dataAir.density())
	PRINT_DATA("TEMPERATURE",listener.dataAir.temp())
	PRINT_DATA("ALIVE",listener.dataAir.alive())
}

void Probe::print_Gps()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataGps.time())
	PRINT_DATA("SENSE_TIME",listener.dataGps.senseTime())
	PRINT_DATA("LAT",listener.dataGps.lat())
	PRINT_DATA("LON",listener.dataGps.lon())
	PRINT_DATA("ALT",listener.dataGps.alt())
	PRINT_DATA("SPEED",listener.dataGps.speed())
	PRINT_DATA("COG",listener.dataGps.cog())
	PRINT_DATA("DOP_P",listener.dataGps.dopP())
	PRINT_DATA("DOP_H",listener.dataGps.dopH())
	PRINT_DATA("DOP_V",listener.dataGps.dopV())
	PRINT_DATA("SATS",listener.dataGps.sats())
	PRINT_DATA("SATS_IN_VIEW",listener.dataGps.satsInView())
	PRINT_DATA("FIX",listener.dataGps.fix())
	PRINT_DATA("FIX_MODE",listener.dataGps.fixMode())
	PRINT_DATA("SECOND",listener.dataGps.second())
	PRINT_DATA("MINUTE",listener.dataGps.minute())
	PRINT_DATA("HOUR",listener.dataGps.hour())
	PRINT_DATA("DAY",listener.dataGps.day())
	PRINT_DATA("MONTH",listener.dataGps.month())
	PRINT_DATA("YEAR",listener.dataGps.year())
	PRINT_DATA("VARIATON",listener.dataGps.variation())
	PRINT_DATA("MAG_X",listener.dataGps.mag_x())
	PRINT_DATA("MAG_Y",listener.dataGps.mag_y())
	PRINT_DATA("MAG_Z",listener.dataGps.mag_z())
	PRINT_DATA("ALIVE",listener.dataGps.alive())

}

void Probe::print_Ctrl()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataCtrl.time())
	PRINT_DATA("XI",listener.dataCtrl.xi())
	PRINT_DATA("ETA",listener.dataCtrl.eta())
	PRINT_DATA("ZETA",listener.dataCtrl.zeta())
	PRINT_DATA("ETA_T",listener.dataCtrl.etaT())
	PRINT_DATA("ETA_F",listener.dataCtrl.etaF())
	PRINT_DATA("FLIGHT_MODE",listener.dataCtrl.fltmode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataCtrl.fltfunc())
	PRINT_DATA("ALIVE",listener.dataCtrl.alive())
}

void Probe::print_Psu()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataPsu.time())
	PRINT_DATA("SENSETIME",listener.dataPsu.senseTime())
	PRINT_DATA("MAIN_VOLT",listener.dataPsu.mainVolt())
	PRINT_DATA("MAIN_CURR",listener.dataPsu.mainCurr())
	PRINT_DATA("MAIN_POW",listener.dataPsu.mainPow())
	PRINT_DATA("PWR_VOLT",listener.dataPsu.pwrVolt())
	PRINT_DATA("PWR_CURR",listener.dataPsu.pwrCurr())
	PRINT_DATA("PWR_POW",listener.dataPsu.pwrPow())
	PRINT_DATA("SYS_VOLT",listener.dataPsu.sysVolt())
	PRINT_DATA("SYS_CURR",listener.dataPsu.sysCurr())
	PRINT_DATA("SYS_POW",listener.dataPsu.sysPow())
	PRINT_DATA("ALIVE",listener.dataPsu.alive())

}

void Probe::print_Watchdog()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataWatchdog.time())
	PRINT_DATA("ALL_ALIVE",listener.allAlive())
	PRINT_DATA("AHRS_ALIVE",listener.ahrsAlive())
	PRINT_DATA("AIR_ALIVE",listener.airAlive())
	PRINT_DATA("CTRL_ALIVE",listener.ctrlAlive())
	PRINT_DATA("DOWNLINK_ALIVE",listener.downlinkAlive())
	PRINT_DATA("GPS_ALIVE",listener.dataWatchdog.gpsAlive())
	PRINT_DATA("LOG_ALIVE",listener.dataWatchdog.logAlive())
	PRINT_DATA("PSU_ALIVE",listener.dataWatchdog.psuAlive())
	PRINT_DATA("RAI_IN_ALIVE",listener.dataWatchdog.raiInAlive())
	PRINT_DATA("RAI_OUT_ALIVE",listener.dataWatchdog.raiOutAlive())
	PRINT_DATA("SFUSION_ALIVE",listener.dataWatchdog.sFusionAlive())
	PRINT_DATA("UPLINK_ALIVE",listener.dataWatchdog.uplinkAlive())
	PRINT_DATA("WATCHDOG_ALIVE",listener.dataWatchdog.alive())
	
}