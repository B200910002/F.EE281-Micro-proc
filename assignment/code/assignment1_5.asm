	MVI A,00h
	MVI B,09h
NEXT: 
	ADD B
	DCR B
	JNZ NEXT
	STA 201FH
	HLT