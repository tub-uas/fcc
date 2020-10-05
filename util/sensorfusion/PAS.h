/************************************************
* Programm "Sensorfusion Funktionsbibliothek"
*
* Autor 1        : Mirkan Etiz
* Autor 2		 : Carlos Giese Bizcocho
* Beschreibung   : Funktionsbibliothek-Datei
* Kompilierbefehl:
************************************************/

#ifndef PAS_H
#define PAS_H

//Makros
#define P0(ptr) (*ptr)
#define P1(ptr) (*(ptr+1))
#define P2(ptr) (*(ptr+2))
#define P3(ptr) (*(ptr+3))

#define DIAG(wert1, wert2, wert3, wert4) (wert1*wert1+wert2*wert2-wert3*wert3-wert4*wert4)
#define NDIAGP(wert1, wert2) (2*(wert1 + wert2))
#define NDIAGN(wert1, wert2) (2*(wert1 - wert2))

#define NORM(ptr) (sqrt(pow(P0(ptr), 2) + pow(P1(ptr), 2) + pow(P2(ptr), 2) + pow(P3(ptr), 2)))
#define GAMMA (sqrt(l[1]*l[1] + l[2]*l[2]))
#define GAMMA2(ptr) (sqrt(P1(ptr)*P1(ptr) + P2(ptr)*P2(ptr)))

//Initialization Acceleration Quaternion
void init_accelquat(float *ptr, float *data);

//Initialization Magnetometer Quaternion
void init_magquat(float *q_acc, float *q_mag, float *mag_data, float *corr_mag_data);

//Rotation with Direct Cosine Matrix
void dcm(float *matrptr, float *quatptr);

//Inverted Quaternion
void quat_inv(float *quatptr);

//Dyadic Product Minusse korrigieren
void dyad(float *quatptr1, float *quatptr2, float *newquatptr);

//LERP Algorithm
void lerp(float *ptr, float *newptr, float gain);

//Normalized Quaternion
void quatnorm(float *ptr, float *newptr);

//Accelerometer correction
void accel_corr(float *qw, float *g, float gain1, float *qf);

//Magnetometer correction
void mag_corr(float *qf, float *l, float gain, float *qfin);

// part of calculation from q_gyr
void computeOmegaGyr(float Xgyr, float Ygyr, float Zgyr, float OmegaGyr[4][4]);

// part of calculation from q_gyr
void computeQdot( float OmegaGyr[4][4], float q_prev[4] , float *q_dot);

//Prediction with explicit Euler Algorithm
void computeQ(float *q_prev, float *q_dot, float dt, int steps, float * q_gyr);

// compute g for acceleration
void computeG(float *q_dcm, float Xacc, float Yacc, float Zacc, float *g_acc);

#endif // PAS_H
