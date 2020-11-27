# FCC Tests

This directory contains our unit and integration tests. We are using CMake to build and Google Test (GTest).

## Add tests
In order to add new tests you will have to follow these steps:
1. Create a test file that will house your tests. If you want to, for example, test the PID Controller you would create a new file inside the `util` directory called `pid_test.cpp`. There you would include the header files needed (here `#include "../util/pid/pid.h"`) for testing and the GTest header `#include <gtest/gtest.h>`. Then you can write your tests using the typical GTest syntax.
2. You will need to modify the `CMakelists.txt` in order to include and build your test. Add the files that contain the code you want to test using `add_library(...)`. Then link your test code (which contains the tests you wrote) against the `main.cpp` using `target_sources(...)` and also link the library you just before added using `target_link_libraries(...)`.
3. Now you are ready to create a new `build` directory. In that directory call `cmake ..` in order to let CMake create the files needed for building. Then run `make` in order to compile your code and your tests. You can finally run `./main_test` and see if your tests pass or not.
