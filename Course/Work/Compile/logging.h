#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define LOG_DEBUG( msg ) fprintf( stdout, "[DEBUG] " msg "\n" );
#define LOG_DEBUG_FMT( msg, ... ) fprintf( stdout, "[DEBUG] " msg "\n", __VA_ARGS__ );

extern char* yytext;

enum BlockKind
{
    FunctionDefinition,
    FunctionDeclaration,
    IfCond, IfBody,
    ElseCond, ElseBody,
    LocalInstanceDeclaration,
    OneLineComment, MultiLineComment,
    StringConstant
};

enum TokenKind
{
    Enter,
    Name,
    Default
};

void onTokenDetected( enum TokenKind tokenKind );

void onBlockDetected( enum BlockKind blockKind );
