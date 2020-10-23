#include "sigGen.h"

#include <iostream>
#include <cstring>

SigGen::SigGen() {

}

SigGen::SigGen(double unitDuration, double offset, double amplitude, double delay) {
	this->unitDuration = unitDuration;
	this->offset = offset;
	this->amplitude = amplitude;
	this->delay = delay;
}

SigGen::~SigGen() {

}

bool SigGen::set(double unitDuration, double offset, double amplitude, double delay) {
	this->unitDuration = unitDuration;
	this->offset = offset;
	this->amplitude = amplitude;
	this->delay = delay;

	return true;
}

bool SigGen::setOffset(double offset) {
	this->offset = offset;

	return true;
}

double SigGen::doublet(double time) {

	time -= delay;

	if (0 > time) {
		return offset;
	} else if (unitDuration > time && time >= 0) {
		return offset + amplitude;
	} else if (2.0*unitDuration > time && time >= unitDuration) {
		return offset - amplitude;
	} else if (time >= 2.0*unitDuration) {
		return offset;
	}

	return 0.0;
}

double SigGen::three211(double time) {

	time -= delay;

	if (0 > time) {
		return offset;
	} else if (3.0*unitDuration > time && time >= 0) {
		return offset + amplitude;
	} else if (5.0*unitDuration > time && time >= 3.0*unitDuration) {
		return offset - amplitude;
	} else if (6.0*unitDuration > time && time >= 5.0*unitDuration) {
		return offset + amplitude;
	} else if (7.0*unitDuration > time && time >= 6.0*unitDuration) {
		return offset - amplitude;
	} else if (time >= 7.0*unitDuration) {
		return offset;
	}

	return 0.0;
}
