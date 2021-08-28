%{
#include <stdlib.h>
#include <string.h>

#include "grammar.tab.h"

#define NEW_TOKEN( token ) \
    onToken(); \
    return token;

extern char curLine[ 128 ];
extern char prevLine[ 128 ];
extern char someName[ 128 ];

void onToken()
{
    if ( strlen( curLine ) > 128 )
    {
        fprintf( stdout, "[ERROR] Too long line: %s\n", curLine );
        exit( -1 );
    }
    strcat( curLine, yytext );
    strcat( curLine, " " );
}

void onEnter()
{
    strcpy( prevLine, curLine );  // clear
    strcpy( curLine, "" );
    yylval++;
}

void onSomeName()
{
    if ( strlen( yytext ) > 128 )
    {
        fprintf( stdout, "[ERROR] Too long name: %s", yytext );
        exit( -1 );
    }

    strcpy( someName, yytext );
}

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

[ \t]+                          /* игнорируем пробелы и знаки табуляции */

(\r\n)|\n                       onEnter();

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

[0-9]*                          NEW_TOKEN( NUMBER );

[a-zA-Z][a-zA-Z0-9|_]*          onSomeName(); NEW_TOKEN( SOME_NAME );

%%
