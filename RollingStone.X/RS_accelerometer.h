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

#define LENGHT_RAW_T    60
#define ACC_ZERO        2048
#define SHOCK           3000

void RS_acc_get(void);

void RS_acc_update(int* acc_T, int* acc_prev_T);

long RS_acc_I(int acc_Y);

int RS_acc_D(int Da);

#endif
