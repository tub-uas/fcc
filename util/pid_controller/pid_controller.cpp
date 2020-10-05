#include <iostream>
#include <cmath>

#include "pid_controller.h"

using namespace std;

PID_Controller::PID_Controller(double kp, double ki, double kd, double max, double min) :
	_kp(kp),
	_ki(ki),
	_kd(kd),
	_max(max),
	_min(min),
	_pre_error(0.0),
	_integral(0.0)
{

}

PID_Controller::~PID_Controller() {

}

double PID_Controller::calculate(double set_point, double process_variable, double dt) {

	// Calculate error
	double error = set_point-process_variable;

	// Proportional term
	double p_out = _kp*error;

	if(dt <= 0.0) {
		cout << "delta t cant be zero or smaller than zero" << endl;
		return(-1.0);
	}

	// Integral term
	_integral += error*dt;
	double i_out = _ki*_integral;

	// Derivative term
	double derivative = (error-_pre_error)/dt;
	double d_out = _kd*derivative;

	// Calculate total output
	double output = p_out+i_out+d_out;


	// Restrict to max/min
	if(output > _max)
		output = _max;
	else if(output < _min)
		output = _min;

	// Save error to previous error
	_pre_error = error;

	// cout  << "d_out: " << d_out
	// << "   output: " << output
	// << "   error: " << error
	// << endl;

	return output;
}

void PID_Controller::reset() {
	_pre_error = 0.0;
	_integral = 0.0;
}
