/****************************************************************************
 * 
 * Author: Christopher Ruwisch
 * Date  : 15/07/2021 
 * 
 * 
 * File  : Mixer.h
 * Description : Mixer class for classic aircraft configuration (AAERTF)
 *
 ****************************************************************************/
#ifndef MIXER_H
#define MIXER_H

#include <cstdint>

typedef enum {
	SURFACE = 0,
	MOTOR,
} controltype_t;

typedef enum {
	MANUAL = 0,
	AUTONOMOUS,
	EXPERIMENTAL,
} flight_mode_t;

typedef enum {
	FCT_0 = 0,
	FCT_1,
	FCT_2
} flight_fct_t;


class Mixer
{

public:
	
	
	
	Mixer() {};
	~Mixer() {};
	
	void init(uint16_t min_pwm, uint16_t max_pwm);


	// == SETTER FUNCTIONS =====================================================
	void set_thr_max(double thr_max) { _thr_max = thr_max; }
	void set_ail_max(double ail_max) { _ail_max = ail_max; }
	void set_ele_max(double ele_max) { _ele_max = ele_max; }
	void set_rud_max(double rud_max) { _rud_max = rud_max; }
	void set_roll_max(double roll_max) { _roll_max = roll_max; }
	void set_pitch_max(double pitch_max) { _pitch_max = pitch_max; }

	void set_yaw_rate_max(double yaw_rate_max) { _yaw_rate_max = yaw_rate_max; }
	void set_spd_max(double spd_max) { _spd_max = spd_max; }
	void set_spd_min(double spd_min) { _spd_min = spd_min; }
	void set_hgt_rate_max(double hgt_rate_max) { _hgt_rate_max = hgt_rate_max; }
	void set_hgt_max(double hgt_max) { _hgt_max = hgt_max; }
	void set_hgt_min(double hgt_min) { _hgt_min = hgt_min; }
	void set_hgt_dflt(double hgt_default) { _hgt_default = hgt_default; }
	void set_hgt_deadband(double hgt_deadband) { _hgt_deadband = hgt_deadband; }
	
	void set_flight_mode(uint16_t mode_pwm);
	void set_flight_fct(uint16_t fct_pwm);

	void set_thr_setpoint(uint16_t thr_pwm);
	void set_ail_left_setpoint(uint16_t ail_left_pwm);
	void set_ail_right_setpoint(uint16_t ail_right_pwm); // Sets also ail_setpoint
	void set_ele_setpoint(uint16_t ele_pwm);
	void set_rud_setpoint(uint16_t rud_pwm);
	void set_flp_setpoint(uint16_t flp_pwm);

	// == GETTER FUNCTIONS =====================================================
	double get_thr_max() { return _thr_max; }
	double get_ail_max() { return _ail_max; }
	double get_ele_max() { return _ele_max; }
	double get_rud_max() { return _rud_max; }
	double get_flp_max() { return _flp_max; }

	double get_roll_max() { return _roll_max; }
	double get_pitch_max() { return _pitch_max; }

	flight_mode_t get_flight_mode() { return _flight_mode; }
	flight_fct_t  get_flight_fct() { return _flight_fct; }

	double get_thr_setpoint() { return _thr_max * _thr_setpoint; }
	double get_ail_setpoint() { return _ail_max * _ail_setpoint; }
	double get_ail_left_setpoint() { return _ail_max * _ail_left_setpoint; }
	double get_ail_right_setpoint() { return _ail_max * _ail_right_setpoint; }
	double get_ele_setpoint() { return _ele_max * _ele_setpoint; }
	double get_rud_setpoint() { return _rud_max * _rud_setpoint; }
	double get_flp_setpoint() { return _flp_max * _flp_setpoint; }

	double get_roll_setpoint() { return _roll_max * _ail_setpoint; }
	double get_pitch_setpoint() { return _pitch_max * _ele_setpoint; }

	double get_yaw_setpoint() { return 0.0; }
	double get_yaw_rate_setpoint() { return _yaw_rate_max * _rud_setpoint; }
	double get_spd_setpoint() { return (_spd_max-_spd_min)*_thr_setpoint + _spd_min; };
	double get_hgt_rate_setpoint() { return _hgt_rate_max * _ele_setpoint; };
	double get_hgt_setpoint();
	


	uint16_t get_thr_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm,MOTOR); }
	uint16_t get_ail_left_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm, SURFACE); }
	uint16_t get_ail_right_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm, SURFACE); }
	uint16_t get_ele_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm, SURFACE); }
	uint16_t get_rud_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm, SURFACE); }
	uint16_t get_flp_pwm_setpoint(double norm) { return _get_pwm_from_normalized(norm, SURFACE); }

	uint16_t get_flight_mode_pwm(flight_mode_t mode);
	uint16_t get_flight_fct_pwm(flight_fct_t fct);


private:

	uint16_t _min_pwm{1000};
	uint16_t _max_pwm{1500};

	// == MODE AND FUNCTIONS ===================================================
	flight_mode_t _flight_mode{MANUAL};
	flight_fct_t  _flight_fct{FCT_0};

	// == VALUES FOR MANUAL CONTROL (MAN) ======================================

	// == MAN - NO / DAMP ======================================================
	double _thr_max{1.0f}; 
	double _ail_max{0.3142};
	double _ele_max{0.3142};
	double _rud_max{0.3142};
	double _flp_max{0.3142};

	double _thr_setpoint{0.0f};
	double _ail_setpoint{0.0f};
	double _ail_left_setpoint{0.0f};
	double _ail_right_setpoint{0.0f};
	double _ele_setpoint{0.0f};
	double _rud_setpoint{0.0f};
	double _flp_setpoint{0.0f};

	// RIGHT AILERON SETPOINT EQUALS AIL_SETPOINT (NO DIFFERENTIAL ATM)

	// == MAN - ATT ============================================================
	double _roll_max{0.5236f};
	double _pitch_max{0.5236f};

	// == VALUES FOR AUTOMATIC CONTROL (AUTO) ==================================
	double _yaw_rate_max{0.0f};
	double _spd_max{30.0f};
	double _spd_min{0.0f};
	double _hgt_rate_max{10.0f};
	double _hgt_max{120.0f};
	double _hgt_min{0.0f};
	double _hgt_default{50.0f};
	double _hgt_deadband{0.01f};

	// PRIVATE METHODS
	double _get_normalized_pwm(uint16_t pwm, controltype_t type);
	uint16_t _get_pwm_from_normalized(double norm, controltype_t type);

	uint16_t _limit_pwm(uint16_t pwm);

};

#endif // MIXER_H