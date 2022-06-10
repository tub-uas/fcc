#ifndef SIG_GEN_H
#define SIG_GEN_H

#include <cstdint>
#include <array>

#include "../timer/timer.h"

class SigGen {

public:

	SigGen();
	SigGen(double unitDuration, double offset, double amplitude, double delay);

	~SigGen();

	bool set(double unitDuration, double offset, double amplitude, double delay);
	bool setOffset(double offset);
	double doublet(double time);
	double three211(double time);

	double unitDuration{1.0};
	double offset{0.0};
	double amplitude{0.0};
	double delay{0.0};

private:

};

#endif  // SIG_GEN_H
