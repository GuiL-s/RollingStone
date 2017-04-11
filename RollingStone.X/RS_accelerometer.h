/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_ACCELEROMETER_H
#define	RS_ACCELEROMETER_H  

#include "a_d/e_ad_conv.h"
#include "a_d/e_accelerometer.h"
#include "RS_const.h"
#include "RS_accelerometer_utility.h"

#define LENGHT_RAW_T    6
#define ACC_ZERO    2048

void RS_acc_get(void);

void RS_acc_update(int* acc_T, int* speed_T);

void RS_acc_speed_compensation(int* acc_T, int* speed_T);

int RS_acc_speedToAcc(int *Speed_T, int *SpeedToAcc);

#endif
