#ifndef PID_H
#define PID_H

#include <cstdint>
#include <array>

#include "../../util/timer/timer.h"

typedef struct {
	double kP;
	double kI;
	double kD;
	double lim_max;
	double lim_min;
} pid_setup_t;

class Pid {

public:

	Pid() {};

	~Pid() {};

	bool init(double kP, double kI, double kD, double lim_max, double lim_min);
	bool init(pid_setup_t setup);

	double update(double target, double is, double dt);

	bool reset_integrator();	
	
	void set_p_gain(double kP) { _kP = kP; }
	void set_i_gain(double kI) { _kI = kI; }
	void set_d_gain(double kD) { _kD = kD; }
	
	void set_limit_max(double lim_max) { _lim_max = lim_max; }
	void set_limit_min(double lim_min) { _lim_min = lim_min; }

	double get_i_gain() { return _kI; }
	double get_d_gain() { return _kD; }
	double get_p_gain() { return _kP; }
	
	double get_limit_max() { return _lim_max; }
	double get_limit_min() { return _lim_min; }
	

private:
	
	bool _is_init{false};

	double _cmd{0.0};
	double _cmd_last{0.0};
	double _kP{0.0};
	double _kI{0.0};
	double _kD{0.0};
	double _lim_max{0.0};
	double _lim_min{0.0};
	
	double _err_integral{0.0};
	double _prev_err{0.0};

};

#endif  // PID_H
