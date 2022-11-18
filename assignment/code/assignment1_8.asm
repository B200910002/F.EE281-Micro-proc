    MVI A, 4
    STA 1000H
    MVI A, 4
    STA 1001H
    LDA 1000H
    MOV B, A
    LDA 1001H
    MOV C, A
    MVI A, 0
M1:    
	ADD B
    DCR C
    JNZ M1
    STA 100AH
    MVI B, 2H
    MVI C, 00H
    LDA 100AH
L1:
    CMP B
    JC L2
    SUB B
    INR C
    JMP L1
L2:
    MOV A, C
    STA 1010H

    HLT