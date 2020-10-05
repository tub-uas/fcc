#ifndef MIXER_H
#define MIXER_H

#include <cstdint>


class Mixer {
public:

	static constexpr float THR_MAX = 1.0;
	static constexpr float AIL_MAX = 0.3141592654;
	static constexpr float ELE_MAX = 0.3141592654;
	static constexpr float RUD_MAX = 0.3490658504;

	enum Surface {
		THR = 0,
		AILR,
		AILL,
		ELE,
		RUD,
		FLP,
	};

	enum Mode {
		INV = -1,
		MAN = 0,
		ATT,
		NAV,
	};

	Mixer();

	~Mixer();

	float pwm2rad(enum Surface surf, uint16_t pwm);

	uint16_t rad2pwm(enum Surface surf, float angle);

	enum Mode pwm2mode(uint16_t pwm);

	uint16_t mode2pwm(enum Mode mode);



private:


};

#endif  // MIXER_H
