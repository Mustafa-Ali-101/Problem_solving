#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int num = 143423;
    int enough = (int) ((ceil( log10(num) ) + 1) * sizeof(char));
    char newVal[enough];
    sprintf(newVal, "%d", num);

    printf(newVal);
}