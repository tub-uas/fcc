#include <iostream>
#include <cstdint>
#include <thread>

#include "gps.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Gps *gps = new Gps();

	std::cout << gps->name << " start" << std::endl;

	if (gps->init()) {
		std::thread run([&] (Gps *gps) { gps->run(); }, gps);
		std::thread publish([&] (Gps *gps) { gps->publish(); }, gps);
		run.join();
		publish.join();
	}

	std::cout << gps->name << " stop" << std::endl;

	delete gps;
	return 0;
}
