#include "gps.h"

#include <iostream>
#include <iomanip>
#include <typeinfo>

Listener::Listener() : publication_matched(0) {
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

Gps::Gps() : participant(nullptr),
             publisher(nullptr),
             topicGps(nullptr),
             writerGps(nullptr),
             typeGps(new DataGpsPubSubType()) {
}

Gps::~Gps() {

	if (writerGps != nullptr) {
		publisher->delete_datawriter(writerGps);
	}

	if (topicGps != nullptr) {
		participant->delete_topic(topicGps);
	}

	if (publisher != nullptr) {
		participant->delete_publisher(publisher);
	}

	eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->delete_participant(participant);

}


bool Gps::init() {

	std::cout << this->name << " init" << std::endl;

	std::cout << std::setprecision(4) << std::fixed;

	eprosima::fastdds::dds::DomainParticipantQos participantQos;
	participantQos.name("GpsParticipant");
	participant = eprosima::fastdds::dds::DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
	if (participant == nullptr) {
		return false;
	}

	// Register the Type
	typeGps.register_type(participant);

	// Create the publications Topic
	topicGps = participant->create_topic("DataGps", "DataGps", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);
	if (topicGps == nullptr) {
		return false;
	}

	// Create the Publisher
	publisher = participant->create_publisher(eprosima::fastdds::dds::PUBLISHER_QOS_DEFAULT, nullptr);
	if (publisher == nullptr) {
		return false;
	}

	// Create the DataWriter
	writerGps = publisher->create_datawriter(topicGps, eprosima::fastdds::dds::DATAWRITER_QOS_DEFAULT, &listener);
	if (writerGps == nullptr) {
		return false;
	}

	aliveTime = timer.getSysTime();

	if (gpsCom.init() == false) {
		return false;
	}

	return true;
}


void Gps::publish() {

	while (1) {

		// std::cout << this->name << " publish" << std::endl;

		std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};
		dataGps.time(timer.getSysTime());

		if (timer.getSysTime() < aliveTime + aliveReset) {
			dataGps.alive(true);
		} else {
			dataGps.alive(false);
			std::cerr << "GPS NOT ALIVE" << std::endl;
		}
		if(_publish_now) {
			writerGps->write(&dataGps);
			_publish_now = false;
		}
		dataGpsLock.unlock();

		// print();

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(1);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(1);
	}

}


void Gps::run() {
	while (1) {
		// std::cout << this->name << " run" << std::endl;
		if (gpsCom.receive()) {

			std::unique_lock<std::mutex> dataGpsLock {dataGpsMutex};

			dataGps.senseTime(gpsCom.time);
			dataGps.latitude(gpsCom.latitude);
			dataGps.longitude(gpsCom.longitude);
			dataGps.alt_msl(gpsCom.altitude);
			dataGps.course_over_ground(gpsCom.cog);
			dataGps.groundspeed(gpsCom.speed);
			dataGps.dop_position(gpsCom.dop_p);
			dataGps.dop_horizontal(gpsCom.dop_h);
			dataGps.dop_velocity(gpsCom.dop_v);
			dataGps.sats(gpsCom.sats_in_use);
			dataGps.sats_in_view(gpsCom.sats_in_view);
			dataGps.fix(gpsCom.fix);
			dataGps.fix_mode(gpsCom.fix_mode);
			dataGps.second(gpsCom.second);
			dataGps.minute(gpsCom.minute);
			dataGps.hour(gpsCom.hour);
			dataGps.day(gpsCom.day);
			dataGps.month(gpsCom.month);
			dataGps.year(gpsCom.year);
			dataGps.variation(gpsCom.variation);
			dataGps.magX(gpsCom.mag[0]);
			dataGps.magY(gpsCom.mag[1]);
			dataGps.magZ(gpsCom.mag[2]);

			// reset the alive timer
			aliveTime = timer.getSysTime();
			_publish_now = true;
			dataGpsLock.unlock();

			// print();
		}

		static auto next_wakeup = std::chrono::steady_clock::now() + std::chrono::milliseconds(10);
		std::this_thread::sleep_until(next_wakeup);
		next_wakeup += std::chrono::milliseconds(10);

	}

}

void Gps::print() {

	std::cout << "--- " << this->name << " " << dataGps.time() << " ---" << std::endl;

	std::cout << "senseTime  " << dataGps.senseTime() << std::endl;
	std::cout << std::setprecision(10) << std::fixed;
	std::cout << "lat        " << dataGps.latitude() << std::endl;
	std::cout << "lon        " << dataGps.longitude() << std::endl;
	std::cout << std::setprecision(4) << std::fixed;
	std::cout << "alt        " << dataGps.alt_msl() << std::endl;
	std::cout << "cog        " << dataGps.course_over_ground() << std::endl;
	std::cout << "speed      " << dataGps.groundspeed() << std::endl;
	std::cout << "dopP       " << dataGps.dop_position() << std::endl;
	std::cout << "dopH       " << dataGps.dop_horizontal() << std::endl;
	std::cout << "dopV       " << dataGps.dop_velocity() << std::endl;
	std::cout << "sats       " << dataGps.sats() << std::endl;
	std::cout << "satsInView " << dataGps.sats_in_view() << std::endl;
	std::cout << "fix        " << dataGps.fix() << std::endl;
	std::cout << "fixMode    " << dataGps.fix_mode() << std::endl;
	std::cout << "second     " << dataGps.second() << std::endl;
	std::cout << "minute     " << dataGps.minute() << std::endl;
	std::cout << "hour       " << dataGps.hour() << std::endl;
	std::cout << "day        " << dataGps.day() << std::endl;
	std::cout << "month      " << dataGps.month() << std::endl;
	std::cout << "year       " << dataGps.year() << std::endl;
	std::cout << "variation  " << dataGps.variation() << std::endl;
	std::cout << "magX       " << dataGps.magX() << std::endl;
	std::cout << "magY       " << dataGps.magY() << std::endl;
	std::cout << "magZ       " << dataGps.magZ() << std::endl;
	std::cout << "alive      " << dataGps.alive() << std::endl;

}
