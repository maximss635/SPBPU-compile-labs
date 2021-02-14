#ifndef MY_STACK_H
#define MY_STACK_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "RegisterAllocator.h"

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
    } *begin, *end;

    int size;
};

void stackInit(struct SolverStack* stack) {
    stack->size = 0;
    stack->begin = stack->end = NULL;
}

bool stackIsEmpty(const struct SolverStack* stack) {
    return 0 == stack->size;
}

void stackPushBack(struct SolverStack* stack, const char* newElem,
    const enum NodeKind newElemKind) {

    struct Node *newNode = (struct Node *)
        malloc(sizeof(struct Node));

    newNode->kind = newElemKind;
    strcpy(newNode->elem, newElem);
    newNode->next = NULL;

    if (!stackIsEmpty(stack)) {
        stack->end->next = newNode;
        newNode->prev = stack->end;
        stack->end = newNode;
    } else {
        stack->end = stack->begin = newNode;
        newNode->prev = NULL;
    }

    ++stack->size;
}

struct Node stackPopBack(struct SolverStack* stack) {
    if (stackIsEmpty(stack)) {
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

void stackClear(struct SolverStack* stack) {
    while (!stackIsEmpty(stack)) {
        stackPopBack(stack);
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
        {
            "=", "+=", "-=", 
            "*=", "/=", "%=", 
            "<<=", ">>=", "&=", 
            "^=", "|="
        },
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
    return "...";
}   

void stackRun(const struct SolverStack* stack, FILE* fout) {
    
    struct SolverStack tmp;
    stackInit(&tmp);

    struct RegisterAllocator regAllocator;
    regAllocatorInit(&regAllocator);

    int regNumResult = 1;
    char r[16];

    bool wasAssigment = false;

    // itterate throw the src stack
    for (const struct Node* n = stack->begin;
        n != NULL;
        n = n->next) {

        if (n->kind == num || n->kind == var) {
            stackPushBack(&tmp, n->elem, n->kind);
            continue;
        }

        if (n->kind == operator) {
            if (!strcmp("=", n->elem)) {
                struct Node rightArg = stackPopBack(&tmp);
                struct Node leftArg = stackPopBack(&tmp);

                fprintf(fout, "MOV\t\t%s, %s\n", 
                    leftArg.elem, rightArg.elem);
                
                stackPushBack(&tmp, leftArg.elem, leftArg.kind);

                wasAssigment = true;
            } else {
                struct Node rightArg = stackPopBack(&tmp);
                struct Node leftArg = stackPopBack(&tmp);

                if (leftArg.kind == num) {
                    fprintf(fout, "LDI\t\tR1, %s\n", leftArg.elem);
                }
                else if (leftArg.kind == var || leftArg.kind == reg) {
                    fprintf(fout, "MOV\t\tR1, %s\n", leftArg.elem);
                    
                    regAllocatorFree(
                        &regAllocator, (int)(leftArg.elem[1] - '0'));
                }

                char* asmCommand = getAsmCommand(n->elem);
                fprintf(fout, "%s\t\tR1, %s\n", asmCommand, rightArg.elem);

                regNumResult = regAllocatorAlloc(
                    &regAllocator);

                fprintf(fout, "MOV\t\tR%d, R1\n", regNumResult);
                
                sprintf(r, "R%d", regNumResult);
                stackPushBack(&tmp, r, reg);

            }
        }

    }

    if (!wasAssigment) {
        if (regNumResult != 1)
            fprintf(fout, "MOV\t\tR1, R%d\n", regNumResult);
        else if (tmp.end->kind == num)
            fprintf(fout, "LDI\t\tR1, %s\n", tmp.end->elem);
        else if (tmp.end->kind == var)    
            fprintf(fout, "MOV\t\tR1, %s\n", tmp.end->elem);
    }
    
}

#endif
