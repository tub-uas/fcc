
#include "highpass.h"

bool Highpass::init(double tau, double delta_t) 
{
    _tau   = tau;
    _delta_t = delta_t;
    _alpha = _tau/(_tau+_delta_t);
    _is_init = true;
    return _is_init;
}

double Highpass::update(double u) 
{
    _y = _alpha*_y_last + _alpha*(u-_u_last);
    _y_last = _y;
    _u_last = u;
    return _y;
}

void Highpass::reset()
{
    _alpha = 0.0;
    _tau = 1.0;
    _delta_t = 0.0;
    _y_last = 0.0;
    _u_last = 0.0;
    _y = 0.0;
    _is_init = false;
}

