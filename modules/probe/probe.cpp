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

	// while (reader->read_next_sample(&data, &info) == ReturnCode_t::RETCODE_OK) {
		// if (info.instance_state == eprosima::fastdds::dds::ALIVE && info.valid_data) {
			// if (reader->get_topicdescription()->get_name().compare("DataRaiIn") == 0) {
				// 
				// reader->take_next_sample(&dataRaiIn, &info);
				// 
				// newDataRaiIn = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataRaiOut") == 0) {
				// std::unique_lock<std::mutex> dataRaiOutLock {dataRaiOutMutex};
				// reader->take_next_sample(&dataRaiOut, &info);
				// dataRaiOutLock.unlock();
				// newDataRaiOut = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataSFusion") == 0) {
				// std::unique_lock<std::mutex> dataSFusionLock {dataSFusionMutex};
				// reader->take_next_sample(&dataSFusion, &info);
				// dataSFusionLock.unlock();
				// newDataSFusion = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataAhrs") == 0) {
				// std::unique_lock<std::mutex> dataAhrsLock {dataAhrsMutex};
				// reader->take_next_sample(&dataAhrs, &info);
				// dataAhrsLock.unlock();
				// newDataAhrs = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataAir") == 0) {
				// std::unique_lock<std::mutex> dataAirLock {dataAirMutex};
				// reader->take_next_sample(&dataAir, &info);
				// dataAirLock.unlock();
				// newDataAir = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataGps") == 0) {
				// std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};
				// reader->take_next_sample(&dataGps, &info);
				// dataGpsLock.unlock();
				// newDataGps = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataPsu") == 0) {
				// std::unique_lock<std::mutex> dataPsuLock {dataPsuMutex};
				// reader->take_next_sample(&dataPsu, &info);
				// dataPsuLock.unlock();
				// newDataPsu = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataCtrl") == 0) {
				// std::unique_lock<std::mutex> dataCtrlLock {dataCtrlMutex};
				// reader->take_next_sample(&dataCtrl, &info);
				// dataCtrlLock.unlock();
				// newDataCtrl = true;
			// } else if (reader->get_topicdescription()->get_name().compare("DataWatchdog") == 0) {
				// std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
				// reader->take_next_sample(&dataWatchdog, &info);
				// dataWatchdogLock.unlock();
				// newDataWatchdog = true;
			// } else {
				// reader->take_next_sample(&data, &info);
			// }
		// } else {
			// reader->take_next_sample(&data, &info);
		// }
	// }
}

Probe::Probe(std::string to_listen) : participant(nullptr),
                       subscriber(nullptr),
                       topic_probe(nullptr),
                       reader_probe(nullptr)
{

	_topicname = to_listen;
	_data_topic_name.append(to_listen);
	
	if(_topicname.compare("RaiIn") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataRaiInPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("RaiOut") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataRaiOutPubSubType());
		type_probe.insert({_topicname, probe});
		
	}
	else if(_topicname.compare("SFusion") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataSFusionPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Ahrs") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataAhrsPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Air") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataAirPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Gps") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataGpsPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Psu") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataPsuPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Ctrl") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataCtrlPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Watchdog") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataWatchdogPubSubType());
		type_probe.insert({_topicname, probe});
	}
	else if(_topicname.compare("Downlink") == 0) {
		eprosima::fastdds::dds::TypeSupport probe(new DataRaiOutPubSubType());
		type_probe.insert({_topicname, probe});
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
	type_probe[_topicname].register_type(participant);

	// Create the Subscriber
	subscriber = participant->create_subscriber(eprosima::fastdds::dds::SUBSCRIBER_QOS_DEFAULT, nullptr);
	if (subscriber == nullptr) {
		return false;
	}
	// Create the subscriptions Topic
	topic_probe = participant->create_topic(_data_topic_name, _data_topic_name, eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topic_probe == nullptr) {
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
		    
			
			print_RaiIn();
			_run = false;
			listener.newDataRaiIn = false;
			
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

			std::cout << "reached..." << std::endl;			
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
	PRINT_DATA("CH 01",listener.dataRaiIn.chnl().at(0))
	PRINT_DATA("CH 02",listener.dataRaiIn.chnl().at(1))
	PRINT_DATA("CH 03",listener.dataRaiIn.chnl().at(2))
	PRINT_DATA("CH 04",listener.dataRaiIn.chnl().at(3))
	PRINT_DATA("CH 05",listener.dataRaiIn.chnl().at(4))
	PRINT_DATA("CH 06",listener.dataRaiIn.chnl().at(5))
	PRINT_DATA("CH 07",listener.dataRaiIn.chnl().at(6))
	PRINT_DATA("CH 08",listener.dataRaiIn.chnl().at(7))
	PRINT_DATA("CH 09",listener.dataRaiIn.chnl().at(8))
	PRINT_DATA("CH 10",listener.dataRaiIn.chnl().at(9))
	PRINT_DATA("CH 11",listener.dataRaiIn.chnl().at(10))
	PRINT_DATA("CH 12",listener.dataRaiIn.chnl().at(11))
	PRINT_DATA("ROLL_SETPOINT",listener.dataRaiIn.roll_setpoint())
	PRINT_DATA("PITCH_SETPOINT",listener.dataRaiIn.pitch_setpoint())
	PRINT_DATA("YAW_SETPOINT",listener.dataRaiIn.yaw_setpoint())
	PRINT_DATA("FLIGHT_MODE",listener.dataRaiIn.flight_mode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataRaiIn.flight_fct())
	PRINT_DATA("FLIGHT_ALIVE",listener.dataRaiIn.alive())

}

void Probe::print_RaiOut() 
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataRaiOut.time())
	PRINT_DATA("SENSE_TIME",listener.dataRaiOut.senseTime())
	PRINT_DATA("CH 01",listener.dataRaiOut.chnl().at(0))
	PRINT_DATA("CH 02",listener.dataRaiOut.chnl().at(1))
	PRINT_DATA("CH 03",listener.dataRaiOut.chnl().at(2))
	PRINT_DATA("CH 04",listener.dataRaiOut.chnl().at(3))
	PRINT_DATA("CH 05",listener.dataRaiOut.chnl().at(4))
	PRINT_DATA("CH 06",listener.dataRaiOut.chnl().at(5))
	PRINT_DATA("CH 07",listener.dataRaiOut.chnl().at(6))
	PRINT_DATA("CH 08",listener.dataRaiOut.chnl().at(7))
	PRINT_DATA("CH 09",listener.dataRaiOut.chnl().at(8))
	PRINT_DATA("CH 10",listener.dataRaiOut.chnl().at(9))
	PRINT_DATA("CH 11",listener.dataRaiOut.chnl().at(10))
	PRINT_DATA("CH 12",listener.dataRaiOut.chnl().at(11))
	PRINT_DATA("XI_SETPOINT",listener.dataRaiOut.xi_setpoint())
	PRINT_DATA("ETA_SETPOINT",listener.dataRaiOut.eta_setpoint())
	PRINT_DATA("ZETA_SETPOINT",listener.dataRaiOut.zeta_setpoint())
	PRINT_DATA("THROTTLE_SETPOINT",listener.dataRaiOut.throttle_setpoint())
	PRINT_DATA("FLAPS_SETPOINT",listener.dataRaiOut.flaps_setpoint())
	PRINT_DATA("FLIGHT_MODE",listener.dataRaiOut.flight_mode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataRaiOut.flight_fct())
	PRINT_DATA("FLIGHT_ALIVE",listener.dataRaiOut.alive())
}

void Probe::print_SFusion()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataSFusion.time())
	PRINT_DATA("GYR_X",listener.dataSFusion.p())
	PRINT_DATA("GYR_Y",listener.dataSFusion.q())
	PRINT_DATA("GYR_Z",listener.dataSFusion.r())
	PRINT_DATA("ACC_X",listener.dataSFusion.a_x())
	PRINT_DATA("ACC_Y",listener.dataSFusion.a_y())
	PRINT_DATA("ACC_Z",listener.dataSFusion.a_z())
	PRINT_DATA("BAROMETRIC_PRESSURE",listener.dataSFusion.barometric_pressure())
	PRINT_DATA("HEIGHT",listener.dataSFusion.height())
	PRINT_DATA("HEIGHT_RATE",listener.dataSFusion.height_rate())
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
	PRINT_DATA("TEMP",listener.dataAhrs.temperature())
	PRINT_DATA("PRESS",listener.dataAhrs.barometric_pressure())
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
	PRINT_DATA("DYN_PRESSURE",listener.dataAir.dynamic_pressure())
	PRINT_DATA("TRUE_AIRSPEED",listener.dataAir.true_airspeed())
	PRINT_DATA("INDICATED_AIRSPEED",listener.dataAir.indicated_airspeed())
	PRINT_DATA("BARO_PRESSURE",listener.dataAir.barometric_pressure())
	PRINT_DATA("BARO_HEIGHT",listener.dataAir.barometric_height())
	PRINT_DATA("DENSITY",listener.dataAir.density())
	PRINT_DATA("TEMPERATURE",listener.dataAir.temperature())
	PRINT_DATA("ALIVE",listener.dataAir.alive())
}

void Probe::print_Gps()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataGps.time())
	PRINT_DATA("SENSE_TIME",listener.dataGps.senseTime())
	PRINT_DATA("LAT",listener.dataGps.latitude())
	PRINT_DATA("LON",listener.dataGps.longitude())
	PRINT_DATA("ALT",listener.dataGps.alt_msl())
	PRINT_DATA("SPEED",listener.dataGps.groundspeed())
	PRINT_DATA("COG",listener.dataGps.course_over_ground())
	PRINT_DATA("DOP_P",listener.dataGps.dop_position())
	PRINT_DATA("DOP_H",listener.dataGps.dop_height())
	PRINT_DATA("DOP_V",listener.dataGps.dop_velocity())
	PRINT_DATA("SATS",listener.dataGps.sats())
	PRINT_DATA("SATS_IN_VIEW",listener.dataGps.sats_in_view())
	PRINT_DATA("FIX",listener.dataGps.fix())
	PRINT_DATA("FIX_MODE",listener.dataGps.fix_mode())
	PRINT_DATA("SECOND",listener.dataGps.second())
	PRINT_DATA("MINUTE",listener.dataGps.minute())
	PRINT_DATA("HOUR",listener.dataGps.hour())
	PRINT_DATA("DAY",listener.dataGps.day())
	PRINT_DATA("MONTH",listener.dataGps.month())
	PRINT_DATA("YEAR",listener.dataGps.year())
	PRINT_DATA("VARIATON",listener.dataGps.variation())
	PRINT_DATA("MAG_X",listener.dataGps.magX())
	PRINT_DATA("MAG_Y",listener.dataGps.magY())
	PRINT_DATA("MAG_Z",listener.dataGps.magZ())
	PRINT_DATA("ALIVE",listener.dataGps.alive())

}

void Probe::print_Ctrl()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataCtrl.time())
	PRINT_DATA("XI",listener.dataCtrl.xi_setpoint())
	PRINT_DATA("ETA",listener.dataCtrl.eta_setpoint())
	PRINT_DATA("ZETA",listener.dataCtrl.zeta_setpoint())
	PRINT_DATA("THROTTLE",listener.dataCtrl.throttle_setpoint())
	PRINT_DATA("FLAPS",listener.dataCtrl.flaps_setpoint())
	PRINT_DATA("ROLL",listener.dataCtrl.roll_setpoint())
	PRINT_DATA("PITCH",listener.dataCtrl.pitch_setpoint())
	PRINT_DATA("YAW",listener.dataCtrl.yaw_setpoint())
	PRINT_DATA("TAS",listener.dataCtrl.tas_setpoint())
	PRINT_DATA("HEIGHT",listener.dataCtrl.hgt_setpoint())
	PRINT_DATA("ROLL_RATE",listener.dataCtrl.roll_rate_setpoint())
	PRINT_DATA("PITCH_RATE",listener.dataCtrl.pitch_rate_setpoint())
	PRINT_DATA("YAW_RATE",listener.dataCtrl.yaw_rate_setpoint())
	PRINT_DATA("TAS_RATE",listener.dataCtrl.tas_rate_setpoint())
	PRINT_DATA("HEIGHT_RATE",listener.dataCtrl.hgt_rate_setpoint())
	PRINT_DATA("FLIGHT_MODE",listener.dataCtrl.flight_mode())
	PRINT_DATA("FLIGHT_FUNC",listener.dataCtrl.flight_fct())
	PRINT_DATA("ALIVE",listener.dataCtrl.alive())
}

void Probe::print_Psu()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataPsu.time())
	PRINT_DATA("SENSETIME",listener.dataPsu.senseTime())
	PRINT_DATA("MAIN_VOLT",listener.dataPsu.main_volt())
	PRINT_DATA("MAIN_CURR",listener.dataPsu.main_curr())
	PRINT_DATA("MAIN_POW",listener.dataPsu.main_pwr())
	PRINT_DATA("PWR_VOLT",listener.dataPsu.pwr_volt())
	PRINT_DATA("PWR_CURR",listener.dataPsu.pwr_curr())
	PRINT_DATA("PWR_POW",listener.dataPsu.pwr_pwr())
	PRINT_DATA("SYS_VOLT",listener.dataPsu.sys_volt())
	PRINT_DATA("SYS_CURR",listener.dataPsu.sys_curr())
	PRINT_DATA("SYS_POW",listener.dataPsu.sys_pwr())
	PRINT_DATA("ALIVE",listener.dataPsu.alive())

}

void Probe::print_Watchdog()
{
	std::cout << "Data of " << _topicname << std::endl;
	PRINT_DATA("TIME",listener.dataWatchdog.time())
	PRINT_DATA("ALL_ALIVE",listener.dataWatchdog.allAlive())
	PRINT_DATA("AHRS_ALIVE",listener.dataWatchdog.ahrsAlive())
	PRINT_DATA("AIR_ALIVE",listener.dataWatchdog.airAlive())
	PRINT_DATA("CTRL_ALIVE",listener.dataWatchdog.ctrlAlive())
	PRINT_DATA("DOWNLINK_ALIVE",listener.dataWatchdog.downlinkAlive())
	PRINT_DATA("GPS_ALIVE",listener.dataWatchdog.gpsAlive())
	PRINT_DATA("LOG_ALIVE",listener.dataWatchdog.logAlive())
	PRINT_DATA("PSU_ALIVE",listener.dataWatchdog.psuAlive())
	PRINT_DATA("RAI_IN_ALIVE",listener.dataWatchdog.raiInAlive())
	PRINT_DATA("RAI_OUT_ALIVE",listener.dataWatchdog.raiOutAlive())
	PRINT_DATA("SFUSION_ALIVE",listener.dataWatchdog.sFusionAlive())
	PRINT_DATA("UPLINK_ALIVE",listener.dataWatchdog.uplinkAlive())
	PRINT_DATA("WATCHDOG_ALIVE",listener.dataWatchdog.alive())
	
}