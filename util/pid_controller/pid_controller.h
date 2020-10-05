#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID_Controller
{
public:
	// kp -  proportional gain
	// ki -  Integral gain
	// kd -  derivative gain
	// max - maximum value of manipulated variable
	// min - minimum value of manipulated variable
	PID_Controller(double kp, double ki, double kd, double max, double min);

	~PID_Controller();

	// sp - set point
	// pv - process variable
	// dt - loop interval time
	// return - calculated control output
	double calculate(double set_point, double process_variable, double dt);

	void reset();

private:
	double _kp;
	double _ki;
	double _kd;
	double _max;
	double _min;
	double _pre_error;
	double _integral;

};

#endif
