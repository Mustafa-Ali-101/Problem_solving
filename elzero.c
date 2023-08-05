#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int sum_of_positive(int* a, int length);
int volume(int l, int w, int h);
int average(int arr[], int len);

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
    int int_var = average(int_array, 5);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = int_array;
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);
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

int sum_of_positive(int* a, int length) {
    if (length == 0) {
        return 0;
    } else {
        if (a[0] < 0) {
            return sum_of_positive(a + 1, length - 1);
        } else {
            return a[0] + sum_of_positive(a + 1, length - 1);
        }  
    }
}

int volume(int l, int w, int h) {
    return l * w * h;
}

int average(int arr[], int len) {   
    int result = 0;
    int count = 0;
    int i;
    for (i = 0; i < len; i++) {
        result += arr[i];
        count++;
    }
    
    return result / count;
}
