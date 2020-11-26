#ifndef MIXER_H
#define MIXER_H

#include <cstdint>


class Mixer {
public:

	static constexpr float THR_MAX = 1.0;
	static constexpr float AIL_MAX = 0.3141592654;
	static constexpr float ELE_MAX = 0.3141592654;
	static constexpr float RUD_MAX = 0.3490658504;

	static constexpr float ATT_MULT = 4.0;

	float ail_max_cmd = AIL_MAX * ATT_MULT;
	float ele_max_cmd = ELE_MAX * ATT_MULT;
	float rud_max_cmd = RUD_MAX * ATT_MULT;

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

	enum Func {
		FUNC1 = 0,
		FUNC2,
		FUNC3,
	};

	Mixer();

	Mixer(float ail_max_cmd, float ele_max_cmd, float rud_max_cmd);

	~Mixer();

	float pwm2rad(enum Surface surf, uint16_t pwm, enum Mode mode);

	uint16_t rad2pwm(enum Surface surf, float angle);

	enum Mode pwm2mode(uint16_t pwm);

	uint16_t mode2pwm(enum Mode mode);

	enum Func pwm2func(uint16_t pwm);

	uint16_t func2pwm(enum Func func);


private:


};

#endif  // MIXER_H
