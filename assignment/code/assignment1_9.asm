	LDA 2000H  
    MOV B,A    
    LDA 2001H  
    MOV D,A
    MVI A,00H 
L1: 
	ADD B
    DCR D
    JNZ L1    
    STA 2010H
    HLT 