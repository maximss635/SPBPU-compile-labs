		MOV		a, 0
		MOV		b, 1
		MOV		i, 1

cycle_1_in:
		MOV		R1, i
		CMP		R1, 10
		JGE		cycle_1_out
		MOV		R1, a
		ADD		R1, b
		MOV		R2, R1
		MOV		f, R2
		MOV		R1, f
		CALL	print
		MOV		a, b
		MOV		b, f
		MOV		R1, i
		INC		R1
		MOV		i, R1
		MOV		R1, i
		JMP		cycle_1_in

cycle_1_out:
		LDI		R1, 0
		RET		R1
