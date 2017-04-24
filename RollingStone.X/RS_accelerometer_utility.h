/*******************************************************************************
 ********************   RS_accelerometer_utility.h  ****************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 * This file contain the utilities function used by accelerometer.h            *
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once. 
#ifndef _RS_ACCELEROMETER_UTILITY
#define _RS_ACCELEROMETER_UTILITY

//include project files
#include "RS_const.h"


/*******************************************************************************
 ****************************   Constants    ***********************************
 ******************************************************************************/

//function to compute a^2
#define P_2(a)      a*a


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
int RS_acc_mean(int* data, int data_length);


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
long RS_acc_norm(int* acc_T);

#endif //_RS_ACCELEROMETER_UTILITY
