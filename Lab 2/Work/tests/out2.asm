	MOV		R1, a
	CMP		R1, 0
	JG		m1
	JMP		??
m1:
	LDI		R1, 1
	CALL	print
	MOV		R1, b
	CMP		R1, 0
	JG		m2
	JMP		??
m2:
	LDI		R1, 11
	CALL	print
	JMP		??????
m3:
	LDI		R1, 12
	CALL	print
m4:
	JMP		??????
m5:
	LDI		R1, 2
	CALL	print
	MOV		R1, c
	CMP		R1, 0
	JG		m6
	JMP		??
m6:
	LDI		R1, 21
	CALL	print
	JMP		??????
m7:
	LDI		R1, 22
	CALL	print
m8:
m9:
	LDI		R1, 3
	CALL	print
