#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct stackNode {
    int val;
    struct stackNode *next;
} StackNode;


StackNode* createStack() {
    StackNode* stack = NULL;
    return stack;
}

bool push (StackNode** stack, int val) {
    StackNode* newNode = (StackNode*) malloc(sizeof(StackNode));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return false;
    }

    newNode->val = val;
    newNode->next = *stack;
    (*stack) = newNode;
    return true;
}


bool isEmptyStack(StackNode* stack) {
    return stack == NULL;
}

int pop(StackNode** stack) {
    if (isEmptyStack(*stack)) {
        printf("Couldn't Pop An Empty Stack\n");
        return INT_MIN;
    } else {
        int poped = (*stack)->val;
        (*stack) = (*stack)->next;
        return poped;
    }
}

