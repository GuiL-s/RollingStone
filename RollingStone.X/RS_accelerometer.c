/*
 * File:   RS_accelerometer.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:48
 */
//#include "xc.h"
#include <a_d/e_accelerometer.h>
#include <RS_accelerometer.h>


int RS_acc_update(int* acc_T) {
    e_get_acc(acc_T+ID_X, acc_T+ID_Y, acc_T+ID_Z);
    acc_T[ID_X]-=2048;
    acc_T[ID_Y]-=2048;
    acc_T[ID_Z]-=2048;
}
