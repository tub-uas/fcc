#ifndef TECS_H
#define TECS_H

#include "pid.h"
#include <cmath>

typedef enum {
	H_SETPOINT,
	H_DOT_SETPOINT
} height_mode_t;

class Tecs 
{

public:

	Tecs(float setpoint_v_dot, float setpoint_gam, float keI, float keP, float ktI, float ktP, float k_geps, float k_vdeps, float k_dist, float k_dist_2, height_mode_t mode);
	~Tecs();

	// SETTER METHODS
	void set_limits_pitch(float min, float max);
	void set_limits_throttle(float min, float max);
	bool set_mode(bool mode);
	void reset(void);

	// GETTER METHODS
	bool run(float dt, float setpoint_v, float setpoint_h, float v, float h, float v_dot, float h_dot);
	

	// RUN / UPDATE METHODS
	
	
	
	bool get_mode(void);
	float get_throttle_setpoint(void);
	float get_pitch_setpoint(void);
	float get_setpoint_gam(float h_cmd, float h, float v);
	float get_setpoint_gam(float h_dot_cmd, float v);
	float get_setpoint_vdot(float v_cmd, float v);
	float get_gam(float h_dot, float v);

private:

	// LIMITS PITCH
	float _pitch_limits_max{45*M_PI/180.0};
	float _pitch_limits_min{-45*M_PI/180.0};

	// LIMITS THROTTLE
	float _thrt_limits_max{1.0};
	float _thrt_limits_min{0.0};

	// INTEGRATOR VALUES
	float _thrt_integrator{0};
	float _pitch_integrator{0};

	// FEED FORWARD (KTP, KEP)
	float _thrt_add;
	float _pitch_add;

	// SETPOINTS
	float _setpoint_v_dot_g;
	float _setpoint_gam;

	// MEASUREMENTS
	float _v_dot_g;
	float _gam;

	// CONTROLLER CONSTANTS
	const float _gravity = 9.80665;
	
	// PITCH
	float _keI;
	float _keP;

	// THROTTLE
	float _ktI;
	float _ktP;
	
	// TIMECONSTANTS
	float _tau_v; // Velocity
	float _tau_h; // Height

	// PRIORITY GAINS
	float _k_geps;
	float _k_vdeps;

	// DISTRIBUTION GAINS
	float _k_dist;
	float _k_dist_2;


	// MODE H/V OR HDOT/V CMD
	height_mode_t _mode;

	// ERROR VALUES
	float _err_vdot_g;
	float _err_gam;

	// CONTROLLER OUTPUTS
	float _setpoint_throttle;
	float _setpoint_pitch;
	
};










#endif // TECS_H