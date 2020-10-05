#include "sigGen.h"

/**
 * @brief Construct a new Sig Gen:: Sig Gen object
 *
 * @param mode
 * @param timeSteps
 * @param amplitude
 */
SigGen::SigGen(sigMode_t mode, unsigned long long timeSteps, float amplitude) {

	_mode       = mode;
	_state      = INACTIV;
	_timeSteps  = timeSteps;
	_amplitude  = amplitude;
}

/**
 * @brief Destroy the Sig Gen:: Sig Gen object
 *
 */
SigGen::~SigGen() {
	_state = INACTIV;
}


/**
 * @brief Run the signalgenerator until finished
 *
 * @param time              - current system time
 * @param baseDeflection    - trimmed deflection when Signalgenerator is called
 * @return float            - delfection value for actuator
 */
float SigGen::run(unsigned long long time, float baseDeflection) {
	if(_state == INACTIV) {
		_startTime = time;
		_state = ACTIV;
	}
	switch(_mode) {
		case LONGITUDINAL:                                      // 3-2-1-1 Input
			if(_elapsedTime(time) < 3*_timeSteps) {             // 3 TimeSteps
				return _amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 5*_timeSteps) {        // 2 TimeSteps
				return -_amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 6*_timeSteps) {        // 1 TimeStep
				return _amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 7*_timeSteps) {        // 1 TimeStep
				return -_amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 8*_timeSteps) {        // 1 TimeStep to 0
				return baseDeflection;
			}
			else {          // STOP SIGGEN
				stop();
				 return baseDeflection;
			}
			break;

		case LATERAL:                                           // Doublet Input
			if(_elapsedTime(time) < _timeSteps) {
				return _amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 2*_timeSteps) {
				return -_amplitude + baseDeflection;
			}
			else if(_elapsedTime(time) < 3*_timeSteps) {
				return + baseDeflection;
			}
			else {
				stop();
				return baseDeflection;
			}

			break;


	}

}

/**
 * @brief Stop Signalgenerator when activ
 *
 */
void SigGen::stop(void) {
	if(_state == ACTIV) {
		reset();
	}
	return;
}

/**
 * @brief Reset Signalgenerator parameter (default LONGITUDINAL mode)
 *
 */
void SigGen::reset(void) {
	
	_state          = INACTIV;
	_timeSteps      = 0;
	_startTime      = 0;
	_amplitude      = 0;
	_baseDeflection = 0;
	return;
}

/**
 * @brief Computing timevalues between Signalgeneratorstart and current time
 *
 * @param time                  - current system time value
 * @return unsigned long long   - elapsed time from Signalgenerator start
 */
unsigned long long SigGen::_elapsedTime(unsigned long long time) {
	return time - _startTime;
}
