#include <iostream>
#include <cstdint>
#include <thread>

#include "downlink.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Downlink *downlink = new Downlink();

	std::cout << downlink->name << " start" << std::endl;

	if (downlink->init()) {
		std::thread run([&] (Downlink *downlink) { downlink->run(); }, downlink);
		run.join();
	}

	std::cout << downlink->name << " stop" << std::endl;

	delete downlink;
	return 0;
}
