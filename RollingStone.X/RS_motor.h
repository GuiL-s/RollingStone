/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_MOTOR_H
#define	RS_MOTOR_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "RS_const.h"
#include "motor_led/e_motors.h"
#include "RS_accelerometer.h"

    
#define K_LIN       0.15
#define K_ANG       3

#define KP          1
#define KD          1
#define KI          1

#define SP_TO_ACC   1
    
#define MAX_SPEED   1000


void RS_mot_updateSpeed(int* acc_T, int* acc_prev_T, int* speed_T, int* speed_prev_T);
int RS_mot_calcSpeedLin(int* speed_T, int* speed_prev_T, int acc_Y);
int RS_mot_calcSpeedAng(int acc_X);
void RS_mot_setSpeed(int speed_lin, int speed_ang);
void RS_mot_PID(int* speed_T, int* speed_prev_T, int acc_Y);


#endif	/* RS_MOTOR_H */