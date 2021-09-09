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
void readStringConstant();
void readPreprocessorLine();

%}

%%

"/*"                            readComment( 1 );
"//"                            readComment( 0 );

"#"                             readPreprocessorLine();

"long int"                      NEW_TOKEN( TYPE_LONG_INT );
"long double"                   NEW_TOKEN( TYPE_LONG_DOUBLE );
"short int"                     NEW_TOKEN( TYPE_SHORT_INT );
long                            NEW_TOKEN( TYPE_LONG );
short                           NEW_TOKEN( TYPE_SHORT );

int                             NEW_TOKEN( TYPE_INT );
double                          NEW_TOKEN( TYPE_FLOAT );
float                           NEW_TOKEN( TYPE_DOUBLE );
char                            NEW_TOKEN( TYPE_CHAR );
unsigned                        NEW_TOKEN( TYPE_PREFIX_UNSIGNED );
signed                          NEW_TOKEN( TYPE_PREFIX_SIGNED );
void                            NEW_TOKEN( TYPE_VOID );
static                          NEW_TOKEN( TYPE_PREFIX_STATIC );
extern                          NEW_TOKEN( TYPE_PREFIX_EXTERN );
const                           NEW_TOKEN( TYPE_PREFIX_CONST );
inline                          NEW_TOKEN( INLINE );
size_t                          NEW_TOKEN( TYPE_SIZE_T );

[ \t]+                          onTokenDetected( Default );

(\r\n)|\n                       onTokenDetected( Enter ); yylval++;

\"                              readStringConstant(); NEW_TOKEN( STRING_CONSTANT );

"."                             NEW_TOKEN( '.' );
","                             NEW_TOKEN( ',' );
";"                             NEW_TOKEN( ';' );
"?"                             NEW_TOKEN( '?' );
":"                             NEW_TOKEN( ':' );
"->"                            NEW_TOKEN( ARR );

\{                              NEW_TOKEN( '{' );
\}                              NEW_TOKEN( '}' );
\(                              NEW_TOKEN( '(' );
\)                              NEW_TOKEN( ')' );
\[                              NEW_TOKEN( '[' );
\]                              NEW_TOKEN( ']' );

struct                          NEW_TOKEN( STRUCT );

sizeof                          NEW_TOKEN( SIZEOF );

if                              NEW_TOKEN( IF );
else                            NEW_TOKEN( ELSE );
do                              NEW_TOKEN( DO );
while                           NEW_TOKEN( WHILE );
for                             NEW_TOKEN( FOR );
return                          NEW_TOKEN( RETURN );

break                           NEW_TOKEN( BREAK );
continue                        NEW_TOKEN( CONTINUE );

"*"                             NEW_TOKEN( '*' );
"&"                             NEW_TOKEN( '&' );
\+|\-|\/                        NEW_TOKEN( BINARY_OPERATOR );
\+=|\-=|\*\|\/=|\|=|\&=|\^=     NEW_TOKEN( BINARY_OPERATOR );
==|!=|\>|\>=|<|<=               NEW_TOKEN( BINARY_OPERATOR );
=                               NEW_TOKEN( '=' );
\||\|\||&&|\%|\^                NEW_TOKEN( BINARY_OPERATOR );
\<\<|>>                         NEW_TOKEN( BINARY_OPERATOR );

\+\+|\-\-|!                     NEW_TOKEN( UNARY_OPERATOR );

[0-9|.]*|[0-9|.]*f              NEW_TOKEN( NUMBER );

[a-zA-Z|_][a-zA-Z0-9|_]*          onTokenDetected( Name ); NEW_TOKEN( SOME_NAME );

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
    			else if ( c == '\n' )
    			{
    			    ++yylval;
    			}
    			else if ( c == 0 )
    			{
    			    break;
    			}
    		}
    	}

    	yyerror( "Unterminated comment\n" );
    }
    else
    {
        int cur, prev = 0;
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

void readStringConstant()
{
    int cur, prev = 0;
    int i = 0;

    while ( ( cur = input() ) != 0 )
    {
        g_context.stringConstant[ i++ ] = ( char )cur;

        if ( i == 1024 )
        {
            yyerror( "Too long string constant\n" );
            exit( -1 );
        }

        if ( cur == '\"' && prev != '\\' )
        {
            g_context.stringConstant[ i ] = 0;
            onBlockDetected( StringConstant );

            return ;
        }

        prev = cur;
    }

    yyerror( "Unterminated string constant\n" );
}

void readPreprocessorLine()
{
    int c;

    do
    {
        c = input();
    } while ( c != '\n' && c != 0 );

    if ( c == 0 )
    {
        yyerror( "Unterminated line\n" );
    }
    else
    {
        onTokenDetected( Enter );
        yylval++;
    }
}