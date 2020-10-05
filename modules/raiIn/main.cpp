#include <iostream>
#include <cstdint>
#include <thread>

#include "raiIn.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	RaiIn *raiIn = new RaiIn();

	std::cout << raiIn->name << " start" << std::endl;

	if (raiIn->init()) {
		std::thread run([&] (RaiIn *raiIn) { raiIn->run(); }, raiIn);
		std::thread publish([&] (RaiIn *raiIn) { raiIn->publish(); }, raiIn);
		run.join();
		publish.join();
	}

	std::cout << raiIn->name << " stop" << std::endl;

	delete raiIn;
	return 0;
}
