/*******************************************************************************
 ************************   RS_accelerometer.h  ********************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 * This file contain the function to measure and compute acceleration          *
 * Acceleration is given by the accelerometer of the e-puck (MMA.....)         *
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_ACCELEROMETER_H
#define	RS_ACCELEROMETER_H  


//include e-puck library
#include "a_d/e_ad_conv.h"
#include "a_d/e_accelerometer.h"
#include "motor_led/e_epuck_ports.h"
#include "motor_led/e_init_port.h"

//include project files
#include "RS_const.h"
#include "RS_accelerometer_utility.h"


/*******************************************************************************
 ****************************   Constants    ***********************************
 ******************************************************************************/

//length of buffer
#define LENGHT_RAW_T    60
//value of accelerometer for 0G
#define ACC_ZERO        2048

//limit for detection of shock
#define SHOCK           4194304 //2048^2



/*******************************************************************************
 ****************************   Functions    ***********************************
 ******************************************************************************/


/*******************************************************************************
 **********************   void RS_acc_get(void)    *****************************
 *******************************************************************************
 *  Parameters :                                                               *
 * void                                                                        *
 *                                                                             *
 * Description :                                                               *
 * This function is used to read the value of accelerometer.                   *
 * It saves values on the global buffer acc_raw_X[],acc_raw_Y[],acc_raw_Z[].   *
 * Main function call this function in the infinite loop (while(1)).           *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *
 ******************************************************************************/
void RS_acc_get(void);


/*******************************************************************************
 *********   void RS_acc_update(int* acc_T, int* acc_prev_T)    ****************
 ******************************************************************************* 
 * Parameters :                                                                *
 * acc_T -->    table of acceleration (main.c --> RS_motor.c)                  *
 *              (Step N)                                                       *
 * acc_prev_T --> table of acceleration (main.c --> RS_motor.c)                *
 *              (Step N-1,used by the PID)                                     *
 *                                                                             *
 * Description :                                                               *
 * This function compute the mean of global buffer acc_raw_X/Y/Z[].            *
 * It updates values in tables acc_T and acc_prev_T.                           *
 * It detects shocks by comparing norm of acceleration with a maximal value.   *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void RS_acc_update(int* acc_T, int* acc_prev_T);


/*******************************************************************************
 **********************   void RS_acc_I(int Da)    *****************************
 *******************************************************************************
 * Parameters :                                                                *
 * Da -->    value of error of acceleration on Y axis (expected - measured)    *
 *                                                                             *
 * Description :                                                               *
 * This function compute the integral term (discrete time) for the I component *
 * of the PID : SUM_ACC += DELTA_ACC_N = DELTA_ACC_1 + ... + DELTA_ACC_N       *
 *                                                                             *
 * Return :                                                                    *
 * Actual (updated) value of integral term for PID                             *
 *******************************************************************************/
long RS_acc_I(int acc_Y);


/*******************************************************************************
 **********************   void RS_acc_D(int Da)    *****************************
 *******************************************************************************
 * Parameters :                                                                *
 * Da -->    value of error of acceleration on Y axis (expected - measured)    *
 *                                                                             *
 * Description :                                                               *
 * This function compute the derivative term for the D component of the PID :  *
 * VAR_DA = DA_N -DA_N-1                                                       *
 * 
 * Return :                                                                    *
 * Actual (updated) value of derivative term for PID                           *
 *******************************************************************************/
int RS_acc_D(int Da);

#endif //RS_ACCELEROMETER_H
