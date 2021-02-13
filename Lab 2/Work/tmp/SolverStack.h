#ifndef MY_STACK_H
#define MY_STACK_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


struct SolverStack {
    struct Node {
        enum NodeKind {
            operator, num, var,
            open_parenthesis,
            close_parenthesis,
            reg
        } kind;

        char elem[128];

        struct Node* next;
        struct Node* prev;
    };

    struct Node* begin;
    struct Node* end;
    int size;
};

void stack_init(struct SolverStack* stack) {
    stack->size = 0;
    stack->begin = stack->end = NULL;
}

bool stack_isEmpty(const struct SolverStack* stack) {
    return 0 == stack->size;
}

void stack_pushBack(struct SolverStack* stack, const char* newElem,
    const enum NodeKind newElemKind) {

    struct Node *newNode = (struct Node *)
        malloc(sizeof(struct Node));

    newNode->kind = newElemKind;
    strcpy(newNode->elem, newElem);
    newNode->next = NULL;

    if (!stack_isEmpty(stack)) {
        stack->end->next = newNode;
        newNode->prev = stack->end;
        stack->end = newNode;
    } else {
        stack->end = stack->begin = newNode;
        newNode->prev = NULL;
    }

    ++stack->size;
}

struct Node stack_popBack(struct SolverStack* stack) {
    if (stack_isEmpty(stack)) {
        struct Node n;
        return n;
    }

    struct Node toReturn;
    strcpy(toReturn.elem, stack->end->elem);
    toReturn.kind = stack->end->kind;

    struct Node* toDelete = stack->end;

    if (stack->size > 1) {
        struct Node* newEnd = stack->end->prev;
        newEnd->next = NULL;
        stack->end = newEnd;
    } else {
        stack->begin = stack->end = NULL;
    }

    free(toDelete);

    --stack->size;

    return toReturn;
}

void stack_clear(struct SolverStack* stack) {
    while (!stack_isEmpty(stack)) {
        stack_popBack(stack);
    }
}

int getOperatorPriority(const char* operator) {
   
    static const char priorityTable[11][11][4] = {
        {"*", "/", "%"},
        {"+", "-"},
        {">>", "<<"},
        {">=", "<=", ">", "<"},
        {"==", "!="},
        {"&"},
        {"^"},
        {"|"},
        {"&&"},
        {"||"},
        {"=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "^=", "|="},
    };

    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            if (!strcmp(priorityTable[i][j], operator)) {
                return 11 - i;
            }
        }
    }

    return 0;
}

char* getAsmCommand(const char* operator) {
    if (!strcmp("+", operator)) 
        return "ADD";
    if (!strcmp("-", operator))
        return "SUB";
    if (!strcmp("*", operator))
        return "MUL";
    if (!strcmp("/", operator))
        return "DIV";
    
    // to continue
}   

void stack_run(const struct SolverStack* stack, FILE* fout) {
    
    struct SolverStack tmp;
    stack_init(&tmp);

    int regNumResult = 1;
    char r[16];

    bool wasAssigment = false;

    // itterate throw the src stack
    for (const struct Node* n = stack->begin;
        n != NULL;
        n = n->next) {

        if (n->kind == num || n->kind == var) {
            stack_pushBack(&tmp, n->elem, n->kind);
            continue;
        }

        if (n->kind == operator) {
            if (!strcmp("=", n->elem)) {
                struct Node rightArg = stack_popBack(&tmp);
                struct Node leftArg = stack_popBack(&tmp);

                fprintf(fout, "MOV\t%s, %s\n", leftArg.elem, rightArg.elem);
                stack_pushBack(&tmp, leftArg.elem, leftArg.kind);

                wasAssigment = true;
            } else {
                struct Node rightArg = stack_popBack(&tmp);
                struct Node leftArg = stack_popBack(&tmp);

                // fprintf(fout, "[l=%s, r=%s]\n", leftArg.elem, rightArg.elem);

                if (leftArg.kind == num)
                    fprintf(fout, "LDI\tR1, %s\n", leftArg.elem);
                else if (leftArg.kind == var || leftArg.kind == reg)
                    fprintf(fout, "MOV\tR1, %s\n", leftArg.elem);
            
                char* asmCommand = getAsmCommand(n->elem);
                fprintf(fout, "%s\tR1, %s\n", asmCommand, rightArg.elem);

                ++regNumResult;
                fprintf(fout, "MOV R%d, R1\n", regNumResult);
                
                sprintf(r, "R%d", regNumResult);
                stack_pushBack(&tmp, r, reg);

            }
        }

    }

    if (!wasAssigment) {
        fprintf(fout, "MOV\tR1, R%d\n", regNumResult);
    }
    
}

#endif
