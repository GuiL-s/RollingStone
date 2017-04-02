
#ifndef _RS_ACCELEROMETER_UTILITIES
#define _RS_ACCELEROMETER_UTILITIES

#define DATA_RANGE  16
const int RS_acc_mean_table[DATA_RANGE] __attribute__ ((space(ymemory), aligned(32)))=
    {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F
    } ;
    

int RS_acc_mean(int* data, int data_length);
#endif //_RS_ACCELEROMETER_UTILITIES
