#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int sum_array(int* b, int numb);
char* point(int a, int b);
int seat_in_theater(int total_col, int total_row, int col, int row);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {1, 5, 2, 3, 4, 6, 7, 8, 9, 10};
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
    int int_var = seat_in_theater(16, 11, 5, 3);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = int_array;
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 2; i++) {
        printf(" %d ", *(arr_var + i));
    }
    printf("]\n");




    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var = point(5, 3);
    printf("RETURN TYPE STRING: %s\n", str_var);

    /* Test For String Array */
    char** str_arr;
    //for (int i = 0; i < 3; i++) {
    //    printf("THE FIRST STRING IS: %s \n", str_arr[i]);
    //}
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

int sum_array(int* b, int numb) {
    if (numb == 0) {
        return 0;
    } else {
        return b[0] + sum_array(b + 1, numb - 1);
    }
}

char* point(int a, int b) {
    if (a > b) {
        return "Win";
    } else if (b > a) {
        return "Lose";
    } else {
        return "Draw";
    }
}

int seat_in_theater(int total_col, int total_row, int col, int row) {
    return (total_col - col + 1) * (total_row - row);
}
