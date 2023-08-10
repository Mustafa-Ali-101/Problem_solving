#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int* powers_of_two(int n);
int summation(int number);
char* update_light(char* s);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[] = {1, 5, 2, 3, 4};
    int lenght = 3;           // integer array lenght
    char* string_arr[] = {"always", "wanna", "do", "best"};
    
    /* Test For Boolean */
    bool bool_var = 0;
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS: TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS: FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = summation(9);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = powers_of_two(3);
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var = update_light("red");
    printf("RETURN TYPE STRING: %s\n", str_var);
}

int compare(const void *a, const void *b)
{
    // Cast the void pointers to int pointers and dereference them
    int x = *(int *)a;
    int y = *(int *)b;

    // Return a negative value if x is less than y
    // Return zero if x is equal to y
    // Return a positive value if x is greater than y
    return x - y;
}

int* powers_of_two(int n) {
    int* p = malloc((n + 1) * sizeof(int));
    int i;
    for (i = 0; i <= n; i++) {
        p[i] = pow(2, i);
    }
    return p;
}

int summation(int number) {
    if (number == 0) {
        return 0;
    } else {
        return number + summation(number - 1);
    }
}

char* update_light(char* s) {
    if (strcmp(s, "green") == 0) {
        return "yellow";
    } else if (strcmp(s, "yellow") == 0) {
        return "red";
    } else {
        return "green";
    }
}