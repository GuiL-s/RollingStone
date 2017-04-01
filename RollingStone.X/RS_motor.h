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

    
#define K_LIN   0
#define K_ANG   0
    
    
void RS_mot_updateSpeed(int *acc_T, int *speed_T);
int RS_mot_calcSpeedLin(int accY);
int RS_mot_calcSpeedAng(int accX);
    

#endif	/* RS_MOTOR_H */