/* == ESTIMATION CONTROL FILTER LIBRARY - 2021 ================================
 * 
 * Height estimation class
 * 
 * Based on the paper of A.M. Sabatini and V. Genovese
 * A SENSOR FUSION METHOD FOR TRACKING VERTICAL VELOCITY AND HEIGHT BASED ON 
 * INERTIAL AND BAROMETRIC ALTIMETER MEASUREMENTS
 * 
 * ============================================================================
 */

#ifndef AOA_SSA_H
#define AOA_SSA_H

#include <array>
#include <Eigen/Dense>

class Aoa_ssa 
{
public:
	Aoa_ssa();
	Aoa_ssa();

	void init(Vector2d X0,
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
				Matrix2d R,);
	void update();
	void reset();
	void reinit();
	double get_aoa();
	double get_ssa();
private:

	double _get_qdynamic();
	void _get_trigonomic();
	void _prediction();
	void _jacobian_F();
	void _jacobian_H();
	void _correction();

	double _dt;
	double _qdyn;

	double _xi;
	double _eta;
	double _zeta;

	double _alpha{0.0f};
	double _alpha_pred{0.0f};
	double _alpha_last{0.0f};
	double _beta{0.0f};
	double _beta_pred{0.0f};
	double _beta_last{0.0f};

	const double _gravity{9.80665f};
	
	// == GEOMETRIC CONSTANTS
	double _lmu{1.0};
	double _mass{1.0};
	double _area{1.0};
	double _span{1.0};

	// == AERODYNAMIC DERIVATIVES
	double _cl0{1.0};
	double _clalpha{1.0};
	double _cleta{1.0};
	double _clq{1.0};

	double _cybeta{1.0};
	double _cyp{1.0};
	double _cyr{1.0};
	double _cyr{1.0};
	double _cyxi{1.0};
	double _cyzeta{1.0};

	double _p{0.0f};
	double _q{0.0f};
	double _r{0.0f};
	double _ax{0.0f};
	double _ay{0.0f};
	double _az{0.0f};
	double _phi{0.0f};
	double _the{0.0f};
	double _psi{0.0f};
	double _tas{1.0f};
	double _rho{1.225f};

	double _cosa{1.0f};
	double _sina{0.0f};
	double _cosb{1.0f};
	double _sinb{0.0f};
	
	double _sinphi{0.0f};
	double _cosphi{1.0f};
	double _sinthe{0.0f};
	double _costhe{1.0f};

	// MATRICES
	Matrix2d _eye;
	Matrix2d _F;
	Matrix2d _H;
	Matrix2d _P_pred;	
	Matrix2d _P;
	Matrix2d _Q;
	Matrix2d _R;
	Matrix2d _K;
	

};


#endif // AOA_SSA_H
