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
}

int RS_mot_calcSpeedLin(int acc_Y){
    static int speedLin;
    speedLin += K_LIN*acc_Y;
    return speedLin;
}

int RS_mot_calcSpeedAng(int acc_X){
    int speedAng;
    speedAng = K_ANG*acc_X;
    return speedAng;
}
    

#endif	/* RS_MOTOR_C */