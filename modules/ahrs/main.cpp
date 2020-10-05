#include <iostream>
#include <cstdint>
#include <thread>

#include "ahrs.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Ahrs *ahrs = new Ahrs();

	std::cout << ahrs->name << " start" << std::endl;

	if (ahrs->init()) {
		std::thread run([&] (Ahrs *ahrs) { ahrs->run(); }, ahrs);
		std::thread publish([&] (Ahrs *ahrs) { ahrs->publish(); }, ahrs);
		run.join();
		publish.join();
	}

	std::cout << ahrs->name << " stop" << std::endl;

	delete ahrs;
	return 0;
}
