#include <p30Fxxxx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "motor_led/motors2.h"
#include "motor_led/e_init_port.h"
#include "motor_led/e_epuck_ports.h"

#define AVANCE 0;
#define TOURNE 1;
#define ABS(a) (((a) < 0) ? -(a) : (a))

int sens = AVANCE;
long counter_r=0, counter_l=0;
long step_rmax=0, step_lmax=0;
int execute = 1;


void Init_T5(int conv_r) // initialise le prescaler
{
T5CON = 0;
if(!conv_r)
{
    step_rmax =0;
    counter_r++;
    return; // evite division par zero
}
T5CONbits.TCKPS=3; // prescaler 256
TMR5 = 0; // clear timer5
PR5 = (1000*MILLISEC)/(256.0*conv_r); // interrupt prop speed_r
IFS1bits.T5IF = 0; // clear interrupt flag
IEC1bits.T5IE = 1; // set interrupt enable bit
T5CONbits.TON = 1; // start timer 5
}


void Init_T4(int conv_l) // initialise le prescaler
{
T4CON = 0;
if(!conv_l)
{
    step_lmax =0;
    counter_l++;
    return; // evite division par zero
}
T4CONbits.TCKPS=3; // prescaler 256
TMR4 = 0; // clear timer4
PR4 = (1000*MILLISEC)/(256.0*conv_l); // interrupt prop speed_r
IFS1bits.T4IF = 0; // clear interrupt flag
IEC1bits.T4IE = 1; // set interrupt enable bit
T4CONbits.TON = 1; // start timer 4
}

void _ISR _T5Interrupt(void) // routine d?interruption
{
IFS1bits.T5IF = 0; // clear interrupt flag
static int step_r = 0;
/*fait avancer le moteur de droite d?un pas*/
if(sens)
{
if(!step_r)
{
MOTOR1_PHA = MOTOR1_PHA^1;
MOTOR1_PHB = MOTOR1_PHB^1;
}
else
{
MOTOR1_PHC = MOTOR1_PHC^1;
MOTOR1_PHD = MOTOR1_PHD^1;
}
}
else
{
if(!step_r)
{
MOTOR1_PHA = MOTOR1_PHA^1;
MOTOR1_PHB = MOTOR1_PHB^1;
}
else
{
MOTOR1_PHC = MOTOR1_PHC^1;
MOTOR1_PHD = MOTOR1_PHD^1;
}
}
step_r = step_r^1;
counter_r ++;
if((counter_r >=step_rmax)&&(counter_l >=step_lmax)) // sortie boucle infinie
{
execute = 0;
}
}


void _ISR _T4Interrupt(void) // routine d?interruption
{
    IFS1bits.T4IF = 0; // clear interrupt flag
    static int step_l = 0;
    /*fait avancer le moteur de gauche d?un pas*/
    if(sens)
    {
        if(!step_l)
        {
            MOTOR2_PHA = MOTOR2_PHA^1;
            MOTOR2_PHB = MOTOR2_PHB^1;
        }
        else
        {
            MOTOR2_PHC = MOTOR2_PHC^1;
            MOTOR2_PHD = MOTOR2_PHD^1;
        }
    }
    else
    {
        if(step_l)
        {
            MOTOR2_PHA = MOTOR2_PHA^1;
            MOTOR2_PHB = MOTOR2_PHB^1;
        }
        else
        {
            MOTOR2_PHC = MOTOR2_PHC^1;
            MOTOR2_PHD = MOTOR2_PHD^1;
        }
    }
    step_l = step_l^1;
    counter_l++;
    if((counter_r >=step_rmax)&&(counter_l >=step_lmax)) // sortie boucle infinie
    {
        execute = 0;
    }
}


void e_motor_init() {
    LATD = 0x0055;
}


void e_motor_set_speed(int speed_l , int speed_r) {
    int convert_speed_r , convert_speed_l;
    if(speed_r <-12)
    {
        speed_r = -12; // permet d?eviter un overflow tout en
    } // gardant le signe de la vitesse
    else if(speed_r > 12) {
        speed_r = 12;
        }
    if(speed_l < -12)
    {
        speed_l = -12; // permet d?eviter un overflow tout en
    } // gardant le signe de la vitesse
    else if(speed_l > 12)
    {
        speed_l = 12;
    }
    if(speed_r*speed_l <0) //definit le sens du deplacement
    {
        sens = TOURNE;
    }
    else
    {
        sens = AVANCE;
    }
    convert_speed_r = ABS(speed_r)*1000/13; // # de step par seconde
    convert_speed_l = ABS(speed_l)*1000/13; // # de step par seconde
    Init_T5(convert_speed_r);
    Init_T4(convert_speed_l);
}



