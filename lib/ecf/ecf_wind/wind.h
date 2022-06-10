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

#ifndef WIND_H
#define WIND_H


#include <Eigen/Dense>

class Wind
{
public:

	Wind();
	~Wind();

	void init(Vectord3d X, Matrix3d P, Matrix3d Q, Matrix3d R);
	void reinit(Vectord3d X, Matrix3d P, Matrix3d Q, Matrix3d R);
	void reset_state(void);

	void update(double v_N_n, double v_E_n, double v_D_n);
	

	get_wind_north() { return _X(0); }
	get_wind_east() { return _X(1); }
	get_wind_down() { return _X(2); }

private:

	Vector3d _X_pred;
	Vector3d _X;
	Vector3d _Y;
	Matrix3d _P;
	Matrix3d _P_pred;
	Matrix3d _K;
	Matrix3d _Q;
	Matrix3d _R;
	
	const Matrix3d _I = MatrixXd::Identity(3,3);

	void _prediction();
	void _correction();
}



#endif // WIND_H