#include "watchdog.h"

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

Watchdog::Watchdog() : participant(nullptr),
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

Watchdog::~Watchdog() {

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

	if (drv_led_init() != 0) {
		return false;
	}

	greenLed = false;
	yellowLed = false;

	return true;
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

void Watchdog::run() {

	// watchdog is running
	// yellowLed = true;

	const double timeout = 0.1;
	static double dataRaiInTime = timer.getSysTimeS();
	static double dataRaiOutTime = timer.getSysTimeS();
	static double dataSFusionTime = timer.getSysTimeS();
	static double dataAhrsTime = timer.getSysTimeS();
	static double dataAirTime = timer.getSysTimeS();
	static double dataPsuTime = timer.getSysTimeS();
	static double dataCtrlTime = timer.getSysTimeS();
	static double okTime = timer.getSysTimeS();

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

		bool allGood = true;
		if (timer.getSysTimeS() - dataRaiInTime > timeout) {
			std::cout << "RaiIn failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataRaiOutTime > timeout) {
			std::cout << "RaiOut failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataSFusionTime > timeout) {
			std::cout << "SFusion failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataAhrsTime > timeout) {
			std::cout << "Ahrs failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataAirTime > timeout) {
			std::cout << "Air failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataPsuTime > timeout) {
			std::cout << "Psu failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}
		if (timer.getSysTimeS() - dataCtrlTime > timeout) {
			std::cout << "Ctrl failure" << std::endl;
			allGood &= false;
		} else {
			allGood &= true;
		}

		if ((timer.getSysTimeS() - okTime > 1.0) && allGood) {
			okTime = timer.getSysTimeS();
			std::cout << "ok @ " << timer.getSysTimeS() << "s" << std::endl;
		}

		greenLed = allGood;

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);
	}
}
