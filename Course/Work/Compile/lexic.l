%{
#include <stdlib.h>
#include <string.h>

#include "grammar.tab.h"
#include "detected_callbacks.h"

#define NEW_TOKEN( token ) \
    onTokenDetected( Default ); \
    return token;

%}

%%
int                             NEW_TOKEN( TYPE_INT );
double                          NEW_TOKEN( TYPE_FLOAT );
float                           NEW_TOKEN( TYPE_DOUBLE );
char                            NEW_TOKEN( TYPE_CHAR );
long                            NEW_TOKEN( TYPE_PREFIX_LONG );
unsigned                        NEW_TOKEN( TYPE_PREFIX_UNSIGNED );
signed                          NEW_TOKEN( TYPE_PREFIX_SIGNED );
void                            NEW_TOKEN( TYPE_VOID );
static                          NEW_TOKEN( TYPE_PREFIX_STATIC );
extern                          NEW_TOKEN( TYPE_PREFIX_EXTERN );
const                           NEW_TOKEN( TYPE_PREFIX_CONST );
inline                          NEW_TOKEN( INLINE );

[ \t]+                          onTokenDetected( Default );

(\r\n)|\n                       onTokenDetected( Enter ); yylval++;

,                               NEW_TOKEN( COMMON );
;                               NEW_TOKEN( SEMICOLON );

\{                              NEW_TOKEN( OBRACE );
\}                              NEW_TOKEN( EBRACE );
\(                              NEW_TOKEN( OPEN_CIRCLE_BRACKET );
\)                              NEW_TOKEN( CLOSE_CITCLE_BRACKET );

if                              NEW_TOKEN( IF );
else                            NEW_TOKEN( ELSE );
do                              NEW_TOKEN( DO );
while                           NEW_TOKEN( WHILE );
for                             NEW_TOKEN( FOR );
return                          NEW_TOKEN( RETURN );

\+|\-|\*|\/                     NEW_TOKEN( BINARY_OPERATOR );
==|!=|\>|\>=|<|<=               NEW_TOKEN( BINARY_OPERATOR );
=                               NEW_TOKEN( BINARY_OPERATOR_ASSIGN );
\||\|\||&|&&|\%|\^              NEW_TOKEN( BINARY_OPERATOR );
\<\<|>>                         NEW_TOKEN( BINARY_OPERATOR );

\+\+|\-\-                       NEW_TOKEN( UNARY_OPERATOR );

[0-9|.]*|[0-9|.]*f              NEW_TOKEN( NUMBER );

[a-zA-Z][a-zA-Z0-9|_]*          onTokenDetected( Name ); NEW_TOKEN( SOME_NAME );

%%
