/*******************************************************************************
 ******************************   main.c   *************************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 ******************************************************************************/


#include "xc.h"

#include "motor_led/e_init_port.h"
#include "motor_led/e_epuck_ports.h"
#include "motor_led/e_motors.h"
#include "a_d/e_ad_conv.h"
#include "a_d/e_accelerometer.h"

#include "RS_debug.h"
#include "RS_motors.h"
#include "RS_accelerometer.h"
#include "RS_const.h"

int acc_T[LENGHT_ACC_T];
int speed_T[LENGHT_SPEED_T];
int acc_prev_T[LENGHT_ACC_T];


/*******************************************************************************
 *******   void _ISR __attribute__((no_auto_psv)) _T2Interrupt(void)    ********
 ******************************************************************************* 
 * Parameters :                                                                *
 * void                                                                        *
 * Description :                                                               *
 * This function initialize timer 2.                                           *
 * Timer 2 is used for update speed                                            *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void Init_TMR2() {
    T2CON = 0;
    T2CONbits.TCKPS=3; // prescaler 256
    TMR2 = 0; // clear timer5
    PR2 = UPDATE_PERIOD; 
    IFS0bits.T2IF = 0; // clear interrupt flag
    IEC0bits.T2IE = 1; // set interrupt enable bit
    T2CONbits.TON = 1; // start timer 5
}

/*******************************************************************************
 *******   void _ISR __attribute__((no_auto_psv)) _T2Interrupt(void)    ********
 ******************************************************************************* 
 * Parameters :                                                                *
 * void                                                                        *
 *                                                                             *
 * Description :                                                               *
 * Callback for timer 2.                                                       *
 * This function update averaged value of acceleration and update speed        *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void _ISR __attribute__((no_auto_psv)) _T2Interrupt(void) {
    RS_acc_update(acc_T, acc_prev_T);
    RS_mot_updateSpeed(acc_T, acc_prev_T, speed_T);
    IFS0bits.T2IF = 0; // clear interrupt flag
    TMR2 = 0; // clear timer5
}

/*******************************************************************************
 *************************   void RS_init(void)    *****************************
 ******************************************************************************* 
 * Parameters :                                                                *
 * void                                                                        *
 *                                                                             *
 * Description :                                                               *
 * This function initializes ports/motors/accelerometer                        *
 * It initializes the buffer of acceleration with the call of RS_acc_get()     *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void RS_init(void){
    e_init_port();
    e_init_motors();
    e_init_acc();
	e_init_ad();
    init_matlab();
    int i;
    for (i=0; i< LENGHT_RAW_T; i++) RS_acc_get();
    Init_TMR2();
}

int main(void) {
    RS_init();
            
    while(1){
        RS_acc_get();
        matlab_uart(acc_T, acc_prev_T);
    }
    return 0;
}