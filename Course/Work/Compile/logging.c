#include "logging.h"
#include "context.h"

extern Context g_context;
extern int yylval;

void onTokenDetected( enum TokenKind tokenKind )
{
    switch( tokenKind )
    {
        case Enter:
            strcpy( g_context.prevLine, g_context.curLine );  // clear
            strcpy( g_context.curLine, "" );
            break;

        case Name:
            if ( strlen( yytext ) > 128 )
            {
                fprintf( stdout, "[ERROR] Too long name: %s", yytext );
                exit( -1 );
            }
            strcpy( g_context.someName, yytext );
            break;

        default:
            if ( strlen( g_context.curLine ) > 128 )
            {
                fprintf( stdout, "[ERROR] Too long line: %s\n", g_context.curLine );
                exit( -1 );
            }
            strcat( g_context.curLine, yytext );
            break;
    }
}

void onBlockDetected( enum BlockKind blockKind )
{
    switch( blockKind )
    {
    case FunctionDefinition:
        LOG_DEBUG_FMT( "Function definition detected: %s", g_context.someFunctionName );
        break;

    case FunctionDeclaration:
        LOG_DEBUG_FMT( "Function declaration detected: %s", g_context.someFunctionName );
        break;

    case LocalInstanceDeclaration:
        LOG_DEBUG_FMT( "Local instance declaration detected in function \"%s\": %s",
                       g_context.someFunctionName, g_context.someName )
        break;

    case OneLineComment:
        LOG_DEBUG_FMT( "Oneline comment detected: %d", yylval );
            break;

    case MultiLineComment:
        LOG_DEBUG_FMT( "Multiline comment detected: %d - %d",
                       g_context.multilineCommentStartLine + 1, yylval + 1 );
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
