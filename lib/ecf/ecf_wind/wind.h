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
	void update();
	void reinit();
	void reset_state();

	get_wind_north();
	get_wind_east();
	get_wind_down();

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