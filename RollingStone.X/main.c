/*
 * File:   main.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:45
 */


#include "xc.h"

#include "e_init_port.h"
#include "e_epuck_ports.h"
#include "e_motors.h"
#include "e_ad_conv.h"
#include "e_accelerometer.h"

#include "RS_motor.h"
#include "RS_accelerometer.h"
#include "RS_const.h"

int acc_T[LENGHT_ACC_T];
int speed_T[LENGHT_SPEED_T];


void Init_T2() {
    T2CON = 0;
    T2CONbits.TCKPS=3; // prescaler 256
    TMR2 = 0; // clear timer5
    PR2 = UPDATE_PERIOD; 
    IFS0bits.T2IF = 0; // clear interrupt flag
    IEC0bits.T2IE = 1; // set interrupt enable bit
    T2CONbits.TON = 1; // start timer 5
}

void _ISR __attribute__((no_auto_psv)) _T2Interrupt(void) {
    RS_acc_update(acc_T, speed_T);
    RS_mot_updateSpeed(acc_T, speed_T);
    
    TMR2 = 0; // clear timer5
    IFS0bits.T2IF = 0; // clear interrupt flag
}

int main(void) {
    Init_T2();
    e_init_port();
    e_init_motors();
    while(1) RS_acc_get();
    return 0;
}
