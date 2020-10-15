#include <iostream>
#include <cstdint>
#include <thread>

#include "log.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Log *log = new Log();

	std::cout << log->name << " start" << std::endl;

	if (log->init()) {
		std::thread run([&] (Log *log) { log->run(); }, log);
		std::thread publish([&] (Log *log) { log->publish(); }, log);
		run.join();
		publish.join();
	}

	std::cout << log->name << " close" << std::endl;

	delete log;
	return 0;
}
