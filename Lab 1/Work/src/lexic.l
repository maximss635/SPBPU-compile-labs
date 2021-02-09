%{ 
#include <stdlib.h> 
#include "y.tab.h" 
%}

%% 
\{                              return OBRACE;
\}                              return EBRACE;
\(                              return OPEN;
\)                              return CLOSE;

print                           return PRINT;
return                          return RETURN;

if                              return IF;
else\ if                        return ELSE_IF;
else                            return ELSE;

while                           return WHILE;

=                               return ASSIGN;
;                               return SEMICOLON;

[ \t]+                          /* игнорируем пробелы и знаки табуляции */
(\r\n)|\n                       yylval++;

>|<|>=|<=|==|!=                 return COMPARE;
(\/=)|(\*=)|(\+=)|(-=)          return CHANGE;
\+\+                            return INC;
\-\-                            return DEC;

\+                              return ADD;
\-                              return SUB;
\*                              return MUL;
\/                              return DIV;

&&                              return AND;
\|\|                            return OR;

&                               return BIT_OR;
\|                              return BIT_AND;
\^                              return BIT_XOR;
\<\<                            return BIT_LEFT_SHIFT;
>>                              return BIT_RIGHT_SHIFT;
\%                              return MOD;

[0-9]*                          return NUMBER;
[a-zA-Z][a-zA-Z0-9]*            return VAR;

%% 
