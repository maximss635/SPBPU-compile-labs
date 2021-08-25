%{
#include <stdlib.h>
#include "grammar.tab.h"
%}

%%
int                             return TYPE_INT;
double                          return TYPE_FLOAT;
float                           return TYPE_DOUBLE;
char                            return TYPE_CHAR;
long                            return TYPE_PREFIX_LONG;
unsigned                        return TYPE_PREFIX_UNSIGNED;
signed                          return TYPE_PREFIX_SIGNED;
void                            return TYPE_VOID;
static                          return TYPE_PREFIX_STATIC;
extern                          return TYPE_PREFIX_EXTERN;
const                           return TYPE_PREFIX_CONST;

[ \t]+                          /* игнорируем пробелы и знаки табуляции */
(\r\n)|\n                       yylval++;

,                               return COMMON;
;                               return SEMICOLON;

\{                              return OBRACE;
\}                              return EBRACE;
\(                              return OPEN_CIRCLE_BRACKET;
\)                              return CLOSE_CITCLE_BRACKET;

if                              return IF;
else                            return ELSE;
while                           return WHILE;
do                              return DO;
for                             return FOR;
return                          return RETURN;

[0-9]*                          return NUMBER;
[a-zA-Z][a-zA-Z0-9|_]*          return SOME_NAME;
%%
