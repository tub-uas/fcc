#include <iostream>
#include <cstdint>
#include <thread>

#include "raiOut.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	RaiOut *raiOut = new RaiOut();

	std::cout << raiOut->name << " start" << std::endl;

	if (raiOut->init()) {
		std::thread run([&] (RaiOut *raiOut) { raiOut->run(); }, raiOut);
		std::thread publish([&] (RaiOut *raiOut) { raiOut->publish(); }, raiOut);
		run.join();
		publish.join();
	}

	std::cout << raiOut->name << " close" << std::endl;

	delete raiOut;
	return 0;
}
