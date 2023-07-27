#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char* two_sort(char* a[], int length);
int cmpfunc(const void *a, const void *b);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[10];
    int lenght = 3;           // integer array lenght
    char* string_arr[] = {"always", "wanna", "do", "best"};
    

    two_sort(string_arr, 4);

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
    int* arr_var = int_array;
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %d\n", char_var);



    /* Test For Char Array */
    char* str_var = two_sort(string_arr, 4);
    printf("RETURN TYPE STRING: %s\n", str_var);
}


char* two_sort(char* a[], int length) {
    char arr[length];
    int i, j;
    for (i = 0; i < length; i++) {
        arr[i] = a[i][0];
        printf("%c\n", arr[i]);
    }
    char* result = malloc((length * 4) * sizeof(char) + 1);
    qsort(arr, length, sizeof(char), cmpfunc);
    for (i = 0, j = 0; i < length * 4; i += 4, j++) {
        result[i] = arr[j];
        result[i + 1] = '*';
        result[i + 2] = '*';
        result[i + 3] = '*';
    }
    result[length * 4] = '\0';
    return result;
}

// A comparison function that uses strcmp to compare two chars as strings
int cmpfunc(const void *a, const void *b) {
  return strcmp((const char *)a, (const char *)b);
}
