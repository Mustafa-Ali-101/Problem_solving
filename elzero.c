#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int* count_positives_sum_negatives(int a[], int length);
int expressions_matter(int a, int b, int c);
bool pythagorean_triple(int a, int b, int c);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {1, 5, 2, 3, 4, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15};
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
    int int_var = expressions_matter(2, 1, 3);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = count_positives_sum_negatives(int_array, 5);
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 2; i++) {
        printf(" %d ", *(arr_var + i));
    }
    printf("]\n");




    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);

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

int* count_positives_sum_negatives(int a[], int length) {
    int i;
    int count = 0;
    int sum = 0;
    int* p = malloc(2 * sizeof(int));
    for (i = 0; i < length; i++) {
        if (a[i] >= 0) {
            count++;
        } else {
            sum += a[i];
        }
    }
    p[0] = count;
    p[1] = sum;
    return p;
}

int expressions_matter(int a, int b, int c) {
    int* p = malloc(5 * sizeof(int));
    p[0] = (a + b) * c;
    p[1] = (a + c) * b;
    p[2] = (c + b) * a;
    p[3] = a + b + c;
    p[4] = a * b * c;

    int max;
    for (int i = 0; i < 5; i++) {
        if (p[i] > max) max = p[i];
    }
    return max;
}

bool pythagorean_triple(int a, int b, int c) {
    int max;
    if (a > b){
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }
    return (max * max) == (a * a) + (b * b) + (c * c) - (max * max);
}
