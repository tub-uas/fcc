/* == ESTIMATION CONTROL FILTER LIBRARY - 2021 ================================
 * 
 * Height estimation class
 * 
 * Based on the paper of sabatini ...
 * 
 * 
 * 
 * 
 * ============================================================================
 */

#include "height.h"
#include <math.h>


Height::Height() 
{

}

Height::~Height()
{

}

void Height::init(double height, double var_height, double var_acc)
{
	_state_last[0] = height;
	_state_last[1] = 0.0f;
	_k_height = std::sqrt(2*var_acc/var_height);
	_k_height_rate = var_acc/var_height;
}

void Height::update(double height, double acc, double dt)
{
	double delta_height = height - _state_last[0];
	double delta_height_rate = dt*acc;
	_state[0] = _state_last[0] + dt* _state_last[1] + (_k_height + _k_height_rate*dt/2)*dt*delta_height + dt/2*delta_height_rate;
	_state[1] = _state_last[1] +  _k_height_rate*dt/2*dt*delta_height + delta_height_rate;
}	

void Height::reset()
{
	_state[0] = 0.0;
	_state[1] = 0.0;
	_state_last[0] = 0.0;
	_state_last[1] = 0.0;
	_var_height = 1.0f;
	_var_acc = 1.0f;
}

void Height::reinit(double height, double var_height, double var_acc)
{
	reset();
	init(height,var_height,var_acc);
}

double Height::get_height()
{
	return _state[0];
}

double Height::get_height_rate()
{
	return _state[1];
}