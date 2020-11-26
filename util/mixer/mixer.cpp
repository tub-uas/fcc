#include "mixer.h"

#include <iostream>

Mixer::Mixer() {

}

Mixer::Mixer(float ail_max_cmd, float ele_max_cmd, float rud_max_cmd) {
	this->ail_max_cmd = ail_max_cmd;
	this->ele_max_cmd = ele_max_cmd;
	this->rud_max_cmd = rud_max_cmd;
}

Mixer::~Mixer() {

}

float Mixer::pwm2rad(enum Surface surf, uint16_t pwm, enum Mode mode) {

	if (pwm > 2200 || pwm < 800) {
		std::cout << "Mixer pwm2rad error, pwm out of bounds " << pwm << std::endl;
		return -69.0;
	}

	switch (mode) {
		case MAN:
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
			break;

		case ATT:
		case NAV:
			switch (surf) {
				case THR:
					return ((pwm - 1000.0) / 1000.0) * THR_MAX;

				case AILR:
					return ((pwm - 1500.0) / 500.0) * -ail_max_cmd;

				case AILL:
					return ((pwm - 1500.0) / 500.0) * ail_max_cmd;

				case ELE:
					return ((pwm - 1500.0) / 500.0) * -ele_max_cmd;

				case RUD:
					return ((pwm - 1500.0) / 500.0) * rud_max_cmd;

				case FLP:
					// TODO not yet implemented

				default:
					std::cout << "Mixer pwm2rad error, unkown surface" << std::endl;
					break;
			}
			break;

		case INV:
		default:
			std::cout << "Mixer pwm2rad error, unkown mode" << std::endl;
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

enum Mixer::Func Mixer::pwm2func(uint16_t pwm) {

	if (pwm > 800 && pwm < 1250) {
		return FUNC1;

	} else if (pwm >= 1250 && pwm <= 1750) {
		return FUNC2;

	} else if (pwm > 1750 && pwm < 2200) {
		return FUNC3;
	}

	std::cout << "Mixer pwm2func error, pwm out of bounds " << pwm << std::endl;
	return FUNC1;
}

uint16_t Mixer::func2pwm(enum Func func) {

	switch (func) {
		case FUNC1:
			return 1900;

		case FUNC2:
			return 1500;

		case FUNC3:
			return 1100;

		default:
			std::cout << "Mixer func2pwm error, unkown func" << std::endl;
			break;
	}

	return 0;
}
