.section .text
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
    
    MOV #2070, W5
    MOV #0x0AAB, W7
    
;    ; Clear accumulator and set 1 pair of pointer
    CLR A, [W8], W4, [W10], W6

    ; MAC loop
    REPEAT #5
    MAC W5*W7, A

    ;shift --> decimal result
    SFTAC A, #14
    
    ; Get accumulator (lowest 16 bits)
    MOV ACCAL, W0
    
    
    
    ; Restore W8 and W10 values
    POP W10
    POP W8
    MOV #2070, W0
    RETURN

.end
