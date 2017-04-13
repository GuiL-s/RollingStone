#include "RS_accelerometer_utility.h"

int RS_acc_mean(int* data, int data_length) {
    int i, mean;
    long int sum=0; 
    for(i=0; i<data_length; i++)    sum+=data[i];
    mean=(int)(sum/data_length);
    return mean;
}


long RS_acc_norm(int* acc_T){
    long X_2 = P_2(acc_T[ID_ACC_X]);
    X_2 = (X_2/P_2(MAX_ANG)); //*(SHOCK_ACC/3) ;
    
    long Y_2 = P_2(acc_T[ID_ACC_Y]);
    Y_2 = (Y_2/P_2(MAX_ANG));//*(SHOCK_ACC/3);
    
    long Z_2 = P_2(acc_T[ID_ACC_Z]);
    Z_2 = (Z_2/P_2(MAX_ANG));//*(SHOCK_ACC/3);
    
    long norm = X_2 + Y_2 + Z_2;
    
    return norm;
}
