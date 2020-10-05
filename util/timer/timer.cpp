#include "timer.h"

#include <iostream>

// TODO make the basic functions static

Timer::Timer(){

}

Timer::~Timer() {
	stop();
}

bool Timer::init(std::function<void(void)> func, uint64_t interval) {

	this->func = func;
	this->interval = interval;
	isInit = true;
	return true;
}

bool Timer::run() {
	if(!isInit) {
		return false;
		std::cout << "Could not start Timer ... Run init first" << std::endl;
	}
	isRun = true;
	thread = std::thread([&]() {  // <-- Lambda Function with reference
		startTime = hrc::now();
		nextHitTime = startTime;
		while (isRun) {
			nextHitTime += std::chrono::microseconds(interval);
			func();
			std::this_thread::sleep_until(nextHitTime);
		}
	});

	thread.detach();
	return true;
}

bool Timer::stop() {
	isRun = false;
	thread.~thread();
	return true;
}

Timer *Timer::setFunc(std::function<void(void)> func) {
	this->func = func;
	return this;
}

uint64_t Timer::getInterval() {
	return interval;
}

Timer *Timer::setInterval(const uint64_t &interval) {
	this->interval = interval;
	return this;
}

double Timer::getTime() {
	hrc::time_point actual = hrc::now();
	std::chrono::nanoseconds usec;
	usec = std::chrono::duration_cast<std::chrono::nanoseconds>(actual-startTime);
	return usec.count();
}

uint64_t Timer::getSysTime() {
	return std::chrono::duration_cast <std::chrono::microseconds>
	      (std::chrono::steady_clock::now().time_since_epoch()).count();
}

double Timer::getSysTimeS() {
	return (double)(std::chrono::duration_cast <std::chrono::microseconds>
	       (std::chrono::steady_clock::now().time_since_epoch()).count())/1000000.0;
}
