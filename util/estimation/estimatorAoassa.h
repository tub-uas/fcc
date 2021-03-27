#ifndef ESTIMATOR_AOA_SSA_H
#define ESTIMATOR_AOA_SSA_H



/**
 * @brief Angle of Attack estimation using a complementary filter
 *        from "Design and Evaluation of UAV Flow Angle Estimation
 *        Filters" by Pengzhi Tian, Haiyang Chao, Patrick Flanagan,
 *        Steven G. Hagerott, Yu Gu in IEEE
 *
 *        Accelerations must be corrected by g - units in m/s^2
 */
class Aoa {
public:
	Aoa(float m, float S, float c, float C_L_0, float C_L_q, float C_L_delta_elev, float C_L_alpha);
	~Aoa() {};

	float estimate(float acc_x, float acc_z, float q_dyn,float V, float q, float elev);
private:
	float _m;
	float _S;
	float _c;
	float _C_L_0;
	float _C_L_delta_elev;
	float _C_L_q;
	float _C_L_alpha;
	float _alpha_hat;
};

/**
 * @brief Sideslip Angle estimation using a complementary filter
 *        from "Design and Evaluation of UAV Flow Angle Estimation
 *        Filters" by Pengzhi Tian, Haiyang Chao, Patrick Flanagan,
 *        Steven G. Hagerott, Yu Gu in IEEE
 *
 *        Accelerations must be corrected by g - units in m/s^2
 */
class Ssa {
public:
	Ssa(float m, float S, float b, float C_Y_0, float C_Y_beta, float C_Y_p, float C_Y_r, float C_Y_delta_ail, float C_Y_delta_rud);
	~Ssa() {};

	float estimate(float acc_y, float q_dyn, float V, float p, float r, float aill, float rudd);
private:
	float _m;
	float _S;
	float _b;

	float _C_Y_0;
	float _C_Y_beta;
	float _C_Y_p;
	float _C_Y_r;
	float _C_Y_delta_ail;
	float _C_Y_delta_rud;
	
	float _beta_hat;
};


#endif // ESTIMATOR_AOA_SSA_H