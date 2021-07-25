/****************************************************************************
 * 
 * Author: Christopher Ruwisch
 * Date  : 15/07/2021 
 * 
 * 
 * File  : Mixer.cpp
 * 
 *
 ****************************************************************************/


#include "Mixer.h"



/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::init(uint16_t min_pwm, uint16_t max_pwm)
{
	_min_pwm = min_pwm;
	_max_pwm = max_pwm;
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_flight_mode(uint16_t mode_pwm) 
{
	// GET RANGE FROM PWM 0 1 2 by scaling Motor
	double modelevel = 2.0*_get_normalized_pwm(mode_pwm,MOTOR);
	if(modelevel < 0.5f) {
		_flight_mode = MAN;
	}
	else if(modelevel > 1.5f) {
		_flight_mode = EXP;
	}
	else {
		_flight_mode = AUTO;
	}
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_flight_fct(uint16_t fct_pwm)
{
	// GET RANGE FROM PWM 0 1 2 by scaling Motor
	double fctlevel = 2.0*_get_normalized_pwm(fct_pwm,MOTOR);
	if( fctlevel < 0.5f ) {
		_flight_fct = FCT_0;
	}
	else if( fctlevel > 1.5f ) {
		_flight_fct = FCT_2;
	}
	else {
		_flight_fct = FCT_1;
	}
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_thr_setpoint(uint16_t thr_pwm)
{
	_thr_setpoint = _get_normalized_pwm(thr_pwm, MOTOR); 
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_ail_left_setpoint(uint16_t ail_left_pwm)
{
	_ail_left_setpoint = _get_normalized_pwm(ail_left_pwm, SURFACE);
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_ail_right_setpoint(uint16_t ail_right_pwm)
{
	_ail_right_setpoint = _get_normalized_pwm(ail_right_pwm, SURFACE);
	_ail_setpoint = _ail_right_setpoint;
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_ele_setpoint(uint16_t ele_pwm)
{
	_ele_setpoint = _get_normalized_pwm(ele_pwm, SURFACE);
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_rud_setpoint(uint16_t rud_pwm)
{
	_rud_setpoint = _get_normalized_pwm(rud_pwm, SURFACE);
}

/**
 * [Mixer description]
 *
 * @return  void    [return description]
 */
void Mixer::set_flp_setpoint(uint16_t flp_pwm)
{
	_flp_setpoint = _get_normalized_pwm(flp_pwm, MOTOR);
}

/**
 * [Mixer description]
 *
 * @return  double  [return description]
 */
double Mixer::get_hgt_setpoint()
{
	// SANITY CHECK
	if(_hgt_max < _hgt_default) {
		_hgt_max = _hgt_default;
	}
	
	if(_hgt_min > _hgt_default) {
		_hgt_min = _hgt_default;
	}

	if(_ele_setpoint > _hgt_deadband) {
		return (_hgt_max-_hgt_default)*_ele_setpoint + _hgt_default;
	}
	else if(_ele_setpoint < -_hgt_deadband) {
		return (_hgt_default-_hgt_min)*_ele_setpoint + _hgt_default;
	}
	else {
		return _hgt_default;
	}
}

/**
 * [Mixer description]
 *
 * @return  double  [return description]
 */
double Mixer::_get_normalized_pwm(uint16_t pwm, controltype_t type)
{
	uint16_t constrained_pwm;
	double output = 0.0;
	switch(type) {
		case SURFACE:
				constrained_pwm = _limit_pwm(pwm);
				output = -2.0/(_min_pwm-_max_pwm)*constrained_pwm + (double)(_min_pwm+_max_pwm)/((double)(_min_pwm-_max_pwm));
			break;
		
		case MOTOR:
				constrained_pwm = _limit_pwm(pwm);
				output = -1.0/(_min_pwm-_max_pwm)*constrained_pwm + (_min_pwm)/((double)(_min_pwm-_max_pwm));
			break;

		default:
			output = 0.0;
	}
	return output;
}

/**
 * [Mixer description]
 *
 * @param   double    type  [type description]
 *
 * @return  uint16_t        [return description]
 */
uint16_t Mixer::_get_pwm_from_normalized(double norm, controltype_t type)
{
	uint16_t constrained_pwm;
	uint16_t output = 0;
	switch(type) {
		case SURFACE:
			output = (_max_pwm-_min_pwm)/2*norm + (_min_pwm+_max_pwm)/2;
			output = _limit_pwm(output);
			break;
		
		case MOTOR:
			output = (_max_pwm-_min_pwm)*norm + _min_pwm;
			output = _limit_pwm(output);
			break;
	}
	return output;
}

/**
 * [Mixer description]
 *
 * @return  uint16_t[return description]
 */
uint16_t Mixer::_limit_pwm(uint16_t pwm)
{
	if(pwm < _min_pwm) {
		return _min_pwm;
	}
	else if(pwm > _max_pwm) {
		return _max_pwm;
	}
	else {
		return pwm;
	}
}
