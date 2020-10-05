#include <iostream>
#include <cstdint>
#include <thread>

#include "air.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Air *air = new Air();

	std::cout << air->name << " start" << std::endl;

	if (air->init()) {
		std::thread run([&] (Air *air) { air->run(); }, air);
		std::thread publish([&] (Air *air) { air->publish(); }, air);
		run.join();
		publish.join();
	}

	std::cout << air->name << " stop" << std::endl;

	delete air;
	return 0;
}
