%{
#include <stdlib.h>
#include <string.h>

#include "grammar.tab.h"
#include "logging.h"
#include "context.h"

#define NEW_TOKEN( token ) \
    onTokenDetected( Default ); \
    return token;

extern void yyerror( char* );

extern Context g_context;

void readComment( _Bool multiline );

%}

%%

"/*"                            readComment( 1 );
"//"                            readComment( 0 );

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

,                               NEW_TOKEN( ',' );
;                               NEW_TOKEN( ';' );
\?                               NEW_TOKEN( '?' );
:                               NEW_TOKEN( ':' );

\{                              NEW_TOKEN( '{' );
\}                              NEW_TOKEN( '}' );
\(                              NEW_TOKEN( '(' );
\)                              NEW_TOKEN( ')' );
\[                              NEW_TOKEN( '[' );
\]                              NEW_TOKEN( ']' );

if                              NEW_TOKEN( IF );
else                            NEW_TOKEN( ELSE );
do                              NEW_TOKEN( DO );
while                           NEW_TOKEN( WHILE );
for                             NEW_TOKEN( FOR );
return                          NEW_TOKEN( RETURN );

\+|\-|\*|\/                     NEW_TOKEN( BINARY_OPERATOR );
==|!=|\>|\>=|<|<=               NEW_TOKEN( BINARY_OPERATOR );
=                               NEW_TOKEN( '=' );
\||\|\||&|&&|\%|\^              NEW_TOKEN( BINARY_OPERATOR );
\<\<|>>                         NEW_TOKEN( BINARY_OPERATOR );

\+\+|\-\-                       NEW_TOKEN( UNARY_OPERATOR );

[0-9|.]*|[0-9|.]*f              NEW_TOKEN( NUMBER );

[a-zA-Z][a-zA-Z0-9|_]*          onTokenDetected( Name ); NEW_TOKEN( SOME_NAME );

%%


void readComment( _Bool multiline )
{
    if ( multiline )
    {
        g_context.multilineCommentStartLine = yylval;

        int c;
    	while ( ( c = input() ) != 0 )
    	{
    	    if ( c == '\n' )
    	    {
    	        ++yylval;
    	    }

    		if ( c == '*' )
    		{
    			while ( ( c = input() ) == '*' ) ;
    			if ( c == '/' )
    			{
    			    onBlockDetected( MultiLineComment );
                    g_context.multilineCommentEndLine = yylval;

    			    return;
    			}
    			if ( c == 0 ) break;
    		}
    	}

    	yyerror( "[ERROR] Unterminated comment\n" );
    }
    else
    {
        int cur, prev;
        while ( ( cur = input() ) != 0 )
        {
    	    if ( cur == '\n' )
    	    {
    	        ++yylval;
    	    }

            if ( cur == '\n' && prev != '\\' )
            {
                onBlockDetected( OneLineComment );
                return;
            }
            prev = cur;
        }

    	yyerror( "Unterminated comment\n" );
    }
}
