#include "pid.h"

#include <iostream>
#include <cstring>



bool Pid::init(double kP, double kI, double kD, double lim_max, double lim_min)
{	
	_cmd = 0.0;
	_cmd_last = _cmd;
	
	set_p_gain(kP);
	set_i_gain(kI);
	set_d_gain(kD);

	set_limit_max(lim_max);
	set_limit_min(lim_min);

	_is_init = true;
	return _is_init;
}



double Pid::update(double target, double is, double dt) {

	// Check if time is negative
	if (dt <= 0.0 || !_is_init) {
		return _cmd_last;
	}

	// Calculate the control error
	double err = target - is;

	// Calculate derivative error
	// Do derivate of only process variable to avoid command glitches
	double deriv = (err-_prev_err) / dt;
	_prev_err = err;

	// Calculate PD command
	_cmd = err*_kP + deriv*_kD;

	// Calculate integral error
	double integ = err * dt + _err_integral;

	// Saturation check
	if(_cmd + integ <= _lim_max && _cmd + integ >= _lim_min) 
	{
		_err_integral += integ;
	}


	_cmd += _err_integral*_kI;
	// Bound output to set limits, this is also our anti windup logic
	if (_cmd > _lim_max) {
		_cmd = _lim_max;
	} else if (_cmd < _lim_min) {
		_cmd = _lim_min;
	}
	_cmd_last = _cmd;

	return _cmd_last;
}

bool Pid::reset_integrator() {

	_err_integral = 0.0;

	return true;
}
