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

    
#define K_LIN       0.05
#define K_ANG       3

#define SP_TO_ACC   1
    
#define MAX_SPEED   500
#define MAX_INT 0x7FFF
#define MIN_INT 0x8000


void RS_mot_updateSpeed(int *acc_T, int *speed_T);
int RS_mot_calcSpeedLin(int acc_Y);
int RS_mot_calcSpeedAng(int acc_X);
void RS_mot_setSpeed(int speed_lin, int speed_ang);


#endif	/* RS_MOTOR_H */