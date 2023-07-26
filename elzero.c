#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int* count_by_x(int x, int n);
char* dogs(int number);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[10];
    int lenght = 3;           // integer array lenght



    /* Test For Boolean */
    bool bool_var = 0;
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS: TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS: FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = 2;
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = count_by_x(4, 4);
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %d\n", char_var);



    /* Test For Char Array */
    char* str_var = dogs(101);
    printf("RETURN TYPE STRING: %s\n", str_var);
}

int* count_by_x(int x, int n) {
    int i;
    int re = 0;
    int* pointer = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        re += x;
        pointer[i] = re; 
    }
    return pointer;
}

char* dogs(int number) {
    return number <= 10 ? "Hardly any"
            : number <= 50 ? "More than a handful"
            : number == 101 ? "101 DALMATIONS"
            : "Woah that's a lot of dogs";
}
