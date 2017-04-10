/*
 * File:   RS_accelerometer.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:48
 */

#include "RS_accelerometer.h"

const int RS_acc_mean_table[DATA_RANGE] __attribute__ ((space(ymemory), aligned(32)))=
    {
        //signed <1-1/14>
        //1/1 , 1/2,    1/3,    1/4,    1/5,    1/6,    1/7,  , 1/8  
        0x4000, 0x2000, 0x1555, 0x1000, 0x0CCC, 0x0AAB, 0x0925, 0x0800, 
        //1/9,  1/10,   1/11,   1/12,   1/13,   1/14,   1/15,   1/16 Deuxieme ligne a redefinir
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400
    }; //signed <1-1/14>

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
    int speedToAcc_T[LENGHT_SPEED_T];
    RS_acc_speedToAcc(speed_T, speedToAcc_T);
    acc_T[ID_ACC_X] += speedToAcc_T[ID_SPEED_ANG];
    acc_T[ID_ACC_Y] += speedToAcc_T[ID_SPEED_LIN];
}


int RS_acc_speedToAcc(int *Speed_T, int *SpeedToAcc){
    return 0;
}