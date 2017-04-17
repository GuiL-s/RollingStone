/*******************************************************************************
 ***************************   RS_motors.c   ***********************************
 *******************************************************************************
 * Authors:     Guilain Lang & Arien Legrain                                   *
 *                                                                             *
 * Project :    Rolling Stone                                                  *
 *                                                                             *
 * Course :     Microinformatique, EPFL, spring 2017                           *
 *                                                                             *
 * Description:                                                                *
 * This file contain the function to compute speed                             *
 * It uses e-puck library to control motors (e-motors.h)                       *
  ******************************************************************************/


// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef RS_MOTORS_C
#define	RS_MOTORS_C

#include "RS_motors.h"


/*******************************************************************************
 *********   void RS_acc_update(int* acc_T, int* acc_prev_T)    ****************
 ******************************************************************************* 
 * Parameters :                                                                *
 * acc_T -->    table of acceleration (main.c --> RS_motor.c)                  *
 *              (Step N)                                                       *
 * acc_prev_T --> table of acceleration (main.c --> RS_motor.c)                *
 *              (Step N-1,used by the PID)                                     *
 * speed_T -->    table of speed (main.c --> RS_motor.c)                       *
 *              (Step N)                                                       *
 *                                                                             *
 * Description :                                                               *
 * This function compute the linear and angular speed                          *
 * Then setup the motors speed with the new values                             *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void RS_mot_updateSpeed(int* acc_T, int* acc_prev_T, int* speed_T){
    speed_T[ID_SPEED_LIN] = RS_mot_calcSpeedLin(speed_T, acc_T[ID_ACC_Y]);
    speed_T[ID_SPEED_ANG] = RS_mot_calcSpeedAng(acc_T[ID_ACC_X]);
    
    RS_mot_setSpeed(speed_T[ID_SPEED_LIN], speed_T[ID_SPEED_ANG]);
}


/*******************************************************************************
 *********   int RS_mot_calcSpeedLin(int* speed_T, int acc_Y)    ***************
 ******************************************************************************* 
 * Parameters :                                                                *
 * speed_T -->   table of speed                                                *
 *              (Step N-1)                                                     *
 * acc_Y -->    acceleration Y axis                                            *
 *              (Step N)                                                       *
 *                                                                             *
 * Description :                                                               *
 * This function compute the linear speed                                      *
 * Then setup the motors speed with the new values                             *
 *                                                                             *
 * Return :                                                                    *
 * New computed linear speed                                                   *   
 ******************************************************************************/
int RS_mot_calcSpeedLin(int* speed_T, int acc_Y){
    static int speedLin;
    long s= RS_mot_PID(speed_T, acc_Y);
    if (s<MAX_INT && s>MIN_INT) speedLin=s;
    return speedLin;
}


/*******************************************************************************
 ***************   int RS_mot_calcSpeedAng(int acc_X)    ***********************
 ******************************************************************************* 
 * Parameters :                                                                *
 * speed_T -->   table of speed                                                *
 *              (Step N-1)                                                     *
 * acc_X -->    acceleration X axis                                            *
 *              (Step N)                                                       *
 *                                                                             *
 * Description :                                                               *
 * This function compute the angular speed                                     *
 * Then setup the motors speed with the new values                             *
 *                                                                             *
 * Return :                                                                    *
 * New computed angular speed                                                  *   
 ******************************************************************************/
int RS_mot_calcSpeedAng(int acc_X){
    static int speedAng;
    speedAng = K_ANG*acc_X;
    return speedAng;
}



/*******************************************************************************
 ********   void RS_mot_setSpeed(int speed_lin, int speed_ang)    **************
 ******************************************************************************* 
 * Parameters :                                                                *
 * speed_lin -->   value of linear speed                                       *
 *              (Step N)                                                       *
 * speed_ang -->   value of angular speed                                      *
 *              (Step N)                                                       *
 *                                                                             *
 * Description :                                                               *
 * This function change linear and angular speed to right and left speed       *
 * It calls e-motor.c to set the speed of e-puck                               *
 *                                                                             *
 * Return :                                                                    *
 * void                                                                        *   
 ******************************************************************************/
void RS_mot_setSpeed(int speed_lin, int speed_ang){
    int speed_left = speed_lin + speed_ang;
    int speed_right = speed_lin - speed_ang;
    
    if (speed_left <= - MAX_SPEED) speed_left = - MAX_SPEED;
    else if (speed_left >= MAX_SPEED) speed_left = MAX_SPEED;
    if (speed_right <= - MAX_SPEED) speed_right = - MAX_SPEED;
    else if (speed_right >= MAX_SPEED) speed_right = MAX_SPEED;
    
    e_set_speed_left(speed_left);
    e_set_speed_right(speed_right);
}


/*******************************************************************************
 *********   int RS_mot_calcSpeedLin(int* speed_T, int acc_Y)    ***************
 ******************************************************************************* 
 * Parameters :                                                                *
 * speed_T -->   table of speed                                                *
 *              (Step N-1)                                                     *
 * acc_Y -->    acceleration Y axis                                            *
 *              (Step N)                                                       *
 *                                                                             *
 * Description :                                                               *
 * This function compute the linear speed with a PID response                  *
 * The PID is based on acceleration                                            *
 * speed_lin_N = speed_lin_N-1 +KP*Dacc + KI*sum_Dacc + KD*Var_Dacc            *
 *                                                                             *
 * Return :                                                                    *
 * New computed linear speed                                                   *   
 ******************************************************************************/
int RS_mot_PID(int* speed_T, int acc_Y){
    int Da = - acc_Y;
    long sum_Da = RS_acc_I(acc_Y);
    int var_Da = RS_acc_D(Da);
    long acc = KP*Da + KI*sum_Da + KD*var_Da;
    acc/=1000;
    int speed_lin = speed_T[ID_SPEED_LIN] + acc;
    return speed_lin;
}

#endif	/* RS_MOTOR_C */
