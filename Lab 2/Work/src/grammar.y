%{    
#include <stdio.h>  
#include <string.h>

void yyerror(char *s) ;
int yylex();        // ???? 

char lastNum[128];
char lastVarName[128];

struct Stack {
    char data[32][128];
    int i;
};

void push_stack(struct Stack* stack, char* s) 
{
    strcpy(stack->data[stack->i++], s);
}

char* pop_stack(struct Stack* stack)
{
    return stack->data[--stack->i];
}

struct Stack assignLeftOperands;

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
    RETURN expr SEMICOLON { fprintf(fout, "RET\n"); } |
    assigment SEMICOLON |
    
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

expr:
    OPEN expr CLOSE |
    binary_operation |
    unary_operation |
    assigment |
    VAR { fprintf(fout, "PUSH\t%s\n", lastVarName); }|
    NUMBER { fprintf(fout, "PUSH\t%s\n", lastNum); };

assigment:
    VAR { push_stack(&assignLeftOperands, lastVarName); }  
    ASSIGN expr { 
        char* varName = pop_stack(&assignLeftOperands);
        fprintf(fout, "POP\t%s\n", varName); 
        if (assignLeftOperands.i) {
            fprintf(fout, "PUSH\t%s\n", varName);
        }
    } ;

unary_operation:
    INC expr | expr INC |
    DEC expr | expr DEC |
    ADD expr | SUB expr;

binary_operation: 
    comparation |
    
    expr ADD expr { 
        char* varName = assignLeftOperands.data[assignLeftOperands.i - 1];
        fprintf(fout, "POP\tTMP\n");
        fprintf(fout, "POP\t%s\n", varName);
        fprintf(fout, "ADD\t%s, TMP\n", varName);
        fprintf(fout, "PUSH\t%s\n", varName); 
    } |
    expr SUB expr {
        char* varName = assignLeftOperands.data[assignLeftOperands.i - 1];
        fprintf(fout, "POP\tTMP\n");
        fprintf(fout, "POP\t%s\n", varName);
        fprintf(fout, "SUB\t%s, TMP\n", varName);
        fprintf(fout, "PUSH\t%s\n", varName); 
    } |
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

    assignLeftOperands.i = 0;

    yyparse();
    fclose(yyin);

    fclose(fout);

    return 0; 
}
