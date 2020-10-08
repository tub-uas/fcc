#include <iostream>
#include <cstdint>
#include <thread>

#include "watchdog.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Watchdog *watchdog = new Watchdog();

	std::cout << watchdog->name << " start" << std::endl;

	if (watchdog->init()) {
		std::thread run([&] (Watchdog *watchdog) { watchdog->run(); }, watchdog);
		std::thread led([&] (Watchdog *watchdog) { watchdog->led(); }, watchdog);
		run.join();
		led.join();
	}

	std::cout << watchdog->name << " stop" << std::endl;

	delete watchdog;
	return 0;
}
