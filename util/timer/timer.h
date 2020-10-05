#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <functional>
#include <thread>

typedef std::chrono::steady_clock hrc;

class Timer
{
public:
	Timer();
	~Timer();

	bool init(std::function<void(void)> func, uint64_t interval);
	bool run();
	bool stop();

	Timer *setFunc(std::function<void(void)> func);

	uint64_t getInterval();
	Timer *setInterval(const uint64_t &interval);

	double getTime();
	uint64_t getSysTime();
	double getSysTimeS();

private:
	std::function<void(void)> func;
	std::thread thread;

	uint64_t interval;
	bool isRun = false;
	bool isInit = false;

	hrc::time_point startTime;
	hrc::time_point stopTime;
	hrc::time_point nextHitTime;

};

#endif // TIMER_H
