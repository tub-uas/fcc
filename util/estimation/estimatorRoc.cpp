#include "estimatorRoc.h"

#include <cmath>


Roc::Roc(float h_init, float roc_init, float sigma_press, float sigma_acc_z_n) {
	
	_h_est          = 0;
	_roc_est        = 0;
	_sigma_press    = sigma_press;
	_sigma_acc_z_n  = sigma_acc_z_n;
	_h_old          = h_init;
	_roc_old        = roc_init;
	
	K[0] = sqrt(2*_sigma_press/_sigma_acc_z_n);
	K[1] = _sigma_acc_z_n/_sigma_press;
}



float Roc::get_h_est(void) {
	return _h_est;
}

float Roc::get_roc_est(void) {
	return _roc_est;
}

void Roc::update(float h_baro, float acc_z_n, float dt) {

	float delta_h   = h_baro - _h_old;
	float delta_roc = dt*acc_z_n;
	
	// COMPUTE ESTIMATES
	_h_est   = _h_old + dt*_roc_old + dt*(K[0] + dt/2*K[1])*delta_h; + dt/2*delta_roc;
	_roc_est = _roc_old + dt*K[1]*delta_h + delta_roc;

	// SET ESTIMATES TO OLD
	_h_old   = _h_est;
	_roc_old = _roc_est;
}