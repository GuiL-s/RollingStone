/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_CONST_H
#define	RS_CONST_H  

#include <xc.h> // include processor files - each processor file is guarded.  

#define PRESCALER           256
#define UPDATE_FREQUENCY    10 //[Hz]
#define UPDATE_PERIOD       (MILLISEC*1000)/(PRESCALER*UPDATE_FREQUENCY) //[millisecond]
#define DT                  1/UPDATE_FREQUENCY
#define LENGHT_ACC_T    2

#define ID_ACC_X        0
#define ID_ACC_Y        1
#define ID_ACC_Z        2

#define LENGHT_SPEED_T  2

#define ID_SPEED_LIN    0
#define ID_SPEED_ANG    1


#define MAX_INT  32767 
#define MIN_INT  -32768


#endif	/* XC_CONST_H */

