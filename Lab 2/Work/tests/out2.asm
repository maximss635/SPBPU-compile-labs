		MOV		R1, a
		CMP		R1, 0
		JE		case_1_1
		JMP		case_2_1

case_1_1:
		LDI		R1, 5
		CALL	print
		JMP		out_1

case_2_1:
out_1:
		LDI		R1, 6
		CALL	print
