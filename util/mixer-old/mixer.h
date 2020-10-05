#ifndef MIXER_H
#define MIXER_H

// Include Libraries
#include <stdint.h>
#include <stdio.h>

// Constant Definitions
#define ENG  9 // Engine
#define AILL 1 // Aileron Left
#define AILR 2 // Aileron Right
#define ELV  5 // Elevator
#define RUD  6 // Ruder
#define PI   3.1415926535897932384626433

// Function Declaration
float32_t pwm_angle(uint8_t ch_nr,uint16_t pwm);

float32_t pwm_att_angle(uint8_t ch_nr,uint16_t pwm);

uint16_t  angle_pwm(uint8_t ch_nr,float32_t angle);

#endif // MIXER_H
