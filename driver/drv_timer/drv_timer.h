#ifndef DRV_TIMER_H
#define DRV_TIMER_H

#include <chrono>
#include <functional>
#include <thread>

typedef std::chrono::steady_clock hrc;

class drv_timer
{
public:
	drv_timer();
	drv_timer(std::function<void(void)> func, const long &interval);
	~drv_timer();

	bool init(std::function<void(void)> func, uint64_t intervalMicros);
	bool run(void);
	bool stop();
	bool isRun();

	drv_timer *setFunc(std::function<void(void)> func);
	uint64_t getInterval();
	drv_timer *setInterval(const uint64_t &interval);

	double getTime();
	uint64_t getSysTime();

private:
	std::function<void(void)> mp_func;
	uint64_t mp_interval;
	std::thread mp_thread;
	bool mp_isRun = false;
	bool mp_isInit = false;
	hrc::time_point mp_startTime;
	hrc::time_point mp_stopTime;
	hrc::time_point mp_nextHitTime;

};

#endif // DRV_TIMER_H
