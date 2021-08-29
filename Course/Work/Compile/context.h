typedef struct Context
{
    char curLine[128];
    char prevLine[128];
    char someName[128];
    char someFunctionName[128];

    int multilineCommentStartLine, multilineCommentEndLine;
} Context;
