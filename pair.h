#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int** cons(int* a, int* b) {
    int **r = malloc(2 * sizeof(int *));
    r[0] = a;
    r[1] = b;
    return r;
}

int car (int** c) {
    return c[0][0];
}

int** cdr(int** c) {
    return &(c[1]);
}