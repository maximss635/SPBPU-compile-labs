		MOV		a, 0

cycle_1_in:
		MOV		R1, a
		CMP		R1, 0
		JLE		cycle_1_out
		MOV		R1, a
		INC		R1
		MOV		a, R1
		MOV		R1, a
		MOV		R1, b
		MOV		R1, b
		INC		R1
		MOV		b, R1
		JMP		cycle_1_in

cycle_1_out:
		MOV		R1, a
		ADD		R1, 5
		MOV		R2, R1
		MOV		b, R2
		MOV		R1, b
		CALL	print
