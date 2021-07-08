#include "wind.hpp"



Wind::Wind()
{

}

Wind::~Wind()
{

}

void Wind::init(Vector2d X, Matrix3d P, Matrix3d Q, Matrix3d R)
{
	_X = X;
	_P = P;
	
	_Q = Q;
	_R = R;


}

void Wind::update(double v_N_n, double v_E_n, double v_D_n)
{
	_Y(1) = v_N_n;
	_Y(2) = v_E_n;
	_Y(3) = v_D_n;
	_prediction();
	_correction();

}

void Wind::reinit(Vector2d X, Matrix3d P, Matrix3d Q, Matrix3d R)
{
	reset_state();
	init(X,P,Q,R);
}

void Wind::reset_state()
{
	_X(0) = 0.0f;
	_X(1) = 0.0f;
	_X(2) = 0.0f;
}


void Wind::get_wind_north()
{
	return _X(0);
}

void Wind::get_wind_east()
{
	return _X(1);
}

void Wind::get_wind_down()
{
	return _X(2);
}

void Wind::_prediction()
{
	_X_pred = _X;
	_P_pred = _P + _Q;
}

void Wind::_correct()
{
	Matrix3d tmp = _P_pred + _R;
	_K = _P_pred*tmp.inverse();

	_X = _X_pred + _K*(_Y-_X_Pred);
	_P = (_I-_K)*_P_pred;
}