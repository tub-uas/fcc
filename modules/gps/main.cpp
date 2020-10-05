#include <iostream>
#include <cstdint>
#include "gps_publisher.h"





int32_t main(void) {
    
    AlxSys_gps *gps = new AlxSys_gps();
    std::cout << "GPS ..." << std::endl;
    if(gps->init()) {
        std::cout << "[START]" << std::endl;
        gps->run();
    }
    else {
        std::cout << "[FAILED]";        
    }
    std::cout << "Closing gps" << std::endl;
    delete gps;
    return 0;
}