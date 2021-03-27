#include "estimatorAoassa.h"
#include <cmath>


Aoa::Aoa(float m,
		float S,
		float c,
		float C_L_0,
		float C_L_q,
		float C_L_delta_elev,
		float C_L_alpha) {

	_m              = m;
	_S              = S;
	_c              = c;
	_C_L_0          = C_L_0;
	_C_L_q          = C_L_q;
	_C_L_delta_elev = C_L_delta_elev;
	_C_L_alpha      = C_L_alpha;
	_alpha_hat       = 0.0;
}

float Aoa::estimate(float acc_x,
					float acc_z,
					float q_dyn,
					float V,
					float q,
					float elev) {

	_alpha_hat = (_m*(acc_x*sin(_alpha_hat)-acc_z*cos(_alpha_hat))/q_dyn/_S - _C_L_0 - _C_L_q*q*_c/2/V - _C_L_delta_elev*elev)/_C_L_alpha;
	return _alpha_hat;
}

Ssa::Ssa(float m,
		float S,
		float b,
		float C_Y_0,
		float C_Y_beta,
		float C_Y_p,
		float C_Y_r,
		float C_Y_delta_ail,
		float C_Y_delta_rud) {

	_m = m;
	_S = S;
	_b = b;
	_C_Y_0 = C_Y_0;
	_C_Y_beta = C_Y_beta;
	_C_Y_p = C_Y_p;
	_C_Y_r = C_Y_r;
	_C_Y_delta_ail = C_Y_delta_ail;
	_C_Y_delta_rud = _C_Y_delta_rud;
	_beta_hat = 0.0;
}

float Ssa::estimate(float acc_y,
					float q_dyn,
					float V,
					float p,
					float r,
					float aill,
					float rudd) {

	_beta_hat = (_m*acc_y/q_dyn/_S - _C_Y_0 - _C_Y_p*p*_b/2/V - _C_Y_r*r*_b/2/V - _C_Y_delta_ail*aill - _C_Y_delta_rud*rudd)/C_Y_beta;
	return _beta_hat;
}