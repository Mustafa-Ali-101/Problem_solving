#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_INT 100
#define MIN_INT -1234759

typedef struct stack {
    int array[MAX_INT];
    int index;
} stack;

/* function to initialize of a stack */
stack* make_stack(void) {
    stack* ss = malloc(sizeof(stack));
    ss->index = 0;
    return ss;
}

/* push an int to the stack */
void push_s(stack* s, int value) {
    if (s->index >= MAX_INT) {
        printf("Sorry.The stack is full.");
    } else {
        s->array[s->index] = value;
        s->index = s->index + 1;
    }
}

/* pop from the stck */
int pop_s(stack* s) {
    if (s->index <= 0) {
        return MIN_INT;
    } else {
        s->index = s->index - 1;
        int r = s->array[s->index];
        
        return r;
    } 
}
