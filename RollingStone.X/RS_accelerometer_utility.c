#include "RS_accelerometer_utility.h"

int RS_acc_mean(int* data, int data_length) {
    int i, mean;
    long int sum=0; 
    for(i=0; i<data_length; i++)    sum+=data[i];
    mean=(int)(sum/data_length);
    return mean;
}



