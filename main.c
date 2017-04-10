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
/*
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
*/
int i;

int main(void) {
    //Init_T2();
    e_init_port();
    e_init_acc();
	e_init_uart1();
	e_init_ad();
    e_init_motors();

	//init_TMR5();
	
	while(1)
	{
		for(i=0;i<SIZE_DATA;i++)
		{
			sense_next=1;
			e_get_acc(&acc_x[i], &acc_y[i], &acc_z[i]);
			while(sense_next);
		}
		i=0;
		e_send_int_to_matlab(&i,1);
		e_send_int_to_matlab(acc_x,SIZE_DATA);
		e_send_int_to_matlab(acc_y,SIZE_DATA);
		e_send_int_to_matlab(acc_z,SIZE_DATA);
		while(e_uart1_sending());
	}
}