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


#define LENGHT_RAW_T    8
#define ACC_ZERO    2048
void RS_acc_update(int* acc_T, int* speed_T);


#endif
