#include "mixer.h"

#include <iostream>

Mixer::Mixer() {

}

Mixer::~Mixer() {

}

float Mixer::pwm2rad(enum Surface surf, uint16_t pwm) {

	if (pwm > 2200 || pwm < 800) {
		std::cout << "Mixer pwm2rad error, pwm out of bounds " << pwm << std::endl;
		return -69.0;
	}

	switch (surf) {
		case THR:
			return ((pwm - 1000.0) / 1000.0) * THR_MAX;

		case AILR:
			return ((pwm - 1500.0) / 500.0) * -AIL_MAX;

		case AILL:
			return ((pwm - 1500.0) / 500.0) * AIL_MAX;

		case ELE:
			return ((pwm - 1500.0) / 500.0) * -ELE_MAX;

		case RUD:
			return ((pwm - 1500.0) / 500.0) * RUD_MAX;

		case FLP:
			// TODO not yet implemented

		default:
			std::cout << "Mixer pwm2rad error, unkown surface" << std::endl;
			break;
	}

	return -69.0;
}

uint16_t Mixer::rad2pwm(enum Surface surf, float angle) {

	uint16_t pwm = 0;

	switch (surf) {
		case THR:
			return (uint16_t)(((angle / THR_MAX) * 1000.0) + 1000.0);

		case AILR:
			return (uint16_t)(((angle / -AIL_MAX) * 500.0) + 1500.0);

		case AILL:
			return (uint16_t)(((angle / AIL_MAX) * 500.0) + 1500.0);

		case ELE:
			return (uint16_t)(((angle / -ELE_MAX) * 500.0) + 1500.0);

		case RUD:
			return (uint16_t)(((angle / RUD_MAX) * 500.0) + 1500.0);

		case FLP:
			// TODO not yet implemented

		default:
			std::cout << "Mixer rad2pwm error, unkown surface" << std::endl;
			break;
	}

	if (pwm > 2200 || pwm < 800) {
		std::cout << "Mixer rad2pwm error, pwm out of bounds " << pwm << std::endl;
		return 0;
	}

	return pwm;
}

enum Mixer::Mode Mixer::pwm2mode(uint16_t pwm) {

	if (pwm > 800 && pwm < 1250) {
		return NAV;

	} else if (pwm >= 1250 && pwm <= 1750) {
		return ATT;

	} else if (pwm > 1750 && pwm < 2200) {
		return MAN;
	}

	std::cout << "Mixer pwm2mode error, pwm out of bounds " << pwm << std::endl;
	return INV;
}

uint16_t Mixer::mode2pwm(enum Mode mode) {

	switch (mode) {
		case MAN:
			return 1900;

		case ATT:
			return 1500;

		case NAV:
			return 1100;

		case INV:
		default:
			std::cout << "Mixer mode2pwm error, unkown mode" << std::endl;
			break;
	}

	return 0;
}
