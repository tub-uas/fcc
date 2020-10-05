#include "drv_timer.h"

#include <iostream>


drv_timer::drv_timer(){

}

drv_timer::~drv_timer() {
	stop();
}

bool drv_timer::init(std::function<void(void)> func, uint64_t intervalMicros) {

	mp_func     = func;
	mp_interval = intervalMicros;
	mp_isInit   = true;
	return true;
}

bool drv_timer::run() {
	if(!mp_isInit) {
		return false;
		std::cerr << "Could not start Timer ... Run init first" << std::endl;
	}
	mp_isRun    = true;
	mp_thread   = std::thread([&]() {  // <-- Lambda Function with reference
		mp_startTime = hrc::now();
		mp_nextHitTime = mp_startTime;
		while(mp_isRun) {
			mp_nextHitTime += std::chrono::microseconds(mp_interval);
			mp_func();
			std::this_thread::sleep_until(mp_nextHitTime);
		}
	});
	mp_thread.detach();
	return true;
}

bool drv_timer::stop() {
	mp_isRun = false;
	mp_thread.~thread();
	return true;
}

drv_timer *drv_timer::setFunc(std::function<void(void)> func) {
	mp_func = func;
	return this;
}

uint64_t drv_timer::getInterval() {
	return mp_interval;
}

drv_timer *drv_timer::setInterval(const uint64_t &interval) {
	mp_interval = interval;
	return this;
}

double drv_timer::getTime() {
	hrc::time_point actual = hrc::now();

	std::chrono::nanoseconds usec;
	usec = std::chrono::duration_cast<std::chrono::nanoseconds>(actual-mp_startTime);
	return usec.count();
}

uint64_t drv_timer::getSysTime() {
	return std::chrono::duration_cast <std::chrono::microseconds>
	  (std::chrono::steady_clock::now().time_since_epoch()).count();
}
