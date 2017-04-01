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
   
    RS_mot_calcSpeedLin(acc_T[ID_ACC_Y]);
    RS_mot_calcSpeedAng(acc_T[ID_ACC_X]);
}

int RS_mot_calcSpeedLin(int accY){
    int speedLin;
    speedLin += K_LIN*accY;
    return speedLin;
}

int RS_mot_calcSpeedAng(int accX){
    int speedAng;
    speedAng = K_ANG*accX;
    return speedAng;
}
    

#endif	/* RS_MOTOR_C */