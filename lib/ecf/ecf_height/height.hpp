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
#ifndef HEIGHT_H
#define HEIGHT_H

#include <array>

class Height {

public:

	Height();
	~Height();
	void init(double height, double var_height,double acc, double var_acc);
	void update(double height, double acc, double dt);
	void reset();
	void reinit(double height=0.0, double var_height=1.0,double acc=0.0, double var_acc=1.0);
	double get_height();
	double get_height_rate();
private:
	
	std::array<double, 2> _state{{0.0,0.0}};
	std::array<double, 2> _state_last{{0.0,0.0}};
	double _var_height{1.0};
	double _var_acc{1.0};
	
	double _k_height{0.0f};
	double _k_height_rate{0.0f};
	


};

#endif // HEIGHT_H