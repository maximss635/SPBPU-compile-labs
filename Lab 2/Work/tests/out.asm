	LDI		R1, 5
	MUL		R1, a
	MOV		R2, R1
	LDI		R1, 8
	MUL		R1, y
	MOV		R3, R1
	MOV		R1, R3
	DIV		R1, r
	MOV		R3, R1
	MOV		R1, R2
	ADD		R1, R3
	MOV		R2, R1
	MOV		R1, R2
	SUB		R1, 32
	MOV		R2, R1
	MOV		res3, R2
	MOV		res2, res3
	MOV		res1, res2
	LDI		R1, 1
	ADD		R1, b
	MOV		R2, R1
	MOV		R1, R2
	ADD		R1, 3
	MOV		R2, R1
	MOV		R1, R2
	CALL	print
	MOV		R1, a
	RET		R1
