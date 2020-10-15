#include "watchdog.h"

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
			} else if (reader->get_topicdescription()->get_name().compare("DataDownlink") == 0) {
				std::unique_lock<std::mutex> dataDownlinkLock {dataDownlinkMutex};
				reader->take_next_sample(&dataDownlink, &info);
				dataDownlinkLock.unlock();
				newDataDownlink = true;
			} else if (reader->get_topicdescription()->get_name().compare("DataLog") == 0) {
				std::unique_lock<std::mutex> dataLogLock {dataLogMutex};
				reader->take_next_sample(&dataLog, &info);
				dataLogLock.unlock();
				newDataLog = true;
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

Watchdog::Watchdog() : participant(nullptr),
                       publisher(nullptr),
                       subscriber(nullptr),
                       topicWatchdog(nullptr),
                       writerWatchdog(nullptr),
                       typeWatchdog(new DataWatchdogPubSubType()),
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
                       typeCtrl(new DataCtrlPubSubType()),
                       topicDownlink(nullptr),
                       readerDownlink(nullptr),
                       typeDownlink(new DataDownlinkPubSubType()),
                       topicLog(nullptr),
                       readerLog(nullptr),
                       typeLog(new DataLogPubSubType()) {

}

Watchdog::~Watchdog() {

	if (writerWatchdog != nullptr) {
		publisher->delete_datawriter(writerWatchdog);
	}
	if (topicWatchdog != nullptr) {
		participant->delete_topic(topicWatchdog);
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
	if (readerDownlink != nullptr) {
		subscriber->delete_datareader(readerDownlink);
	}
	if (topicDownlink != nullptr) {
		participant->delete_topic(topicDownlink);
	}
	if (readerLog != nullptr) {
		subscriber->delete_datareader(readerLog);
	}
	if (topicLog != nullptr) {
		participant->delete_topic(topicLog);
	}

	if (subscriber != nullptr) {
		participant->delete_subscriber(subscriber);
	}

	drv_led_set_green(0);
	drv_led_set_yellow(0);

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);
}

bool Watchdog::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("WatchdogParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeWatchdog.register_type(participant);
	// Create the publications Topic
	topicWatchdog = participant->create_topic("DataWatchdog", "DataWatchdog", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicWatchdog == nullptr) {
		return false;
	}
	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}
	// Create the DataWriter
	writerWatchdog = publisher->create_datawriter(topicWatchdog, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerWatchdog == nullptr) {
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
	// Register the Type
	typeDownlink.register_type(participant);
	// Create the subscriptions Topic
	topicDownlink = participant->create_topic("DataDownlink", "DataDownlink", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicDownlink == nullptr) {
		return false;
	}
	// Register the Type
	typeLog.register_type(participant);
	// Create the subscriptions Topic
	topicLog = participant->create_topic("DataLog", "DataLog", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicLog == nullptr) {
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
	// Create the DataReader
	readerDownlink = subscriber->create_datareader(topicDownlink, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerDownlink == nullptr) {
		return false;
	}
	// Create the DataReader
	readerLog = subscriber->create_datareader(topicLog, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);
	if (readerLog == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (drv_led_init() != 0) {
		return false;
	}

	greenLed = false;
	yellowLed = false;

	return true;
}

void Watchdog::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
		dataWatchdog.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataWatchdog.alive(true);
		} else {
			dataWatchdog.alive(false);
		}

		writerWatchdog->write(&dataWatchdog);
		dataWatchdogLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Watchdog::run() {

	// watchdog is running
	// yellowLed = true;

	const double timeout = 0.1;
	static double dataRaiInTime = timer.getSysTimeS();
	static double dataRaiOutTime = timer.getSysTimeS();
	static double dataSFusionTime = timer.getSysTimeS();
	static double dataAhrsTime = timer.getSysTimeS();
	static double dataAirTime = timer.getSysTimeS();
	// static double dataGpsTime = timer.getSysTimeS();
	static double dataPsuTime = timer.getSysTimeS();
	static double dataCtrlTime = timer.getSysTimeS();
	static double dataDownlinkTime = timer.getSysTimeS();
	static double dataLogTime = timer.getSysTimeS();
	static double okPrintTime = timer.getSysTimeS();

	while (1) {
		// std::cout << this->name << " run" << std::endl;

		if (listener.newDataRaiIn) {
			std::unique_lock<std::mutex> dataRaiInLock {listener.dataRaiInMutex};
			// std::cout << "newDataRaiIn" << std::endl;

			if (listener.dataRaiIn.alive()) {
				// std::cout << "Reset dataRaiInTime" << std::endl;
				dataRaiInTime = timer.getSysTimeS();
			}

			listener.newDataRaiIn = false;
			dataRaiInLock.unlock();
		}

		if (listener.newDataRaiOut) {
			std::unique_lock<std::mutex> dataRaiOutLock {listener.dataRaiOutMutex};
			// std::cout << "newDataRaiOut" << std::endl;

			if (listener.dataRaiOut.alive()) {
				// std::cout << "Reset dataRaioutTime" << std::endl;
				dataRaiOutTime = timer.getSysTimeS();
			}

			listener.newDataRaiOut = false;
			dataRaiOutLock.unlock();
		}

		if (listener.newDataSFusion) {
			std::unique_lock<std::mutex> dataSFusionLock {listener.dataSFusionMutex};
			// std::cout << "newDataSFusion" << std::endl;

			if (listener.dataSFusion.alive()) {
				// std::cout << "Reset dataSFusionTime" << std::endl;
				dataSFusionTime = timer.getSysTimeS();
			}

			listener.newDataSFusion = false;
			dataSFusionLock.unlock();
		}

		if (listener.newDataAhrs) {
			std::unique_lock<std::mutex> dataAhrsLock {listener.dataAhrsMutex};
			// std::cout << "newDataAhrs" << std::endl;

			if (listener.dataAhrs.alive()) {
				// std::cout << "Reset dataAhrsTime" << std::endl;
				dataAhrsTime = timer.getSysTimeS();
			}

			listener.newDataAhrs = false;
			dataAhrsLock.unlock();
		}

		if (listener.newDataAir) {
			std::unique_lock<std::mutex> dataAirLock {listener.dataAirMutex};
			// std::cout << "newDataAir" << std::endl;

			if (listener.dataAir.alive()) {
				// std::cout << "Reset dataAirTime" << std::endl;
				dataAirTime = timer.getSysTimeS();
			}

			listener.newDataAir = false;
			dataAirLock.unlock();
		}

		if (listener.newDataPsu) {
			std::unique_lock<std::mutex> dataPsuLock {listener.dataPsuMutex};
			// std::cout << "newDataPsu" << std::endl;

			if (listener.dataPsu.alive()) {
				// std::cout << "Reset dataPsuTime" << std::endl;
				dataPsuTime = timer.getSysTimeS();
			}

			listener.newDataPsu = false;
			dataPsuLock.unlock();
		}

		if (listener.newDataCtrl) {
			std::unique_lock<std::mutex> dataCtrlLock {listener.dataCtrlMutex};
			// std::cout << "newDataCtrl" << std::endl;

			if (listener.dataCtrl.alive()) {
				// std::cout << "Reset dataCtrlTime" << std::endl;
				dataCtrlTime = timer.getSysTimeS();
			}

			listener.newDataCtrl = false;
			dataCtrlLock.unlock();
		}

		if (listener.newDataDownlink) {
			std::unique_lock<std::mutex> dataDownlinkLock {listener.dataDownlinkMutex};
			// std::cout << "newDataDownlink" << std::endl;

			if (listener.dataDownlink.alive()) {
				// std::cout << "Reset dataDownlinkTime" << std::endl;
				dataDownlinkTime = timer.getSysTimeS();
			}

			listener.newDataDownlink = false;
			dataDownlinkLock.unlock();
		}

		if (listener.newDataLog) {
			std::unique_lock<std::mutex> dataLogLock {listener.dataLogMutex};
			// std::cout << "newDataLog" << std::endl;

			if (listener.dataLog.alive()) {
				// std::cout << "Reset dataLogTime" << std::endl;
				dataLogTime = timer.getSysTimeS();
			}

			listener.newDataLog = false;
			dataLogLock.unlock();
		}

		bool allGood = true;

		if (timer.getSysTimeS() - dataRaiInTime > timeout) {
			std::cout << "RaiIn failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.raiInAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.raiInAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataRaiOutTime > timeout) {
			std::cout << "RaiOut failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.raiOutAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.raiOutAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataSFusionTime > timeout) {
			std::cout << "SFusion failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.sFusionAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.sFusionAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataAhrsTime > timeout) {
			std::cout << "Ahrs failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.ahrsAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.ahrsAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataAirTime > timeout) {
			std::cout << "Air failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.airAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.airAlive(true);
			dataWatchdogLock.unlock();
		}

		// if (timer.getSysTimeS() - dataGpsTime > timeout) {
		// 	std::cout << "Gps failure" << std::endl;
		// 	std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
		// 	allGood &= false;
		// 	dataWatchdog.gpsAlive(false);
		// 	dataWatchdogLock.unlock();
		// } else {
		// 	std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
		// 	allGood &= true;
		// 	dataWatchdog.gpsAlive(true);
		// 	dataWatchdogLock.unlock();
		// }

		if (timer.getSysTimeS() - dataPsuTime > timeout) {
			std::cout << "Psu failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.psuAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.psuAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataCtrlTime > timeout) {
			std::cout << "Ctrl failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.ctrlAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.ctrlAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataDownlinkTime > timeout) {
			std::cout << "Downlink failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.downlinkAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.downlinkAlive(true);
			dataWatchdogLock.unlock();
		}

		if (timer.getSysTimeS() - dataLogTime > timeout) {
			std::cout << "Log failure" << std::endl;
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= false;
			dataWatchdog.logAlive(false);
			dataWatchdogLock.unlock();
		} else {
			std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
			allGood &= true;
			dataWatchdog.logAlive(true);
			dataWatchdogLock.unlock();
		}

		std::unique_lock<std::mutex> dataWatchdogLock {dataWatchdogMutex};
		dataWatchdog.allAlive() = allGood;
		dataWatchdogLock.unlock();

		if ((timer.getSysTimeS() - okPrintTime > 1.0) && allGood) {
			okPrintTime = timer.getSysTimeS();
			std::cout << "ok @ " << timer.getSysTimeS() << "s" << std::endl;
		}

		greenLed = allGood;

		// reset the alive timer
		aliveTime = timer.getSysTime();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}

void Watchdog::print() {

	std::cout << "--- " << this->name << " " << dataWatchdog.time() << " ---" << std::endl;
	std::cout << "allAlive      " << dataWatchdog.allAlive() << std::endl;
	std::cout << "ahrsAlive     " << dataWatchdog.ahrsAlive() << std::endl;
	std::cout << "airAlive      " << dataWatchdog.airAlive() << std::endl;
	std::cout << "ctrlAlive     " << dataWatchdog.ctrlAlive() << std::endl;
	std::cout << "downlinkAlive " << dataWatchdog.downlinkAlive() << std::endl;
	std::cout << "gpsAlive      " << dataWatchdog.gpsAlive() << std::endl;
	std::cout << "psuAlive      " << dataWatchdog.psuAlive() << std::endl;
	std::cout << "raiInAlive    " << dataWatchdog.raiInAlive() << std::endl;
	std::cout << "raiOutAlive   " << dataWatchdog.raiOutAlive() << std::endl;
	std::cout << "sFusionAlive  " << dataWatchdog.sFusionAlive() << std::endl;
	std::cout << "uplinkAlive   " << dataWatchdog.uplinkAlive() << std::endl;
	std::cout << "alive         " << dataWatchdog.alive() << std::endl;

}

void Watchdog::led() {

	while (1) {

		{ // handle green led
			float period = 0.0;
			float duty_cycle = 0.0;

			if (greenLed) {
				period = 1.5;
				duty_cycle = 0.95;
			} else {
				period = 0.15;
				duty_cycle = 0.5;
			}

			static int led_mode = 0;
			if (duty_cycle < 0.01) {
				drv_led_set_green(0);
				led_mode = 0;

			} else if (duty_cycle > 0.99) {
				drv_led_set_green(1);
				led_mode = 1;

			} else {

				static float last_switch_time = timer.getSysTimeS();
				if (led_mode == 0) {
					if (timer.getSysTimeS() > last_switch_time + period*(1.0-duty_cycle)) {
						drv_led_set_green(1);
						led_mode = 1;
						last_switch_time = timer.getSysTimeS();
					}

				} else {
					if (timer.getSysTimeS() > last_switch_time + period*duty_cycle) {
						drv_led_set_green(0);
						led_mode = 0;
						last_switch_time = timer.getSysTimeS();
					}
				}
			}
		}

		{ // handle red led
			float period = 0.0;
			float duty_cycle = 0.0;

			if (yellowLed) {
				period = 0.5;
				duty_cycle = 0.5;
			} else {
				period = 0.0;
				duty_cycle = 0.0;
			}

			static int led_mode = 0;
			if (duty_cycle < 0.01) {
				drv_led_set_yellow(0);
				led_mode = 0;

			} else if (duty_cycle > 0.99) {
				drv_led_set_yellow(1);
				led_mode = 1;

			} else {

				static float last_switch_time = timer.getSysTimeS();
				if (led_mode == 0) {
					if (timer.getSysTimeS() > last_switch_time + period*(1.0-duty_cycle)) {
						drv_led_set_yellow(1);
						led_mode = 1;
						last_switch_time = timer.getSysTimeS();
					}

				} else {
					if (timer.getSysTimeS() > last_switch_time + period*duty_cycle) {
						drv_led_set_yellow(0);
						led_mode = 0;
						last_switch_time = timer.getSysTimeS();
					}
				}
			}
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}

}
