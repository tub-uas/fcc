#ifndef PID_H
#define PID_H

#include <cstdint>
#include <array>

#include "../timer/timer.h"

class Pid {

public:

	Pid();
	Pid(float kP, float kI, float kD, float outMax, float outMin, float wrap);

	~Pid();

	bool set(float kP, float kI, float kD, float outMax, float outMin, float wrap);

	bool run(float dt, float set, float in, float *out);

	bool reset();

	float kP = 0.0;
	float kI = 0.0;
	float kD = 0.0;
	float outMax = 0.0;
	float outMin = 0.0;
	bool wrap = false;

private:
	float errAcc = 0.0;
	float prevIn = 0.0;

};

#endif  // PID_H
