#ifndef ESTIMATOR_ROC_H
#define ESTIMATOR_ROC_H

#include <cstdint>
#include <array>

class Roc {
public:
	Roc(float h_init, float roc_init, float sigma_press, float sigma_acc_z);
	~Roc() {};

	float get_h_est(void);
	float get_roc_est(void);
	void update(float h_baro, float acc_z_n, float dt);

private:

	float _sigma_press;
	float _sigma_acc_z_n;
	
	std::array<float,2> K = {};

	float _h_est;
	float _h_old;

	float _roc_est;
	float _roc_old;

};

#endif // ESTIMATOR_ROC_H