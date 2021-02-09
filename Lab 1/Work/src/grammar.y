%{    
#include <stdio.h>  

void yyerror(char *s) ;
int yylex();        // ???? 

extern FILE* yyin;
int num_error = 0;
%} 

%start commands
%token NUMBER VAR ASSIGN SEMICOLON IF OPEN CLOSE OBRACE EBRACE COMPARE ELSE_IF ELSE PRINT ADD SUB MUL DIV WHILE RETURN CHANGE DEC INC AND OR BIT_AND BIT_OR BIT_XOR BIT_LEFT_SHIFT BIT_RIGHT_SHIFT MOD

%% 
commands: 
    /* empty */ | 
    commands command;

command:
    PRINT expr SEMICOLON /*{ printf("print\n"); }*/ |
    RETURN expr SEMICOLON /*{ printf("return"); }*/ |
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
    VAR ASSIGN expr { /*printf("assigment");*/ };

expr:
    OPEN expr CLOSE |
    binary_operation |
    unary_operation |
    assigment |
    VAR |
    NUMBER;

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
    ++num_error;
    fprintf(stderr, "%s\n", s); 
} 

int yywrap()
{
    if (0 == num_error)
        printf("OK\n");
    return 1;
} 

int main(int argc, void *argv[])
{
    yylval = 0;

    if (2 != argc) {
        printf("Incorrect arguments\n");
        printf("Usage: ./compile [path]\n");
        
        return -1;
    }

    char* pathFile = argv[1];
    yyin = fopen(pathFile,"r");
    if (NULL == yyin) {
        printf("No such file: %s\n", pathFile);
	    return -1;
    }

    yyparse();
    fclose(yyin);

    return 0; 
}
