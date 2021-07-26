#include "aoa_ssa.h"


Aoa_ssa::Aoa_ssa()
{
	eye(0,0) = 1.0;
	eye(0,1) = 0.0;
	eye(1,0) = 0.0;
	eye(1,1) = 1.0;
}

Aoa_ssa::~Aoa_ssa()
{

}

void Aoa_ssa::init( Vector2d X0,
					Matrix2d P0,
					double cl0,
					double clalpha,
					double cleta,
					double clq,
					double cybeta,
					double cyp,
					double cyr,
					double cyxi,
					double cyzeta,
					double wingarea,
					double span,
					double mean_chord,
					double mass,
					Matrix2d Q,
					Matrix2d R,
					)
{
	
}

void Aoa_ssa::update(double dt
					double ax,
					double ay,
					double az,

)
{
	_dt = dt;
	_prediction();
	_correction();
}

void Aoa_ssa::reset()
{

}

void Aoa_ssa::reset()
{

}

double Aoa_ssa::get_aoa()
{
	return _alpha;
}

double Aoa_ssa::get_ssa()
{
	return _beta;
}


// == PRIVATE METHODS

double Aoa_ssa::_get_qdynamic()
{
	return _rho/2*_tas*_tas;
}

void Aoa_ssa::_get_trigonomic()
{
	_cosa = std::cos(_alpha_last);
	_sina = std::sin(_alpha_last);
	_cosb = std::cos(_beta_last);
	_sinb = std::sin(_beta_last);
	_cosphi = std::cos(_phi);
	_sinphi = std::sin(_phi);
	_costhe = std::cos(_the);
	_sinthe = std::sin(_the);
}

void Aoa_ssa::_prediction()
{
	double tmp_alpha = _q-(_p*_cosa + _r*_sina)*std::tan(_beta_last) +
						(_gravity*(_cosphi*_costhe*_cosa + _sinthe*_sina) -
						_ax*_sina + az*cosa)/(_tas*_cosb);
	_alpha_pred = _alpha_last + _dt*tmp_alpha;

	double tmp_beta = 1/_tas*(-_ax*_cosa*_sinb+_ay*_sina*_sinb +
						_gravity*(_sinthe*_cosa*_sinb+_costhe*_sinphi*_cosb -
						_costhe*_cosphi*_sina*_sinb)) + _p*_sina-_r*_cosa;
	_beta_pred = _beta_last + _dt*tmp_alpha;

	
	_jacobian_F();

	_P_pred = _F*_P*_F.transpose() + _Q;
}

void Aoa_ssa::_jacobian_F()
{
	_qdyn = _get_qdynamic();

	_F(0,0) = 1.0 + _dt*((_p*_sina - _r*_cosa)*std::tan(_beta_last) + (_gravity*(-_sina*_cosphi*_costhe+_sinthe*_cosa)-_ax*_cosa-_az*_sina)/(_tas*_cosb));
	_F(0,1) = _dt*(-(_p*_cosa+_r*_sina)*_cosb*_cosb+(_gravity*(_cosphi*_costhe*_cosa+_sinthe*_sina)-_ax*_sina+_az*_cosa)/_tas*_sinb/(_cosb*_cosb));
	_F(1,0) = _dt*(1/_tas*(_ax*_sina*_sinb-_az*_cosa*_sinb+_g*(_sinthe*_sina*_sinb-_costhe*_cosphi*_cosa*_sinb))+_p*_cosa+_r*_sina);
	_F(1,1) = 1 + _dt*(1/_tas*(-_ax*_cosa*_cosb-_ay*_sinb-_az*_sina*_cosb+_gravity*(_sinthe*_cosa*_cosb-_costhe*_sinphi*_sinb-_costhe*_cosphi*_sina*_cosb)));

}

void Aoa_ssa::_jacobian_H()
{
	_H(0,0) = _mass*(_ax*_std::cosa(_alpha_pred)+_az*std::sin(_alpha_pred))/(_qdyn*_area)-_clalpha;
	_H(0,1) = 0.0f;
	_H(1,0) = 0.0f;
	_H(1,1) = 1.0f;
}

void Aoa_ssa::_correction()
{
	_jacobian_H();
	Matrix2d tmp = (_H*_P_pred*_H.transpose() + R);
	_K = _P_pred*_H.transpose()*tmp.inverse();
	 

	Vector2d h;
	h(0) = _mass*(_ax*_sina-_az*_cosa)/(_qdyn*_area)-_clalpha*_alpha_pred;
	h(1) = _beta_pred;

	Vector2d z;
	z(0) = _cl0 + _clq*_q*_lmu/(2.0*_tas) + _cleta*_eta;
	z(1) = 1/_cybeta*(_mass*_ay/(_qdyn*_area) - _cyp*_p*_span/(2.0*_tas) - _cyr*_r/(2.0*_tas) - _cyxi*_xi - _cyzeta*_zeta;

	Vector2d X;
	X(0) = _alpha_pred;
	X(1) = _beta_pred;

	X = X + _K*(z-h);
	_alpha = X(0);
	_beta = X(1);
	
	_P = (eye-_K*_H)*_P_pred;

}