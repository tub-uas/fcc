#include "lowpass.h"

bool Lowpass::init(double tau, double delta_t)
{
    _tau = tau;
    _delta_t = delta_t;
    _alpha = _tau/(_tau+_delta_t);
    _is_init = true;
    return _is_init;
}

double Lowpass::update(double u)
{
    _y = _alpha*_y_last + (1-_alpha)*u;
    _y_last = _y;
    return _y;
}

void Lowpass::reset()
{
    _alpha = 0.0;
    _tau = 1.0;
    _delta_t = 0.0;
    _y_last = 0.0;
    _y = 0.0;
    _is_init = false;
}