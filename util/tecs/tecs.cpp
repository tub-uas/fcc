#include "tecs.h"
#include <cmath>


Tecs::Tecs(float setpoint_v_dot,
			float setpoint_gam,
			float keI,
			float keP,
			float ktI,
			float ktP,
			float k_geps,
			float k_vdeps,
			float k_dist,
			float k_dist_2,
			height_mode_t mode) {

	_setpoint_gam     = setpoint_gam;
	_setpoint_v_dot_g = setpoint_v_dot/_gravity;
	_keI              = keI;
	_keP              = keP;
	_ktI              = ktI;
	_ktP              = ktP;
	_k_geps           = k_geps;
	_k_vdeps          = k_vdeps;
	_k_dist           = k_dist;
	_k_dist_2         = k_dist_2;
	_mode             = mode;

}


float Tecs::_get_setpoint_gam(float h_cmd, float h, float v) {
	return (h_cmd-h)/_tau_h/v;
}

float Tecs::_get_setpoint_gam(float h_dot_cmd, float v) {
	return h_dot_cmd/v;
}

float Tecs::_get_setpoint_vdot(float v_cmd, float v) {
	return (v_cmd-v)/_tau_v;
}

float Tecs::_get_gam(float h_dot, float v) {
	return h_dot/v;
}

bool Tecs::run(float dt, float setpoint_v, float setpoint_h, float v, float h, float v_dot, float h_dot) {

	// SETPOINT COMPUTATION
	if(_mode == H_DOT_SETPOINT) {
		_setpoint_gam   = _get_setpoint_gam(setpoint_h,v);
	}
	else { // -> H
		_setpoint_gam   = _get_setpoint_gam(setpoint_h,h,v);
	}
	_setpoint_v_dot_g = _get_setpoint_vdot(setpoint_v,v)/_gravity;
	
	// COMPUTATION OF MEASURED VALUES
	_v_dot_g = v_dot/_gravity;
	_gam = h_dot/v;
	
	// ERROR COMPUTATION
	_err_gam    = _setpoint_gam-_gam;
	_err_vdot_g = _setpoint_v_dot_g-_v_dot_g;

	// TOTAL ENERGY PATH (THROTTLE)
	float thrt_integ = (_err_gam + _err_vdot_g)*_ktI*dt;
	_thrt_add = -_ktP*(_gam+_v_dot_g);
	
	// INTEGRATION AND ANTI WINDUP
	if(_thrt_integrator + thrt_integ + _thrt_add > _thrt_limits_max) {
		_setpoint_throttle = _thrt_limits_max;
	}
	else if(_thrt_integrator + thrt_integ + _thrt_add < _thrt_limits_min) {
		_setpoint_throttle = _thrt_limits_min;
	}
	else {
		_thrt_integrator += thrt_integ;
		_setpoint_throttle = _thrt_integrator + _thrt_add;
	}

	// ENERGY DISTRIBUTION PATH (PITCH)
	float pitch_integ = (_err_vdot_g*_k_vdeps-_err_gam*_k_geps)*_keI*dt;
	_pitch_add = _keP*(_k_dist_2*_gam-_k_dist*_v_dot_g);

	// INTEGRATION AND ANTI WINDUP
	if(_pitch_integrator + pitch_integ + _pitch_add > _pitch_limits_max) {
		_setpoint_pitch = _pitch_limits_max;
	}
	else if(_pitch_integrator + pitch_integ + _thrt_add < _pitch_limits_min) {
		_setpoint_pitch = _pitch_limits_min;
	}
	else {
		_pitch_integrator += pitch_integ;
		_setpoint_pitch = _pitch_integrator + _pitch_add;
	}

	return _mode;
}

void Tecs::reset() {
	_thrt_integrator = 0;
	_pitch_integrator = 0;
}



bool Tecs::set_mode(height_mode_t mode) {

	_mode = mode;
	if(_mode == H_SETPOINT) {
		return true;
	}
	else {
		return false;
	}

}

bool Tecs::get_mode(void) {
	return _mode;
}

float Tecs::get_throttle_setpoint(void) {
	return _setpoint_throttle;
}

float Tecs::get_pitch_setpoint(void) {
	return _setpoint_pitch;
}

void Tecs::set_limits_pitch(float min, float max) {
	_pitch_limits_min = min;
	_pitch_limits_max = max;
}

void Tecs::set_limits_throttle(float min, float max) {
	_thrt_limits_min = min;
	_thrt_limits_max = max;
}