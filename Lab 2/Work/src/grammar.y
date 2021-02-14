%{    
#include <stdio.h>  
#include <string.h>

#include "SolverStack.h"
#include "Vars.h"

void yyerror(char *s) ;
int yylex();        // ???? 

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



void endLineCallBack() {
    stackForeachElem(&varsForPredInc, asmInc);
    stackForeachElem(&varsForPredDec, asmDec);

    solveExpr();

    stackForeachElem(&varsForPostInc, asmInc);
    stackForeachElem(&varsForPostDec, asmDec);

    stackClear(&varsForPredInc);
    stackClear(&varsForPredDec);
    stackClear(&varsForPostInc);
    stackClear(&varsForPostDec);
}

%} 

%start commands

%token OPEN CLOSE OBRACE EBRACE
%token NUMBER VAR 
%token SEMICOLON 
%token IF ELSE_IF ELSE WHILE 
%token PRINT RETURN 
%token ADD SUB MUL DIV AND OR 
%token DEC INC
%token BIT_AND BIT_OR BIT_XOR 
%token BIT_LEFT_SHIFT BIT_RIGHT_SHIFT MOD
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
        endLineCallBack();
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
        fprintf(fout, "\ncase_%d_%d:\n", curElseCasesNum + 2, condsNum);
        fprintf(fout, "out_%d:\n", condsNum);
    };

else_case:
    /* empty */ |
    ELSE_IF OPEN {
        ++curElseCasesNum;
        fprintf(fout, "\ncase_%d_%d:\n", curElseCasesNum + 1, condsNum);
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

        fprintf(fout, "\ncycle_%d_in:\n", cyclesNum);

        solveExpr();

        char* jmpTypeCmd = getJmpTypeCommand(lastBinCompareOperator);
        jmpTypeCmd = getOppositeJmpTypeCommand(jmpTypeCmd);

        fprintf(fout, "\t\t%s\t\tcycle_%d_out\n", 
            jmpTypeCmd, cyclesNum);
    }
    body {
        fprintf(fout, "\t\tJMP\t\tcycle_%d_in\n", cyclesNum);
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
    unary_operation |
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
    expr;

unary_operation:
    INC VAR {
        printf("++%s\n", lastVarName);
        stackPushBack(&varsForPredInc, lastVarName, var);

        lastExprKind = var;
        stackPushBack(&stack, lastVarName, var);
    } | 
    VAR INC {
        printf("%s++\n", lastVarName);
        stackPushBack(&varsForPostInc, lastVarName, var);

        lastExprKind = var;
        stackPushBack(&stack, lastVarName, var);
    } |
    DEC VAR {
        printf("--%s\n", lastVarName);
        stackPushBack(&varsForPredDec, lastVarName, var);

        lastExprKind = var;
        stackPushBack(&stack, lastVarName, var);
    } | 
    VAR DEC {
        printf("%s--\n", lastVarName);
        stackPushBack(&varsForPostDec, lastVarName, var);

        lastExprKind = var;
        stackPushBack(&stack, lastVarName, var);
    } |

    ADD expr | 
    SUB expr;

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

    stackInit(&varsForPostInc);
    stackInit(&varsForPostDec);
    stackInit(&varsForPredInc);
    stackInit(&varsForPredDec);

    yyparse();

    fclose(yyin);
    fclose(fout);

    return 0; 
}
