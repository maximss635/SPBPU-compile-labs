all:
	lex src/lexic.l
	yacc -d src/grammar.y

	mv lex.yy.c tmp/
	mv y.tab.c tmp/
	mv y.tab.h tmp/

	cp src/SolverStack.h tmp/
	cp src/RegisterAllocator.h tmp/
	cp src/Vars.h tmp/

	cc tmp/lex.yy.c tmp/y.tab.c -o compile -lfl
