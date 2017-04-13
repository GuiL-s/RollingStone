/*
 * File:   debug.c
 * Author: GuiLs
 *
 * Created on 13. avril 2017, 08:15
 */

#include "RS_debug.h"

int acc_x[SIZE_DATA];
int acc_y[SIZE_DATA];
int acc_z[SIZE_DATA];
char sense_next=0;


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

void init_TMR1(void){
	T1CON = 0; //
	T1CONbits.TCKPS=2; // prescaler = 64
	TMR1 = 0; // clear timer 5
	PR1 = (3*MILLISEC)/64.0; // interrupt every 1000ms
	IFS0bits.T1IF = 0; // clear interrupt flag
	IEC0bits.T1IE = 1; // set interrupt enable bit
	T1CONbits.TON = 1; // start Timer5
}


void _ISR __attribute__((no_auto_psv)) _T1Interrupt(void){
	IFS0bits.T1IF = 0; // clear interrupt flag
	sense_next=0;
}


void init_matlab(void){
    init_TMR1();
    e_init_uart1();
}