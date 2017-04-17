/*******************************************************************************
 ************************   RS_accelerometer.c  ********************************
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
#ifndef RS_ACCELEROMETER_C
#define	RS_ACCELEROMETER_C  

#include "RS_accelerometer.h"

/*******************************************************************************
 ************************   Global variables    ********************************
 ******************************************************************************/

//these 3 tables are used to save the values read on the accelerometer
//to diminuate the impact of the noise take the average of these values
int acc_raw_X[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
int acc_raw_Y[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
int acc_raw_Z[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
//pointer on the table
int buff_P=0;

//variables for a PID calculation
long sum_acc = 0;
int Da_prev = 0;


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
void RS_acc_get(void){
    e_get_acc(acc_raw_X+buff_P, acc_raw_Y+buff_P, acc_raw_Z+buff_P);
    if(buff_P<(LENGHT_RAW_T-1)) buff_P++ ;
    else buff_P=0;
}


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
void RS_acc_update(int* acc_T, int* acc_prev_T) {    
    
    //update of acc_prev_T : acc_N-2 <-- acc_N-1
    acc_prev_T[ID_ACC_X] = acc_T[ID_ACC_X];
    acc_prev_T[ID_ACC_Y] = acc_T[ID_ACC_Y];
    acc_prev_T[ID_ACC_Z] = acc_T[ID_ACC_Z];
    
    //calculation of average and update of acc_T : acc_N <-- mean_acc
    acc_T[ID_ACC_X] = RS_acc_mean(acc_raw_X, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Y] = RS_acc_mean(acc_raw_Y, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Z] = RS_acc_mean(acc_raw_Z, LENGHT_RAW_T) - ACC_ZERO;
    
    
    //test to detect shocks : norm = acc_X^2 + acc_Y^2 + acc_Z^2
    // shock : norm > SHOCK (MAX_NORM_VALUE^2 = 2048^2)
    long norm = RS_acc_norm(acc_T);
    if(norm>SHOCK) LED5=1;
    else LED5=0;
}


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
long RS_acc_I(int Da){
   sum_acc += Da;
   return sum_acc;
}


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
int RS_acc_D(int Da){
    int var_Da = Da - Da_prev;
    Da_prev = Da;
    return var_Da;
}

#endif //RS_ACCELEROMETER_C