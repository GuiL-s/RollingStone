/*******************************************************************************
 ********************   RS_accelerometer_utility.c  ****************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 * This file contain the utilities function used by accelerometer.c            *
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_ACCELEROMETER_UTILITY_C
#define RS_ACCELEROMETER_UTILITY_C

#include "RS_accelerometer_utility.h"


/*******************************************************************************
 ****************************   Functions    ***********************************
 ******************************************************************************/

/*******************************************************************************
 ***********   int RS_acc_mean(int* data, int data_length)    ******************
 *******************************************************************************
 *  Parameters :                                                               *
 * data --> table of data                                                      *
 * data_length --> length of data                                              *
 *                                                                             *
 * Description :                                                               *
 * This function is used to compute the average of a buffer                    *
 *                                                                             *
 * Return :                                                                    *
 * The mean of the table                                                       *
 ******************************************************************************/
int RS_acc_mean(int* data, int data_length) {
    int i, mean;
    long int sum=0; 
    for(i=0; i<data_length; i++)    sum+=data[i];
    mean=(int)(sum/data_length);
    return mean;
}


/*******************************************************************************
 ******************   long RS_acc_norm(int* acc_T)   ***************************
 *******************************************************************************
 *  Parameters :                                                               *
 * acc_T --> table of acceleration (3 int --> acceleration X/Y/Z)              *
 *                                                                             *
 * Description :                                                               *
 * This function is used to compute the norm (^2) of a vector in R^3           *
 *                                                                             *
 * Return :                                                                    *
 * Norm^2 of the vector (table : acc_T)                                        *
 ******************************************************************************/
long RS_acc_norm(int* acc_T){
    long X_2 = P_2(acc_T[ID_ACC_X]);
    long Y_2 = P_2(acc_T[ID_ACC_Y]);
    long Z_2 = P_2(acc_T[ID_ACC_Z]);
    
    long norm = X_2 + Y_2 + Z_2;
    
    return norm;
}

#endif // _RS_ACCELEROMETER_UTILITY_C