#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int rental_car_cost(int days);
int* pipe_fix(int* arr, int length);
int student_grade(int grade, int project);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
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
    int int_var = student_grade(85, 5);
    printf("RETURN TYPE INTEGER: %d\n", int_var);




    /* Test For Float */
    float fl_var = 7.23;
    printf("RETURN TYPE FLOAT: %f\n", fl_var);




    /* Test For Integer Array */
    int* arr_var = pipe_fix(int_array, 5);
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 9; i++) {
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

int rental_car_cost(int days) {
    int cost = days * 40;
    if (days >= 7) {
        return cost - 50;
    } else if(days >= 3) {
        return cost - 20;
    } else {
        return cost;
    }
}

int* pipe_fix(int* a, int length) {
    int start = a[0];
    int end = a[length - 1];
    int diff = end - start + 1;
    int * p = malloc(diff * sizeof(int));
    for (int i = 0; i < diff; i++) {
        p[i] = start;
        start++;
    }
    return p;
}

int student_grade(int grade, int project) {
    if (grade == 100 || project > 10) return 100;
    if (grade > 75 && project >= 5) return 90;
    if (grade > 50 && project >= 2) return 75;
    return 0;
}