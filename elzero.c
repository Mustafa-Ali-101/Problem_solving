#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int* fakebin(int a[], int len);
int sakura_fall(int speed);
char* replace(char* arr);

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
    int int_var = sakura_fall(5);
    printf("RETURN TYPE INTEGER: %d\n", int_var);



    /* Test For Integer Array */
    int* arr_var = fakebin(int_array, 5);
    for (int i = 0; i < 4; i++) {
        printf("THE NUMBER IN %d IS: %d\n", i, *(arr_var + i));
    }



    /* Test For Char */
    char char_var = 'a';
    printf("RETURN TYPE CHARCATER IS: %c\n", char_var);



    /* Test For Char Array */
    char* str_var = replace(char_array);
    printf("RETURN TYPE STRING: %s\n", str_var);
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

int* fakebin(int a[], int len) {
    int* p = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (a[i] < 5) {
            p[i] = 0;
        } else {
            p[i] = 1;
        }
    }
    return p;
}

int sakura_fall(int speed) {
    if (speed <= 0) {
        return 0;
    } else {
        return 400 / speed;
    }
}

char* replace(char* arr) {
    char s[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; arr[i] != '\0'; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] == s[j]) {
                arr[i] = '!';
                break;
            }
        }
    }
    return arr;
}