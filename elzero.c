#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int combat(int health, int damage);
int find_smallest(int a[], int length);
int sum(int a[], int length);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[] = {4, 5, 7, 3, 9, 2};
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
    int int_var = sum(int_array, 6);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = int_array;
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %d\n", char_var);



    /* Test For Char Array */
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);
}

int sum(int a[], int length) {
    int arr[length];
    int i;
    int result = 0;
    for (i = 0; i < length; i++) {
        arr[i] = a[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), compare);

    for (int i = 1; i < (length - 1); i++) {
        result += arr[i];
    }
    return result;
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

int combat(int health, int damage) {
    return health > damage ? health - damage : 0;
}

int find_smallest(int a[], int length) {
    int so_far = a[0];
    int i;
    for (i = 0; i < length; i++) {
        if (a[i] < so_far) so_far = a[i];
    }
    return so_far;
}