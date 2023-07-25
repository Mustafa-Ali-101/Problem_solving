#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int* multi(int n, int a[]);
int do_i_get_bonus(int salary, bool bonus);
int opposite(int number);

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
    int int_var = do_i_get_bonus(3, 0);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = multi(6, int_array);
    for (int i = 0; i < 10; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %d\n", char_var);



    /* Test For Char Array */
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);
}

int* multi(int n, int a[]) {
    int i;
    for (i = 1; i <= 10; i++) {
        a[i - 1] = i * n;
    }
    return a;
}

int do_i_get_bonus(int salary, bool bonus) {
    return bonus? salary * 10 : salary; 
}

int opposite(int number) {
    return number * -1;
}

