#ifndef SIGGEN_H
#define SIGGEN_H

typedef enum {
	LONGITUDINAL,
	LATERAL,
} sigMode_t;

typedef enum {
	INACTIV,
	ACTIV
} sigState_t;

class SigGen
{
public:
	SigGen(sigMode_t mode, unsigned long long timeSteps, float amplitude);
	~SigGen();

	float   run(unsigned long long time, float baseDeflection);
	void    stop(void);
	void    reset(void); // <- necessary?

private:

	sigMode_t           _mode;
	sigState_t          _state;
	unsigned long long  _timeSteps;
	unsigned long long  _startTime;

	float               _amplitude;
	float               _baseDeflection;

	// == METHODS =============================================================
	unsigned long long  _elapsedTime(unsigned long long time);

};





#endif // SIGGEN_H
