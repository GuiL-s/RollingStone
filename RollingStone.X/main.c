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
#include "uart/e_uart_char.h"
#include "matlab/matlab.h"

#include "RS_motor.h"
#include "RS_accelerometer.h"
#include "RS_const.h"

int acc_T[LENGHT_ACC_T];
int speed_T[LENGHT_SPEED_T];

#define SIZE_DATA 128
int acc_x[SIZE_DATA];
int acc_y[SIZE_DATA];
int acc_z[SIZE_DATA];

char sense_next=0;

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
    
    
    RS_acc_update(acc_T, speed_T);
    RS_mot_updateSpeed(acc_T, speed_T);
    IFS0bits.T2IF = 0; // clear interrupt flag
    TMR2 = 0; // clear timer5
}


void matlab_uart(){
    int i;
    for(i=0;i<SIZE_DATA;i++)
    {
        sense_next=1;
        e_get_acc(&acc_x[i], &acc_y[i], &acc_z[i]);
        //while(sense_next);
    }
    i=0;
    e_send_int_to_matlab(&i,1);
    e_send_int_to_matlab(acc_x,SIZE_DATA);
    e_send_int_to_matlab(acc_y,SIZE_DATA);
    e_send_int_to_matlab(acc_z,SIZE_DATA);
    while(e_uart1_sending());
}

void init_TMR1(void)
{
	T1CON = 0; //
	T1CONbits.TCKPS=2; // prescaler = 64
	TMR1 = 0; // clear timer 5
	PR1 = (3*MILLISEC)/64.0; // interrupt every 1000ms
	IFS0bits.T1IF = 0; // clear interrupt flag
	IEC0bits.T1IE = 1; // set interrupt enable bit
	T1CONbits.TON = 1; // start Timer5
}

void _ISR __attribute__((no_auto_psv)) _T1Interrupt(void)
{
	IFS0bits.T1IF = 0; // clear interrupt flag
	sense_next=0;
}

int main(void) {
    Init_TMR2();
    //init_TMR1();
    e_init_port();
    e_init_motors();
    e_init_acc();
    e_init_uart1();
	e_init_ad();
        
    while(1){
        //matlab_uart();
        RS_acc_get();
    }
    return 0;
}