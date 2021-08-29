#include "detected_callbacks.h"

extern char someFunctionName[ 128 ];
extern char curLine[ 128 ];
extern char prevLine[ 128 ];
extern char someName[ 128 ];
extern int yylval;

void onTokenDetected( enum TokenKind tokenKind )
{
    switch( tokenKind )
    {
        case Enter:
            strcpy( prevLine, curLine );  // clear
            strcpy( curLine, "" );
            break;

        case Name:
            if ( strlen( yytext ) > 128 )
            {
                fprintf( stdout, "[ERROR] Too long name: %s", yytext );
                exit( -1 );
            }
            strcpy( someName, yytext );
            break;

        default:
            if ( strlen( curLine ) > 128 )
            {
                fprintf( stdout, "[ERROR] Too long line: %s\n", curLine );
                exit( -1 );
            }
            strcat( curLine, yytext );
            break;
    }
}

void onBlockDetected( enum BlockKind blockKind )
{
    switch( blockKind )
    {
    case FunctionDefinition:
        LOG_DEBUG_FMT( "Function definition detected: %s", someFunctionName );
        break;

    case FunctionDeclaration:
        LOG_DEBUG_FMT( "Function declaration detected: %s", someFunctionName );
        break;

    case IfCond:
        //LOG_DEBUG_FMT( "If condition detected at line: %d", yylval );
        break;

    case ElseCond:
        //LOG_DEBUG_FMT( "Else condition detected at line: %d", yylval );
        break;

    case IfBody:
        //LOG_DEBUG( "If body detected" );
        break;

    case ElseBody:
        //LOG_DEBUG( "Else body detected" );
        break;

    default:
        break;
    }
}
