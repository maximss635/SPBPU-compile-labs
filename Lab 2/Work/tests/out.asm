		MOV		R1, b
		INC		R1
		MOV		b, R1
		MOV		R1, d
		DEC		R1
		MOV		d, R1
[stack: A a b + c + d + = ]
		MOV		R1, a
		ADD		R1, b
		MOV		R2, R1
		MOV		R1, R2
		ADD		R1, c
		MOV		R2, R1
		MOV		R1, R2
		ADD		R1, d
		MOV		R2, R1
		MOV		A, R2
		MOV		R1, a
		INC		R1
		MOV		a, R1
		MOV		R1, c
		DEC		R1
		MOV		c, R1
