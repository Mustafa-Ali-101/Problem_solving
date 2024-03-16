#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct stackNode {
    int val;
    int*next;
}stackNode;


stackNode* makeStack() {
    stackNode* stack = NULL;
    return stack;
}

bool pushStack (stackNode** stack, int val) {
    stackNode* newNode = malloc(sizeof(stackNode));

    if (newNode == NULL) {
        printf("Memory Allocation Failed");
        return false;
    }

    newNode->val = val;
    newNode->next = *stack;
    (*stack) = newNode;
    return true;
}


bool isEmptyStack(stackNode* stack) {
    return stack == NULL;
}

int popStack(stackNode** stack) {
    if (isEmptyStack(stack)) {
        printf("Couldn't Pop An Empty Stack");
        return -404;
    } else {
        int poped = (*stack)->val;
        (*stack) = (*stack)->next;
        return poped;
    }
}

