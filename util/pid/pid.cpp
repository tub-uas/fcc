#include "pid.h"

#include <iostream>
#include <cstring>


Pid::Pid() {

	this->kP = 0.0;
	this->kI = 0.0;
	this->kD = 0.0;
	this->outMax = 0.0;
	this->outMin = 0.0;
	this->wrap = false;

}

Pid::Pid(float kP, float kI, float kD, float outMax, float outMin, float wrap) {

	this->kP = kP;
	this->kI = kI;
	this->kD = kD;
	if (outMax <= outMin) {
		std::cout << "Pid outMax has to be greater than outMin" << std::endl;
	} else {
		this->outMax = outMax;
		this->outMin = outMin;
	}
	this->wrap = wrap;

}

Pid::~Pid() {

}

bool Pid::set(float kP, float kI, float kD, float outMax, float outMin, float wrap) {

	this->kP = kP;
	this->kI = kI;
	this->kD = kD;
	if (outMax <= outMin) {
		std::cout << "Pid outMax has to be greater than outMin" << std::endl;
		return false;
	} else {
		this->outMax = outMax;
		this->outMin = outMin;
	}
	this->wrap = wrap;

	return true;
}

bool Pid::run(float dt, float set, float in, float *out) {

	// Check if time is negative
	if (dt <= 0.0) {
		std::cout << "Pid error dt has to be greater than zero" << std::endl;
		return false;
	}

	// Calculate the control error
	float err = set - in;

	// Check for special wrap around function
	if (wrap) {
		if (err < outMin) {
			err += 2.0 * outMax;
		} else if (err > outMax) {
			err += 2.0 * outMin;
		}
	}

	// Calculate integral error
	float integ = err * dt + errAcc;

	// Calculate derivative error
	// Do derivate of only process variable to avoid command glitches
	float deriv = -(prevIn - in) / dt;

	// Calculate overall error
	*out = err*kP + integ*kI + deriv*kD;

	// Bound output to set limits, this is also our anti windup logic
	if (*out < outMin) {
		*out = outMin;
	} else if (*out > outMax) {
		*out = outMax;
	} else {
		errAcc += err * dt;
	}

	// Store current error in prev variable for next iteration
	prevIn = in;

	return true;
}

bool Pid::reset() {

	errAcc = 0.0;
	prevIn = 0.0;

	return true;
}
