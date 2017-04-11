.section .RS_utiliy
.text
.global _RS_acc_mean
_RS_acc_mean:
    ;W0 : DATA*
    ;W1 : LENGTH OF DATA 

    ; Save value if W8 and W10 were used
    PUSH W8
    PUSH W10

    MOV W0, W8 ; X pointer init

     ; Y pointer init
    MOV _RS_acc_mean_table, W2
    ADD W2, W1, W2
    ADD W2, W1, W2
    SUB	W2, #2
    MOV W2, W10

    ; Clear accumulator and set 1 pair of pointer
    CLR A, [W8]+=2, W4, [W10]+=2, W7

    ; MAC loop
    REPEAT W1
    MAC W4*W7, A, [W8]+=2, W4, [W10] , W7

    ;shift --> decimal result
    
    ; Get accumulator (lowest 16 bits)
    MOV ACCAL, W0
    
    ;shift --> sign
    
    ; Restore W8 and W10 values
    POP W10
    POP W8

    RETURN

.end
