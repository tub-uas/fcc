#include <iostream>
#include <cstdint>
#include <thread>

#include "sFusion.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	SFusion *sFusion = new SFusion();

	std::cout << sFusion->name << " start" << std::endl;

	if (sFusion->init()) {
		std::thread run([&] (SFusion *sFusion) { sFusion->run(); }, sFusion);
		//std::thread publish([&] (SFusion *sFusion) { sFusion->publish(); }, sFusion);
		run.join();
		//publish.join();
	}

	std::cout << sFusion->name << " close" << std::endl;

	delete sFusion;
	return 0;
}
