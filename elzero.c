#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int sum_of_arrays(int a[], int b[],int alength, int blength,int aindex, int bindex);
void count_sheep(int number, int asc);
bool does_match(char a[], char b[], int aindex, int bindex);
/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "mustafa nedeer";
    int int_array[] = {2, 1, 10};
    int lenght = 3;           // integer array lenght



    /* Test For Boolean */
    bool bool_var = does_match("ala", "ala", 0, 0);
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS: TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS: FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = sum_of_arrays(int_array, int_array, 3, 3, 0, 0);
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
    char* str_var;
    //printf("RETURN TYPE STRING: %s\n", str_var);
    count_sheep(3, 1);
}


int sum_of_arrays(int a[], int b[],int alength, int blength,int aindex, int bindex) {
    if (alength == 0){
        if (blength == 0) {
            return 0;
        } else {
           return  b[bindex] + sum_of_arrays(a, b, 0, blength - 1, 0, bindex + 1);
        }
    } else if (blength == 0) {
        return a[aindex] + sum_of_arrays(a, b, alength - 1, 0, aindex + 1, 0);
    }else {
        return (a[aindex] +b[bindex] + sum_of_arrays(a, b, alength - 1, blength - 1, aindex + 1, bindex + 1));
    }
}

void count_sheep(int number, int asc) {
    if (asc <= number) {
        printf("%d sheep...", asc);
        count_sheep(number, asc + 1);
    }
}

bool does_match(char a[], char b[], int aindex, int bindex) {
    if (a[aindex] == '\0') {
        if (b[bindex] == '\0') {
            return (a[aindex - 1] == b[bindex - 1]);
        } else {
            return (1 && does_match(a, b, aindex, bindex - 1));
        }
    } else if (b[bindex] == '\0') {
        return (1 && does_match(a, b, aindex - 1, bindex));
    } else {
        return ( 1 && does_match(a, b, aindex - 1, bindex - 1));
    }
}
