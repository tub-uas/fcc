#include <iostream>
#include <cstdint>
#include "downlink.h"





int32_t main(void) {
    
    Downlink *downlink = new Downlink();
    std::cout << "DOWNLINK ..." << std::endl;
    if(downlink->init()) {
        std::cout << "[START]" << std::endl;
        downlink->run();
    }
    else {
        std::cout << "[FAILED]" << std::endl;        
    }
    std::cout << "Closing Downlink" << std::endl;
    delete downlink;
    return 0;
}