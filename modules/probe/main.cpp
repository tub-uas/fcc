#include <iostream>
#include <cstdint>
#include <thread>

#include "probe.h"

int main(int argc, const char* argv[]) {


	if( argc < 1 ) {
		return 0;
	}

	std::string listen_to = argv[1];

	Probe *probe = new Probe(listen_to);

	std::cout << probe->name << " " << listen_to  << " start" << std::endl;
	
	if (probe->init()) {
		probe->run();
	}

	std::cout << probe->name << " stop" << std::endl;

	delete probe;
	return 0;
}
