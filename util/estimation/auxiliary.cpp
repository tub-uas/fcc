#include "auxiliary.h"
#include <cmath>


#define R_GAS	287.085f
#define T_REF	288.15f
#define P_REF	101325.0f
#define GRAVITY	9.80665f


float isa_height(float p) {
	
	const float coeff = -R_GAS*T_REF/GRAVITY; 

	return coeff*log(p/P_REF);
}

float isa_height_above_gnd(float p, float QFE) {
	return isa_pressurealt(p) - isa_pressurealt(QFE);
}