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
            close_parenthesis
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

#endif
