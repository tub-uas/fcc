#include <iostream>
#include <cstdint>
#include <thread>

#include "ctrl.h"

int main(int argc, const char* argv[]) {

	(void) argc;
	(void) argv;

	Ctrl *ctrl = new Ctrl();

	std::cout << ctrl->name << " start" << std::endl;

	if (ctrl->init()) {
		std::thread run([&] (Ctrl *ctrl) { ctrl->run(); }, ctrl);
		std::thread publish([&] (Ctrl *ctrl) { ctrl->publish(); }, ctrl);
		run.join();
		publish.join();
	}

	std::cout << ctrl->name << " close" << std::endl;

	delete ctrl;
	return 0;
}
