	MVI A,11
    LXI B,2000H
L1:    STAX B
    INX B
    DCR A
    JNZ L1

    LXI D,3000H
    LXI B,2000H
L2:    LDAX B
    STAX D
    INX D
    INX B
    DCR A
    JNZ L2
    HLT
    .END