#include <iostream>
#include <cstdint>
#include <thread>

#include "psu.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Psu *psu = new Psu();

	std::cout << psu->name << " start" << std::endl;

	if (psu->init()) {
		std::thread run([&] (Psu *psu) { psu->run(); }, psu);
		std::thread publish([&] (Psu *psu) { psu->publish(); }, psu);
		run.join();
		publish.join();
	}

	std::cout << psu->name << " stop" << std::endl;

	delete psu;
	return 0;
}
