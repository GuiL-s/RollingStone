/*
 * File:   RS_accelerometer.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:48
 */
//#include "xc.h"
#include <a_d/e_accelerometer.h>
#include "RS_accelerometer.h"
#include "RS_const.h"
#include "RS_accelerometer_utility.h"

int acc_raw_X[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
int acc_raw_Y[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
int acc_raw_Z[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));
int buff_P=0;

void RS_acc_update(int* acc_T, int* speed_T) {
    e_get_acc(acc_raw_X+buff_P, acc_raw_Y+buff_P, acc_raw_Z+buff_P);
    
    acc_T[ID_ACC_X] = RS_acc_mean(acc_raw_X, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Y] = RS_acc_mean(acc_raw_Y, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Z] = RS_acc_mean(acc_raw_Z, LENGHT_RAW_T) - ACC_ZERO;
}

void RS_acc_speed_compensation(int* acc_T, int* speed_T) {
    
}
