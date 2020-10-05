#include <iostream>
#include <cstdint>
#include "downlink_subscriber.h"





int32_t main(void) {
    
    AlxSys_downlink *downlink = new AlxSys_downlink();
    std::cout << "DOWNLINK ..." << std::endl;
    if(downlink->init()) {
        std::cout << "[START]" << std::endl;
        downlink->run();
    }
    else {
        std::cout << "[FAILED]";        
    }
    std::cout << "Closing Downlink" << std::endl;
    delete downlink;
    return 0;
}