typedef struct Context
{
    char curLine[ 128 ];
    char prevLine[ 128 ];
    char someName[ 128 ];
    char varName[ 128 ];
    char someFunctionName[ 128 ];

    char stringConstant[ 1024 ];
    char charConstant;

    int multilineCommentStartLine, multilineCommentEndLine;
} Context;
