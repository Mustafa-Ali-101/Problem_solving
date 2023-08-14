#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int indexes(int* a, int length, int b);
char get_grade(int* b, int length);
int paper_work(int n, int m);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {84, 79, 85};
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
    int int_var = paper_work(7, 9);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = int_array;
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 2; i++) {
        printf(" %d ", *(arr_var + i));
    }
    printf("]\n");




    /* Test For Char */
    char char_var = get_grade(int_array, 3);
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

int indexes(int* a, int length, int b) {
    if (b >= length) return -1;
    return pow(a[b], b);
}

char get_grade(int* b, int length) {
    int avg;
    int count;
    for (int i = 0; i < length; i++) {
        count = count + b[i];
    }
    avg = count / length;
    if (avg >= 90) {
        return 'A';
    } else if (avg >= 80) {
        return 'B';
    } else if (avg >= 70) {
        return 'C';
    } else if (avg >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int paper_work(int n, int m) {
    return n < 0 || m < 0 ? 0 : n * m;
}