#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* values;
    int* min_values;

    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->values = (int*)malloc(30000 * sizeof(int));
    stack->min_values = (int*)malloc(30000 * sizeof(int));
    stack->top = -1;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->values[obj->top] = val;
    if (obj->top == 0) {
        obj->min_values[obj->top] = val;
    } else {
        obj->min_values[obj->top] = val < obj->min_values[obj->top - 1] ? val : obj->min_values[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->values[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_values[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->values);
    free(obj->min_values);
    free(obj);
}


int main() {
    MinStack* obj = minStackCreate();
    minStackPush(obj, 10);
    minStackPush(obj, 20);

    minStackPop(obj);

    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);

    minStackFree(obj);
    return 0;
}