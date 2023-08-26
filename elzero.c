#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
char * longestCommonPrefix(char ** strs, int strsSize);
/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "ma";
    char* str_array[] = {"dog", "flow", "flight"};
    int int_array[] = {3, 2, 2, 2, 3};
    int lenght = 3;           // integer array lenght
    char* string_arr[] = {"always", "wanna", "do", "best"};
    
    /* Test For Boolean */
    bool bool_var = 1;
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS: TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS: FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = 0;
    printf("RETURN TYPE INTEGER: %d\n", int_var);




    /* Test For Float */
    float fl_var = 7.23;
    printf("RETURN TYPE FLOAT: %f\n", fl_var);




    /* Test For Integer Array */
    int* arr_var = int_array;
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 2; i++) {
        printf(" %d ", arr_var[i]);
    }
    printf("]\n");




    /* Test For Char */
    char char_var = 'A';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var = longestCommonPrefix(str_array, 3);
    printf("RETURN TYPE STRING: %s\n", str_var);

    /* Test For String Array */
    /*char** str_arr = char_array;
    printf("THE STRING IS: ");
    for (int i = 0; i < 3; i++) {
        printf("%s", str_arr[i]);
    }
    printf("\n");*/
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

char * longestCommonPrefix(char ** strs, int strsSize) {
    char * commonpre = malloc(200 * sizeof(char));
    int index = 0;
    int i;
    while (true) {
        char c = strs[0][index];   /* the indexed character in the first string */
        if (c == '\0') {           /* just in case the strings are all equal */
            commonpre[index] = '\0';
            return commonpre;
        }
        for (i = 1; i < strsSize; i++) {
            if (strs[i][index] != c) {
                commonpre[index] = '\0';
                return commonpre;
            }
        }
        commonpre[index] = c;
        index++;
    }
}