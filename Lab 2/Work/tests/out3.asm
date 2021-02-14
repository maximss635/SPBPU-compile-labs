		MOV		a, 1
		MOV		b, 4
		MOV		R1, a
		CMP		R1, 20
		JL		cycle_1_in
		JMP		cycle_1_out

cycle_1_in:
		MOV		R1, a
		CMP		R1, 3
		JG		case_1_1
		JMP		case_2_1

case_1_1:
		MOV		R1, a
		ADD		R1, b
		MOV		R2, R1
		MOV		a, R2
		JMP		out_1

case_2_1:
		MOV		R1, a
		ADD		R1, b
		MOV		R2, R1
		MOV		b, R2

case_3_1:
out_1:

cycle_1_out:
		LDI		R1, 7
		MUL		R1, a
		MOV		R2, R1
		LDI		R1, 3
		MUL		R1, b
		MOV		R3, R1
		MOV		R1, RR
		ADD		R1, 1
		MOV		R2, R1
		MOV		R1, R3
		DIV		R1, R2
		MOV		R2, R1
		MOV		R1, R2
		SUB		R1, R2
		MOV		R2, R1
		MOV		R, R2
		MOV		R1, b
		ADD		R1, a
		CALL	print
