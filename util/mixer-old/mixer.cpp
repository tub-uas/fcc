// Include Header
#include "mixer.h"
#include <math.h>

// Function declarations
float32_t pwm_angle(uint8_t ch_nr, uint16_t pwm) {

	switch (ch_nr) {

		case ENG: {
			float32_t eta_f = (0.00125 *((float32_t)pwm-1100.0));
			return eta_f;
		}

		case AILL: {
			float32_t xil = (0.032546*((float32_t)pwm-1502.0))*PI/180.0;
			return xil;
		}

		case AILR: {
			float32_t xir = (-0.029747*((float32_t)pwm-1502.0))*PI/180.0;
			return xir;
		}

		case ELV: {
			float32_t eta = (-0.048959*((float32_t)pwm-1500.0))*PI/180.0;
			return eta;
		}

		case RUD: {
			float32_t zeta = (0.041879*((float32_t)pwm-1500.0))*PI/180.0;
			return zeta;
		}
	}

	return pwm;
}
float32_t pwm_att_angle(uint8_t ch_nr, uint16_t pwm) {

	switch (ch_nr) {

		case ENG: {
			float32_t eta_f = (0.00125 *((float32_t)pwm-1100.0));
			return eta_f;
		}

		case AILL: {
			float32_t xil = -(((float32_t)pwm-1502.0)/400.0)*(PI/180.0)*60.0;
			return xil;
		}

		case AILR: {
			float32_t xir = (((float32_t)pwm-1502.0)/400.0)*(PI/180.0)*60.0;
			return xir;
		}

		case ELV: {
			float32_t eta = (((float32_t)pwm-1500.0)/400.0)*(PI/180.0)*60.0;
			return eta;
		}

		case RUD: {
			float32_t zeta = -(((float32_t)pwm-1504.0)/400.0)*(PI/180.0)*180.0;
			return zeta;
		}
	}

	return pwm;
}


uint16_t angle_pwm(uint8_t ch_nr,float32_t angle) {

	switch (ch_nr) {

		case ENG: {
			float32_t pwm_eta_f = 800.0*(angle) + 1100.0;
			uint16_t pwm_return = (uint16_t)round(pwm_eta_f);
			return pwm_return;
		}

		case AILL: {
			float32_t pwm_xil = -1.0/0.032546*(angle*180.0/PI) + 1502.0;
			uint16_t pwm_return = (uint16_t)round(pwm_xil);
			return pwm_return;
		}

		case AILR: {
			float32_t pwm_xir = -1.0/0.029747*(angle*180.0/PI) + 1502.0;
			uint16_t pwm_return = (uint16_t)round(pwm_xir);
			return pwm_return;
		}

		case ELV: {
			float32_t pwm_eta = -1.0/0.048959*(angle*180.0/PI) + 1500.0;
			uint16_t pwm_return = (uint16_t)round(pwm_eta);
			return pwm_return;
		}

		case RUD: {
			float32_t pwm_zeta = 1.0/0.041879*(angle*180.0/PI) + 1500.0;
			uint16_t pwm_return = (uint16_t)round(pwm_zeta);
			return pwm_return;
		}

	}

	return angle;
}
