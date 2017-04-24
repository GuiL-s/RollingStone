/*******************************************************************************
 ****************************   RS_const.h   ***********************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 * This file contain constants used by motors.c and accelerometer.c            *
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_CONST_H
#define	RS_CONST_H  

#include <xc.h> // include processor files - each processor file is guarded.  


/*******************************************************************************
 ****************************   Constants    ***********************************
 ******************************************************************************/

//constants about frequency and update
#define PRESCALER           256
#define UPDATE_FREQUENCY    10 //[Hz]
#define UPDATE_PERIOD       (MILLISEC*1000)/(PRESCALER*UPDATE_FREQUENCY) //[millisecond]


//lenght of acceleration table
#define LENGHT_ACC_T    3

//ID for acceleration table
#define ID_ACC_X        0
#define ID_ACC_Y        1
#define ID_ACC_Z        2


//lenght of speed table
#define LENGHT_SPEED_T  2

//ID for speed table
#define ID_SPEED_LIN    0
#define ID_SPEED_ANG    1


//limit of int value
#define MAX_INT  32767 
#define MIN_INT  -32768


#endif	/* XC_CONST_H */

