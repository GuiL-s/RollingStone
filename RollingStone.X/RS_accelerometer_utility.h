
#ifndef _RS_ACCELEROMETER_UTILITY
#define _RS_ACCELEROMETER_UTILITY

#include "RS_const.h"

#define DATA_RANGE  16

#define P_2(a)      a*a
#define MAX_ANG     2048
#define SHOCK_ACC   3000

int RS_acc_mean(int* data, int data_length);
long RS_acc_norm(int* acc_T);

#endif //_RS_ACCELEROMETER_UTILITY
