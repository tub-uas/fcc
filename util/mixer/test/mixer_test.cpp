#include <gtest/gtest.h>
#include "../MixerNew.h"

TEST(MIXER_TEST,thr_setpoint)
{
	// ARRANGE TEST
	Mixer mix;
	mix.init(1000,2000);
	uint16_t input = 1000; 
	
	double expected = 0.0;
	double actual = 0.0;
	
	
	// Compute resulte
	mix.set_thr_setpoint(1000);
	actual = mix.get_thr_setpoint();
	
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_EQ(1000,mix.get_thr_pwm_setpoint(actual));

	expected = 1.0;
	mix.set_thr_setpoint(2000);
	actual = mix.get_thr_setpoint();
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_EQ(2000,mix.get_thr_pwm_setpoint(actual));

	expected = 0.5;
	mix.set_thr_setpoint(1500);
	actual = mix.get_thr_setpoint();
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_EQ(1500,mix.get_thr_pwm_setpoint(actual));
}

TEST(MIXER_TEST,ail_setpoint)
{
	// ARRANGE TEST
	Mixer mix;
	mix.init(1000,2000);
	uint16_t input = 1000; 
	
	double expected = 0.0;
	double actual = 0.0;
	double scale = 0.3142;
	
	// Compute resulte
	mix.set_ail_left_setpoint(1000);
	mix.set_ail_right_setpoint(1000);
	actual = mix.get_ail_left_setpoint();
	expected = mix.get_ail_max()*-1.0;
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_EQ(1000,mix.get_ail_left_pwm_setpoint(actual/mix.get_ail_max()));
	
	expected = mix.get_ail_max()*1.0;
	mix.set_ail_left_setpoint(2000);
	mix.set_ail_right_setpoint(2000);
	actual = mix.get_ail_right_setpoint();
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_DOUBLE_EQ(expected,mix.get_ail_setpoint());
	EXPECT_EQ(2000,mix.get_ail_right_pwm_setpoint(actual/mix.get_ail_max()));

	expected = 0.0;
	mix.set_ail_left_setpoint(1500);
	mix.set_ail_right_setpoint(1500);
	actual = mix.get_ail_setpoint();
	EXPECT_DOUBLE_EQ(expected,actual);
	EXPECT_EQ(1500,mix.get_ail_right_pwm_setpoint(actual/mix.get_ail_max()));
}

TEST(MIXER_TEST,Modetest)
{
	// ARRANGE TEST
	Mixer mix;
	
	flight_mode_t expected = MAN;
	uint16_t input = 1000;
	mix.init(1000,2000);
	mix.set_flight_mode(input);

	EXPECT_EQ(expected,mix.get_flight_mode());
	
	expected = AUTO;
	mix.set_flight_mode(1500);
	EXPECT_EQ(expected,mix.get_flight_mode());

	expected = EXP;
	mix.set_flight_mode(2000);
	EXPECT_EQ(expected,mix.get_flight_mode());
}

TEST(MIXER_TEST,Fcttest)
{
	// ARRANGE TEST
	Mixer mix;
	
	flight_fct_t expected = FCT_0;
	uint16_t input = 1000;
	mix.init(1000,2000);
	mix.set_flight_fct(input);

	EXPECT_EQ(expected,mix.get_flight_fct());
	
	expected = FCT_1;
	mix.set_flight_fct(1500);
	EXPECT_EQ(expected,mix.get_flight_fct());

	expected = FCT_2;
	mix.set_flight_fct(2000);
	EXPECT_EQ(expected,mix.get_flight_fct());
}

TEST(MIXER_TEST, spd_setpoint)
{
	Mixer mix;
	mix.init(1000,2000);
	mix.set_thr_setpoint(1500);
	EXPECT_DOUBLE_EQ(15.0,mix.get_spd_setpoint());

	mix.set_thr_setpoint(2000);
	EXPECT_DOUBLE_EQ(30.0,mix.get_spd_setpoint());

	mix.set_thr_setpoint(1000);
	EXPECT_DOUBLE_EQ(0.0,mix.get_spd_setpoint());

	mix.set_spd_min(15.0f);
	EXPECT_DOUBLE_EQ(15.0,mix.get_spd_setpoint());
}

TEST(MIXER_TEST, hgt_setpoint)
{
	Mixer mix;
	mix.init(1000,2000);
	mix.set_ele_setpoint(1500);
	EXPECT_DOUBLE_EQ(50,mix.get_hgt_setpoint());

	mix.set_ele_setpoint(2000);
	EXPECT_DOUBLE_EQ(120.0,mix.get_hgt_setpoint());

	mix.set_ele_setpoint(1000);
	EXPECT_DOUBLE_EQ(0.0,mix.get_hgt_setpoint());

	mix.set_hgt_min(15);
	EXPECT_DOUBLE_EQ(15.0,mix.get_hgt_setpoint());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}