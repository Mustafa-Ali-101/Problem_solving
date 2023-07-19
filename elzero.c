#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare_ints_desc(const void* a, const void* b);
int sum_of_difference(int a[], int length);
int messi_goals(int a, int b, int c);
char* get_planet_name(int n);


/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[] = {2, 1, 10};
    int lenght = 3;           // integer array lenght



    /* Test For Boolean */
    bool bool_var = 0;
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = messi_goals(5, 4, 6);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = int_array;
    for (int i = 0; i < 3; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var = get_planet_name(5);
    printf("RETURN TYPE STRING: %s\n", str_var);
}


int sum_of_difference(int a[], int length) {
    int sorted[length];
    int i;
    int result = 0;
    if (length <= 1) return 0;
    /* Copy the array in sorted */
    for (i = 0; i < length; i++) {
        sorted[i] = a[i];
    }
    /* sort descending */
    qsort(sorted, length, sizeof(int), compare_ints_desc);
    
    /* final loop for differences */
    for (i = 0; i < (length - 1); i++) {
        result += sorted[i] - sorted[i + 1];
    }
    return result;
}


int compare_ints_desc(const void* a, const void* b) {
    // Cast the pointers to int*
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    // Compare the integers and return the result
    if (arg1 < arg2) return 1; // Return positive if the first element is less than the second
    if (arg1 > arg2) return -1; // Return negative if the first element is greater than the second
    return 0;
}

int messi_goals(int a, int b, int c) {
    return a + b + c;
}

char* get_planet_name(int n) {
    char* ps[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

    return ps[n - 1];
}