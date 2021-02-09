%{    
#include <stdio.h>  
#include <string.h>

void yyerror(char *s) ;
int yylex();        // ???? 

int lastNum;
char lastVarName[128];
char assignLeftOperand[128];

extern FILE* yyin;

FILE* fout;
int numError = 0;
%} 

%start commands
%token NUMBER VAR ASSIGN SEMICOLON IF OPEN CLOSE OBRACE EBRACE COMPARE ELSE_IF ELSE PRINT ADD SUB MUL DIV WHILE RETURN CHANGE DEC INC AND OR BIT_AND BIT_OR BIT_XOR BIT_LEFT_SHIFT BIT_RIGHT_SHIFT MOD

%% 
commands: 
    /* empty */ | 
    commands command;

command:
    PRINT expr SEMICOLON { fprintf(fout, "CALL\tprint\n"); } |
    RETURN expr SEMICOLON { fprintf(fout, "RET"); } |
    assigment SEMICOLON /*{ printf("assigment\n"); }*/ |
    expr SEMICOLON { /*printf("expr");*/ } |
    
    condition |

    cycle_while
    ;

body:
    OBRACE commands EBRACE;

condition:
    IF OPEN expr CLOSE
    body
    else_case;

else_case:
    /* empty */ |
    ELSE_IF OPEN expr CLOSE
    body  
    else_case   |
    ELSE 
    body;

cycle_while:
    WHILE OPEN expr CLOSE
    body;

assigment:
    VAR { strcpy(assignLeftOperand, lastVarName); }
    ASSIGN expr 
    { fprintf(fout, "MOV\t%s, R1\n", assignLeftOperand); };

expr:
    OPEN expr CLOSE |
    binary_operation |
    unary_operation |
    assigment |
    VAR |
    NUMBER { fprintf(fout, "LEA\tR1, %d\n", lastNum); } ;

unary_operation:
    INC expr | expr INC |
    DEC expr | expr DEC |
    ADD expr | SUB expr;

binary_operation:
    comparation |
    
    expr ADD expr |
    expr SUB expr |
    expr MUL expr |
    expr DIV expr |
    
    expr CHANGE expr |
    
    expr AND expr |
    expr OR expr |

    expr BIT_AND expr |
    expr BIT_OR expr |
    expr BIT_XOR expr |
    expr BIT_LEFT_SHIFT expr |
    expr BIT_RIGHT_SHIFT expr |
    expr MOD expr;

comparation:
    expr COMPARE expr;

%% 

void yyerror(char *s) 
{     
    ++numError;
    fprintf(stderr, "%s\n", s); 
} 

int yywrap()
{
    if (0 == numError)
        printf("OK\n");
    return 1;
} 

int main(int argc, void *argv[])
{
    yylval = 0;

    if (4 != argc || strcmp("-o", argv[2])) {
        printf("Incorrect arguments\n");
        printf("Usage: ./compile [path src] -o [path asm]\n");
        
        return -1;
    }

    char* pathFile = argv[1];
    yyin = fopen(pathFile,"r");
    if (NULL == yyin) {
        printf("No such file: %s\n", pathFile);
	    return -1;
    }

    fout = fopen(argv[3], "w");

    yyparse();
    fclose(yyin);

    fclose(fout);

    return 0; 
}
