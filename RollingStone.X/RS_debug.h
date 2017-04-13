#ifndef RS_DEBUG_H
#define	RS_DEBUG_H

#include "motor_led/e_init_port.h"
#include "motor_led/e_epuck_ports.h"
#include "a_d/e_ad_conv.h"
#include "a_d/e_accelerometer.h"
#include "uart/e_uart_char.h"
#include "matlab/matlab.h"

#include "RS_const.h"

#define SIZE_DATA 128


void matlab_uart();
void init_matlab();

#endif	/* RS_DEBUG_H */

