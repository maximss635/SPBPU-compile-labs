%{    
#include <stdio.h>  
#include <string.h>

#include "SolverStack.h"

void yyerror(char *s) ;
int yylex();        // ???? 

extern char* yytext;

extern FILE* yyin;
FILE* fout;

char lastVarName[128];
char lastNumber[128];
char lastBinOperator[4];
char lastBinCompareOperator[4];

enum NodeKind lastExprKind;

int condsNum = 0;
int curElseCasesNum = 0;
int cyclesNum = 0;

int numError = 0;

struct SolverStack stack;
struct SolverStack tmp;

void tmpStackPrint() {
    fprintf(fout, "[stack: ");
    for (struct Node* i = stack.begin; i != NULL; i = i->next) {
        fprintf(fout, "%s ", i->elem);
    }
    fprintf(fout, "]\n");

}

void solveExpr() {
    struct Node n;
    while (!stackIsEmpty(&tmp)) {
        n = stackPopBack(&tmp);
        stackPushBack(&stack, n.elem, n.kind);
    }

    // tmpStackPrint();

    stackRun(&stack, fout);
    stackClear(&stack);
}

char* getJmpTypeCommand(const char* compareOperator) {
    if (!strcmp("==", compareOperator)) 
        return "JE";
    if (!strcmp("!=", compareOperator)) 
        return "JNE";
    if (!strcmp(">", compareOperator)) 
        return "JG";
    if (!strcmp("<", compareOperator)) 
        return "JL";
    if (!strcmp(">=", compareOperator)) 
        return "JGE";
    if (!strcmp("<=", compareOperator)) 
        return "JLE";

    return "???";
}

char* getOppositeJmpTypeCommand(const char* jmpType) {
    if (!strcmp("JE", jmpType)) 
        return "JNE";
    if (!strcmp("JNE", jmpType)) 
        return "JE";
    if (!strcmp("JG", jmpType)) 
        return "JLE";
    if (!strcmp("JL", jmpType)) 
        return "JGE";
    if (!strcmp("JLE", jmpType)) 
        return "JG";
    if (!strcmp("JGE", jmpType)) 
        return "JL";
        
    return "???";
}

%} 

%start commands

%token OPEN CLOSE OBRACE EBRACE
%token NUMBER VAR 
%token SEMICOLON 
%token IF ELSE_IF ELSE WHILE 
%token PRINT RETURN 
%token ADD SUB MUL DIV AND OR 
%token BIT_AND BIT_OR BIT_XOR 
%token BIT_LEFT_SHIFT BIT_RIGHT_SHIFT MOD
%token DEC INC
%token ASSIGN 
%token IS_EQUAL IS_NOT_EQUAL 
%token IS_LESS IS_MORE IS_LEQUAL IS_MEQUAL
%token AASS SASS MASS DASS

%% 
commands: 
    /* empty */ | 
    commands command;

semicolon:
    SEMICOLON semicolon |
    SEMICOLON {
        solveExpr();
    };

command:
    PRINT expr semicolon {
        fprintf(fout, "\t\tCALL\tprint\n");
    } |
    RETURN expr semicolon {
        fprintf(fout, "\t\tRET\t\tR1\n");
    } |
    
    expr semicolon |
    
    condition |
    cycle_while;

body:
    OBRACE commands EBRACE;

condition:
    IF OPEN expr CLOSE {
        ++condsNum;

        solveExpr();
        
        char* jmpTypeCmd = getJmpTypeCommand(lastBinCompareOperator);
        
        fprintf(fout, "\t\t%s\t\tcase_1_%d\n", jmpTypeCmd, condsNum);
        fprintf(fout, "\t\tJMP\t\tcase_2_%d\n", condsNum);

        curElseCasesNum = 0;
        fprintf(fout, "\ncase_%d_%d:\n", 1, condsNum);
    }
    body {
        fprintf(fout, "\t\tJMP\t\tout_%d\n", condsNum);
    }
    else_case {
        fprintf(fout, "\ncase_%d_%d:\n", 
            curElseCasesNum + 2, condsNum);

        fprintf(fout, "out_%d:\n", condsNum);
    };

else_case:
    /* empty */ {

    } |
    ELSE_IF OPEN {
        ++curElseCasesNum;

        fprintf(fout, "\ncase_%d_%d:\n", 
            curElseCasesNum + 1, condsNum);
    }
    expr CLOSE {
        solveExpr();
        char* jmpTypeCmd = getJmpTypeCommand(lastBinCompareOperator);
        
        jmpTypeCmd = getOppositeJmpTypeCommand(jmpTypeCmd);
        fprintf(fout, "\t\t%s\t\tcase_%d_%d\n", 
            jmpTypeCmd, curElseCasesNum + 2, condsNum);
    } 
    body {
        fprintf(fout, "\t\tJMP\t\tout_%d\n", condsNum);
    }
    else_case   |
    ELSE {
        ++curElseCasesNum;
        fprintf(fout, "\ncase_%d_%d:\n",
            curElseCasesNum + 1, condsNum);
    }
    body;

cycle_while:
    WHILE OPEN expr CLOSE {
        ++cyclesNum;

        solveExpr();

        char* jmpTypeCmd = getJmpTypeCommand(lastBinCompareOperator);
        
        fprintf(fout, "\t\t%s\t\tcycle_%d_in\n", jmpTypeCmd, cyclesNum);
        fprintf(fout, "\t\tJMP\t\tcycle_%d_out\n", cyclesNum);

        fprintf(fout, "\ncycle_%d_in:\n", cyclesNum);

    }
    body {
        fprintf(fout, "\ncycle_%d_out:\n", cyclesNum);
    };

var_or_number:
    VAR {
        lastExprKind = var;
        stackPushBack(&stack, lastVarName, var);
    } | 
    NUMBER {
        lastExprKind = num;
        stackPushBack(&stack, lastNumber, num);
    };

expr:
    var_or_number |
    OPEN {
        stackPushBack(&tmp, "(", open_parenthesis);
    }
    expr 
    CLOSE {
        struct Node n;
        
        while (true) {
            n = stackPopBack(&tmp);
            if (n.kind == open_parenthesis) {
                break;
            }
            stackPushBack(&stack, n.elem, n.kind);
        }

    } |
    
    expr 
    binary_operator {
        strcpy(lastBinOperator, yytext);

        struct Node n;
        while (!stackIsEmpty(&tmp)) {
            bool compare;
            if (!strcmp("=", lastBinOperator)) {
                compare = (
                    getOperatorPriority(lastBinOperator) <
                    getOperatorPriority(tmp.end->elem)
                );
            } else {
                compare = (
                    getOperatorPriority(lastBinOperator) <=
                    getOperatorPriority(tmp.end->elem)
                );
            }
            if (!compare) {
                break;
            }

            n = stackPopBack(&tmp);
            stackPushBack(&stack, n.elem, n.kind);
        }

        stackPushBack(&tmp, lastBinOperator, operator);
    }
    expr |
    
    unary_operation;

unary_operation:
    INC expr | expr INC |
    DEC expr | expr DEC |
    ADD expr | SUB expr;

binary_operator:
    ASSIGN { 
        if (lastExprKind == num) {
            yyerror("syntax error");
            exit(1);
        }
        strcpy(lastBinOperator, "="); 
    } | 
        
    ADD | SUB | MUL | DIV |   
    compare_operator  {
        strcpy(lastBinCompareOperator, yytext);
    } |
    AASS | SASS | MASS | DASS |      
    AND | OR | MOD |
    BIT_AND | BIT_OR | BIT_XOR | 
    BIT_RIGHT_SHIFT | BIT_LEFT_SHIFT;

compare_operator:
    IS_EQUAL | IS_NOT_EQUAL | 
    IS_MORE | IS_LESS | 
    IS_MEQUAL | IS_LEQUAL; 
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

    if (4 != argc || strcmp("-o", argv[2]) != 0) {
        printf("Incorrect arguments\n");
        printf("Usage: ./compile [path src] -o [path asm]\n");
        
        return -1;
    }

    char* pathFile = argv[1];
    yyin = fopen(pathFile,"r");

    char* pathAsmFile = argv[3];
    fout = fopen(pathAsmFile, "w");

    if (NULL == yyin) {
        printf("No such file: %s\n", pathFile);
	    return -1;
    }
    
    stackInit(&stack);
    stackInit(&tmp);

    yyparse();

    fclose(yyin);
    fclose(fout);

    return 0; 
}
