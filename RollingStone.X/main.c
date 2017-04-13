/*
 * File:   main.c
 * Author: GuiLs
 *
 * Created on 29. mars 2017, 16:45
 */


#include "xc.h"

#include "motor_led/e_init_port.h"
#include "motor_led/e_epuck_ports.h"
#include "motor_led/e_motors.h"
#include "a_d/e_ad_conv.h"
#include "a_d/e_accelerometer.h"

#include "RS_motor.h"
#include "RS_accelerometer.h"
#include "RS_const.h"

int acc_T[LENGHT_ACC_T];
int speed_T[LENGHT_SPEED_T];
int acc_prev_T[LENGHT_ACC_T];
int speed_prev_T[LENGHT_SPEED_T];


void Init_TMR2() {
    T2CON = 0;
    T2CONbits.TCKPS=3; // prescaler 256
    TMR2 = 0; // clear timer5
    PR2 = UPDATE_PERIOD; 
    IFS0bits.T2IF = 0; // clear interrupt flag
    IEC0bits.T2IE = 1; // set interrupt enable bit
    T2CONbits.TON = 1; // start timer 5
}

void _ISR __attribute__((no_auto_psv)) _T2Interrupt(void) {
    RS_acc_update(acc_T, acc_prev_T);
    RS_mot_updateSpeed(acc_T, acc_prev_T, speed_T, speed_prev_T);
    IFS0bits.T2IF = 0; // clear interrupt flag
    TMR2 = 0; // clear timer5
}
void RS_init(void){
    e_init_port();
    e_init_motors();
    e_init_acc();
	e_init_ad();
    int i;
    for (i=0; i< LENGHT_RAW_T; i++) RS_acc_get();
    Init_TMR2();
}

int main(void) {
    RS_init();
            
    while(1){
        RS_acc_get();
    }
    return 0;
}