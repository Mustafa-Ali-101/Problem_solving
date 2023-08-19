#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int square_rectangle(int length, int width);
int* divisible_by(int * a, int num, int length);
char** greet(char * a);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "Mustafa Nedeer";
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {1, 2, 3, 4, 9};
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
    int int_var = square_rectangle(3, 3);
    printf("RETURN TYPE INTEGER: %d\n", int_var);




    /* Test For Float */
    float fl_var = 7.23;
    printf("RETURN TYPE FLOAT: %f\n", fl_var);




    /* Test For Integer Array */
    int* arr_var = divisible_by(int_array, 9, 5);
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 4; i++) {
        printf(" %d ", arr_var[i]);
    }
    printf("]\n");




    /* Test For Char */
    char char_var = 'A';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);

    /* Test For String Array */
    char** str_arr = greet(char_array);
    printf("THE STRING IS: ");
    for (int i = 0; i < 3; i++) {
        printf("%s", str_arr[i]);
    }
    printf("\n");
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

int square_rectangle(int length, int width) {
    if (length == width) {
        int area = length * width;
        return area;
    } else {
        int perimeter = 2 * (length + width);
        return perimeter;
    }
}

int* divisible_by(int * a, int num, int length) {
    int result_length = 0;
    int i;
    int index = 0;
    for (i = 0; i < length; i++) {
        if (num % a[i] == 0) result_length++;
    }
    int * p = malloc(result_length * sizeof(int));
    for (i = 0; i < length; i++) {
        if (num % a[i] == 0) {
            p[index] = a[i];
            index++;
        }
    }
    return p;
}

char** greet(char * a) {
    int i;
    char* * g = malloc(3 * sizeof(char*));
    g[0] = "Hello, ";
    g[1] = a;
    g[2] = " how are you doing today?";
    return g;
}