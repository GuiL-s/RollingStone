/*
 * File:   RS_accelerometer.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:48
 */

#include "RS_accelerometer.h"
#include "RS_accelerometer_utility.h"
#include "motor_led/e_epuck_ports.h"
#include "motor_led/e_init_port.h"

int acc_raw_X[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));//={2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048};
int acc_raw_Y[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));//={2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048};
int acc_raw_Z[LENGHT_RAW_T]  __attribute__((space(xmemory), aligned(32)));//={2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048};
int buff_P=0;

long sum_acc = 0;
int Da_prev = 0;

void RS_acc_get(void){
    e_get_acc(acc_raw_X+buff_P, acc_raw_Y+buff_P, acc_raw_Z+buff_P);
    if(buff_P<(LENGHT_RAW_T-1)) buff_P++ ;
    else buff_P=0;
}

void RS_acc_update(int* acc_T, int* acc_prev_T) {
    int comp;
    comp=acc_T[ID_ACC_Y];
    
    acc_prev_T[ID_ACC_X] = acc_T[ID_ACC_X];
    acc_prev_T[ID_ACC_Y] = acc_T[ID_ACC_Y];
    acc_prev_T[ID_ACC_Z] = acc_T[ID_ACC_Z];
    
    acc_T[ID_ACC_X] = RS_acc_mean(acc_raw_X, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Y] = RS_acc_mean(acc_raw_Y, LENGHT_RAW_T) - ACC_ZERO;
    acc_T[ID_ACC_Z] = RS_acc_mean(acc_raw_Z, LENGHT_RAW_T) - ACC_ZERO;
    
    if((acc_T[ID_ACC_Y]-comp)>SHOCK || (acc_T[ID_ACC_Y]-comp)<-SHOCK) LED6=1;
}

long RS_acc_I(int acc_Y){
   sum_acc += acc_Y;
   return sum_acc;
}

int RS_acc_D(int Da){
    int var_Da = Da - Da_prev;
    Da_prev = Da;
    return var_Da;
}