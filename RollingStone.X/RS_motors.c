/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_MOTOR_C
#define	RS_MOTOR_C

#include "RS_motor.h"

void RS_mot_updateSpeed(int *acc_T, int *speed_T){
   
    speed_T[ID_SPEED_LIN] = RS_mot_calcSpeedLin(acc_T[ID_ACC_Y]);
    speed_T[ID_SPEED_ANG] = RS_mot_calcSpeedAng(acc_T[ID_ACC_X]);
    RS_mot_setSpeed(speed_T[ID_SPEED_LIN], speed_T[ID_SPEED_ANG]);
}

int RS_mot_calcSpeedLin(int acc_Y){
    static int speedLin;
    long s= speedLin;
    s -= K_LIN*acc_Y;
    if (s<MAX_INT && s>MIN_INT) speedLin=s;
    return speedLin;
}

int RS_mot_calcSpeedAng(int acc_X){
    static int speedAng;
    speedAng = K_ANG*acc_X;
    return speedAng;
}

void RS_mot_setSpeed(int speed_lin, int speed_ang){
    int speed_left = speed_lin + speed_ang;
    int speed_right = speed_lin - speed_ang;
    
    if (speed_left <= - MAX_SPEED) speed_left = - MAX_SPEED;
    else if (speed_left >= MAX_SPEED) speed_left = MAX_SPEED;
    if (speed_right <= - MAX_SPEED) speed_right = - MAX_SPEED;
    else if (speed_right >= MAX_SPEED) speed_right = MAX_SPEED;
    
    
    e_set_speed_left(speed_left);
    e_set_speed_right(speed_right);
}
#endif	/* RS_MOTOR_C */