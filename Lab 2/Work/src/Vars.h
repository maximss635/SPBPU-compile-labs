#ifndef VARS_H
#define VARS_H

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

struct SolverStack varsForPostInc;
struct SolverStack varsForPostDec;
struct SolverStack varsForPredInc;
struct SolverStack varsForPredDec;

#endif
