/************************************************
* Programm "Sensorfusion Funktionsbibliothek"
*
* Autor 1        : Mirkan Etiz
* Autor 2		 : Carlos Giese Bizcocho
* Beschreibung   : Funktionsbibliothek-Datei
* Kompilierbefehl:
************************************************/

//Bibliotheken

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PAS.h"

//Init Acceleration Quaternion
void init_accelquat(float *ptr, float *data){
	if (P2(data) != -1.0) {
		P0(ptr) = sqrt((P2(data) + 1.0) / 2.0);
		P1(ptr) = -P1(data) / sqrt(2.0 * (P2(data) + 1.0));
		P2(ptr) = P0(data) / sqrt(2.0 * (P2(data) + 1.0));
		P3(ptr) = 0.0;
	} else {
		P0(ptr) = -P1(data) / sqrt(2.0 * (1.0 - P2(data)));
		P1(ptr) = sqrt((1.0 - P2(data)) / 2.0);
		P2(ptr) = 0.0;
		P3(ptr) = P0(data) / sqrt(2.0 * (1.0 - P2(data)));
	}
}

//Init Magnetometer Quaternion
// qf is the dyadic product from q_gyr and the corrected q_acc
void init_magquat(float *qf, float *q_mag, float *mag_data, float *corr_mag_data){
	//Calc trafo m --> l, --> into new function

	float matmag[3][3];
	dcm(&matmag[0][0], qf);

	// l = R(q_acc)*m

	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
					*(corr_mag_data+i) += matmag[j][i] * (*(mag_data+j));
			}
	}

	//Init Magneto Quat
	if (P1(corr_mag_data) >= 0) {

			P0(q_mag) = sqrt(GAMMA2(corr_mag_data) + P1(corr_mag_data) * sqrt(GAMMA2(corr_mag_data))) / sqrt(2.0 * GAMMA2(corr_mag_data));
			P1(q_mag) = 0.0;
			P2(q_mag) = 0.0;
			P3(q_mag) = P2(corr_mag_data) / (sqrt(2.0) * sqrt(sqrt(GAMMA2(corr_mag_data) + P1(corr_mag_data) * sqrt(GAMMA2(corr_mag_data)))));

	} else {
			P0(q_mag) = P2(corr_mag_data) / (sqrt(2.0) * sqrt(sqrt(GAMMA2(corr_mag_data) - P1(corr_mag_data) * sqrt(GAMMA2(corr_mag_data)))));
			P1(q_mag) = 0.0;
			P2(q_mag) = 0.0;
			P3(q_mag) = sqrt(GAMMA2(corr_mag_data) - P1(corr_mag_data) * sqrt(GAMMA2(corr_mag_data))) / sqrt(2.0 * GAMMA2(corr_mag_data));
	}
}

//Rotation with Direct Cosine Matrix
void dcm(float *matrptr, float *quatptr) {

		P0(matrptr) = DIAG(P0(quatptr), P1(quatptr), P2(quatptr), P3(quatptr));
		P1(matrptr) = NDIAGN(P1(quatptr) * P2(quatptr), P0(quatptr) * P3(quatptr));
		P2(matrptr) = NDIAGP(P1(quatptr) * P3(quatptr), P0(quatptr) * P2(quatptr));
		P3(matrptr) = NDIAGP(P1(quatptr) * P2(quatptr), P0(quatptr) * P3(quatptr));
		*(matrptr + 4) = DIAG(P0(quatptr), P2(quatptr), P1(quatptr), P3(quatptr));
		*(matrptr + 5) = NDIAGN(P2(quatptr) * P3(quatptr), P0(quatptr) * P1(quatptr));
		*(matrptr + 6) = NDIAGN(P1(quatptr) * P3(quatptr), P0(quatptr) * P2(quatptr));
		*(matrptr + 7) = NDIAGP(P2(quatptr) * P3(quatptr), P0(quatptr) * P1(quatptr));
		*(matrptr + 8) = DIAG(P0(quatptr), P3(quatptr), P1(quatptr), P2(quatptr));
 }

//Inverted Quaternion
void quat_inv(float *quatptr) {
		for (int i = 1; i < 4; i++) {
				*(quatptr + i) = *(quatptr + i) * (-1.0);
		}
}

//Dyadic Product
void dyad(float *quatptr1, float *quatptr2, float *newquatptr) {
		P0(newquatptr) = P0(quatptr1) * P0(quatptr2) - P1(quatptr1) * P1(quatptr2) - P2(quatptr1) * P2(quatptr2) -
										 P3(quatptr1) * P3(quatptr2);
		P1(newquatptr) = P0(quatptr1) * P1(quatptr2) + P1(quatptr1) * P0(quatptr2) + P2(quatptr1) * P3(quatptr2) -
										 P3(quatptr1) * P2(quatptr2);
		P2(newquatptr) = P0(quatptr1) * P2(quatptr2) - P1(quatptr1) * P3(quatptr2) + P2(quatptr1) * P0(quatptr2) +
										 P3(quatptr1) * P1(quatptr2);
		P3(newquatptr) = P0(quatptr1) * P3(quatptr2) + P1(quatptr1) * P2(quatptr2) - P2(quatptr1) * P1(quatptr2) +
										 P3(quatptr1) * P0(quatptr2);
}

//LERP Algorithm
void lerp(float *ptr, float *newptr, float gain) {

		float qi[4] = {1, 0, 0, 0};
		for (int i = 0; i < 4; i++) {
				*(newptr + i) = (1 - gain) * qi[i] + gain * (*(ptr + i));
		}
}

//Normalized Quaternion
void quatnorm(float *ptr, float *newptr) {

		P0(newptr) = P0(ptr) / NORM(ptr);
		P1(newptr) = P1(ptr) / NORM(ptr);
		P2(newptr) = P2(ptr) / NORM(ptr);
		P3(newptr) = P3(ptr) / NORM(ptr);
}

//Accelerometer correction
void accel_corr(float *qw, float *g, float gain, float *qf){

	//Init Quaternions
	float dq_acc[4] = {
					sqrt((P2(g) + 1.0f) / 2.0f),
					-P1(g) / (sqrt(2.0f * (P2(g) + 1.0f))),
					P0(g) / (sqrt(2.0f * (P2(g) + 1.0f))),
					0.0f
	}; //Quat 1

	// for (int i = 0; i < 4; i++){
	//   printf("%f \n", dq_acc[i]);
	// }

	float dq_acc_s[4]; //Quat 2, delta Quaternion Acc Strich Zwischenberechnung
	float dq_acc_norm[4]; //Quat 3, Final Result of Accel Correction

	//Function calls
	lerp(dq_acc, dq_acc_s, gain);
	quatnorm(dq_acc_s, dq_acc_norm);
	dyad(qw, dq_acc_norm, qf);

	// for (int i = 0; i < 4; i++){
	//   printf("%f \n", *(qf+i));
	// }
}

//Magnetometer correction
void mag_corr(float *qf, float *l, float gain, float *qfin){
	//Init quaternions

	float dq_mag[4] = {
					sqrt(GAMMA2(l) + P1(l) * sqrt(GAMMA2(l))) / sqrt(2.0f * GAMMA2(l)),
					0.0f,
					0.0f,
					P2(l) / sqrt(2.0f * (GAMMA2(l) + P1(l) * sqrt(GAMMA2(l))))
	};
	float dq_mag_s[4];
	float dq_mag_norm[4]; //Final Result of magnetometer correction

	//Function calls
	lerp(dq_mag, dq_mag_s, gain);
	quatnorm(dq_mag_s, dq_mag_norm);
	dyad(qf, dq_mag_norm, qfin);
}

// computing p_gyr
void computeOmegaGyr(float Xgyr, float Ygyr, float Zgyr, float OmegaGyr[4][4])
{
		//float OmegaGyr[4][4];
		OmegaGyr[0][0] = 0.0;
		OmegaGyr[0][1] = Xgyr;
		OmegaGyr[0][2] = Ygyr;
		OmegaGyr[0][3] = Zgyr;
		OmegaGyr[1][0] = -Xgyr;
		OmegaGyr[1][1] = 0.0;
		OmegaGyr[1][2] = Zgyr;
		OmegaGyr[1][3] = -Ygyr;
		OmegaGyr[2][0] = -Ygyr;
		OmegaGyr[2][1] = -Zgyr;
		OmegaGyr[2][2] = 0.0;
		OmegaGyr[2][3] = Xgyr;
		OmegaGyr[3][0] = -Zgyr;
		OmegaGyr[3][1] = Ygyr;
		OmegaGyr[3][2] = Xgyr;
		OmegaGyr[3][3] = 0.0;
}
// Todo pass array as pointer
void computeQdot( float OmegaGyr[4][4], float q_prev[4] , float *q_dot)
{

		q_dot[0] =  OmegaGyr[0][0] * q_prev[0] +
								OmegaGyr[0][1] * q_prev[1] +
								OmegaGyr[0][2] * q_prev[2] +
								OmegaGyr[0][3] * q_prev[3];
		q_dot[1] =  OmegaGyr[1][0] * q_prev[0] +
								OmegaGyr[1][1] * q_prev[1] +
								OmegaGyr[1][2] * q_prev[2] +
								OmegaGyr[1][3] * q_prev[3];
		q_dot[2] =  OmegaGyr[2][0] * q_prev[0] +
								OmegaGyr[2][1] * q_prev[1] +
								OmegaGyr[2][2] * q_prev[2] +
								OmegaGyr[2][3] * q_prev[3];
		q_dot[3] =  OmegaGyr[3][0] * q_prev[0] +
								OmegaGyr[3][1] * q_prev[1] +
								OmegaGyr[3][2] * q_prev[2] +
								OmegaGyr[3][3] * q_prev[3];
}

//Prediction with explicit Euler Algorithm
void computeQ(float *q_prev, float *q_dot, float dt, int steps, float * q_gyr)
{

		// numeric solution
		for(int i = 0; i < steps; i++)
		{
				for(int j=0; j<4; j++)
				{
						q_gyr[j] = q_prev[j] + q_dot[j] * dt;
						q_prev[j] = q_gyr[j];
				}
				dt = dt + 10;
		}
}

// compute g for acceleration
void computeG(float *q_dcm, float Xacc, float Yacc, float Zacc, float *g_acc)
{
		g_acc[0] = q_dcm[0] * Xacc + q_dcm[1] * Yacc + q_dcm[2] * Zacc;
		g_acc[1] = q_dcm[3] * Xacc + q_dcm[4] * Yacc + q_dcm[5] * Zacc;
		g_acc[2] = q_dcm[6] * Xacc + q_dcm[7] * Yacc + q_dcm[8] * Zacc;
}
//float strapdown()

// int main() {
//     // is needed for the complementary filter
//     float **OmegaGyr;
//     OmegaGyr = malloc( 4*sizeof( float* ));
//     float *q_prev = malloc(4* sizeof(float));
//     float *q_gyr = malloc(4* sizeof(float));
//     float *q_dot = malloc(4* sizeof(float));
//     float *q_dcm = malloc( 9* sizeof(float));
//
//     // predicted gravity needed in acc-correction
//     float *g_acc = malloc(3* sizeof(float));
//     for(int i = 0; i <4 ; i++){
//         OmegaGyr[i] = malloc( 4* sizeof(float));
//     }
//
//     q_prev[0] = 1.0;
//     q_prev[1] = 0.0;
//     q_prev[2] = 0.0;
//     q_prev[3] = 0.0;
//     float dt = 10.0;
//     int steps = 100;
//
//     //Variables
//     float a[3] = {
//             sub_AHRS.ahrs_accX,
//             sub_AHRS.ahrs_accY,
//             sub_AHRS.ahrs_accZ
//     };  //Measured acceleration from accelerometer
//     float m[3] = {
//             sub_AHRS.ahrs_magX,
//             sub_AHRS.ahrs_magY,
//             sub_AHRS.ahrs_magZ
//     };  //Measured magnetometer data
//     float gyr[3] = {
//             sub_AHRS.ahrs_gyrX,
//             sub_AHRS.ahrs_gyrY,
//             sub_AHRS.ahrs_gyrZ
//     }; // measured gyro data
//     float l[3]; //corrected magnetometer data
//
//     //accelerometer data gp, gp is calculated by a the measured accel, dcm(qw)*a = gp MUSS NOCH IMPLEMENTIERT WERDEN!!
//     float q_acc[4];
//     float q_mag[4];
//     float q[4];
//     float gain1 = 0.5; //gain element of [0,1] for accel correction
//     float gain2 = 0.7; //gain element of [0,1] for mag correction
//     float qf[4]; //Final Result of dyadic multiplication of qw and dq_acc_norm, in paper qf = q'
//     float qfin[4]; //Final quat with corrections applied
//
//     // complimentary filter algorithm with euler
//     computeOmegaGyr(gyr[0],gyr[1],gyr[2],OmegaGyr);
//     computeQdot(OmegaGyr,q_prev,q_dot);
//     computeQ(q_prev,q_dot,dt,steps,q_gyr);
//     dcm(q_dcm, q_gyr);
//     computeG(q_dcm,a[0],a[1],a[2],g_acc);
//     //Init Quat
//     init_accelquat(q_acc, a);
//     accel_corr(q_gyr, g_acc, gain1, qf);
//     init_magquat(qf, q_mag, m, l); //q_mag and l is given values
//     mag_corr(qf, l, gain2, qfin);
//
//     for(int i = 0; i <4 ; i++){
//             printf("Value for q_gyr [%i] : %f \n",i,q_gyr[i]);
//     }
//
//     for(int i = 0; i < 3; i++)
//     {
//         printf("g_acc %f \r\n",g_acc[i]);
//     }
//
//     for(int i = 0; i < 4; i++)
//     {
//         printf("qfin %d %f \r\n", (i+1),g_acc[i]);
//     }
//
//     return 0;
// }
