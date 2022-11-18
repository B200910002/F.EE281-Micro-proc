    MVI A,11
        LXI B,2000H
L1:        STAX B
        INX B
        DCR A
        JNZ L1

    MVI L,11
        LXI D,3000H
        LXI B,2000H
    MVI H,0
L2:        ADD H
    MOV H,A
    LDAX B
        INX B
        DCR L
        JNZ L2
    ADD H
    STAX D
        HLT
        .END