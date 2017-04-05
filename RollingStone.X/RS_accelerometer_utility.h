
#ifndef _RS_ACCELEROMETER_UTILITIES
#define _RS_ACCELEROMETER_UTILITIES

#define DATA_RANGE  16
const int RS_acc_mean_table[DATA_RANGE] __attribute__ ((space(ymemory), aligned(32)))=
    {
        //signed <1-1/14>
        //1/1 , 1/2,    1/3,    1/4,    1/5,    1/6,    1/7,  , 1/8  
        0x4000, 0x2000, 0x1555, 0x1000, 0x0CCC, 0x0AAB, 0x0925, 0x0800, 
        //1/9,  1/10,   1/11,   1/12,   1/13,   1/14,   1/15,   1/16 Deuxieme ligne a redefinir
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0400
    }; //signed <1-1/14>

int RS_acc_mean(int* data, int data_length);
#endif //_RS_ACCELEROMETER_UTILITIES
