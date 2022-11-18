	MVI A, 2H
    STA 2000H
    MVI D, 01H
    MVI E, 01H 
    LDA 2000H
L1:
	SUB D
    JZ L2
    INR D
    INR D
    INR E 
    JMP L1 
L2:
	MOV A, E 
    STA 2001H
    HLT
