#include <gtest/gtest.h>

#include "../../util/pid/pid.h"

TEST(pid, constructor) {

	Pid pid1(1.0, 2.0, 3.0, 4.0, -5.0, false);
	ASSERT_NEAR(pid1.kP, 1.0, 1.0e-6);
	ASSERT_NEAR(pid1.kI, 2.0, 1.0e-6);
	ASSERT_NEAR(pid1.kD, 3.0, 1.0e-6);
	ASSERT_NEAR(pid1.outMax, 4.0, 1.0e-6);
	ASSERT_NEAR(pid1.outMin, -5.0, 1.0e-6);
	ASSERT_EQ(pid1.wrap, false);

	Pid pid2(-1.1, -2.2, -3.3, -4.4, -5.5, true);
	ASSERT_NEAR(pid2.kP, -1.1, 1.0e-6);
	ASSERT_NEAR(pid2.kI, -2.2, 1.0e-6);
	ASSERT_NEAR(pid2.kD, -3.3, 1.0e-6);
	ASSERT_NEAR(pid2.outMax, -4.4, 1.0e-6);
	ASSERT_NEAR(pid2.outMin, -5.5, 1.0e-6);
	ASSERT_EQ(pid2.wrap, true);
}
