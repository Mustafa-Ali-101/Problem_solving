#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
bool is_palindrome (int n);
void reverse_string(char* string);
int roman_to_int(char * s);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "ma";
    reverse_string(char_array);
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {3, 2, 2, 2, 3};
    int lenght = 3;           // integer array lenght
    char* string_arr[] = {"always", "wanna", "do", "best"};
    
    /* Test For Boolean */
    bool bool_var = is_palindrome(1221);
    if(bool_var) {
        printf("THE BOOLEAN VALUE IS: TRUE\n");
    } else{
        printf("THE BOOLEAN VALUE IS: FALSE\n");
    }

    


    /* Test For Integer */
    int int_var = roman_to_int("III");
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
    //char* str_var =;
    printf("RETURN TYPE STRING: %s\n", char_array);

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

bool is_palindrome (int n) {
    char arr[12];
    char rev[12];
    int length = 0;
    int j = 0;
    int i;
    sprintf(arr, "%d", n);
    for (i = 0; arr[i] != '\0'; i++) {
        length++;
    }
    for (i = length - 1; i >= 0; i--) {
        rev[j] = arr[i];
        j++;
    }
    rev[j] = '\0';
    
    return (strcmp(arr, rev) == 0) ? 1 : 0;
}

void reverse_string(char* string) {
    int length = 0;
    int i;
    char temp;
    for (i = 0; string[i] != '\0'; i++) {
        length++;
    }
    if (length == 1) return;
    for (i = 0; i <= floor(length / 2) - 1; i++) {
        temp = string[length - i - 1];
        string[length - i - 1] = string[i];
        string[i] = temp;
    }
}

int roman_to_int(char * s) {
    if (s[0] == '\0') {

        return 0;

    }else if (s[0] == 'M') {

        return 1000 + roman_to_int(s + 1);

    } else if (s[0] == 'D') {

        return 500 + roman_to_int(s + 1);

    } else if (s[0] == 'C') {

        if (s[1] == 'M') {
            return 900 + roman_to_int(s + 2);
        } else if (s[1] == 'D'){
            return 400 + roman_to_int(s + 2);
        } else {
            return 100 + roman_to_int(s + 1);
        }

    } else if (s[0] == 'L') {

       return 50 + roman_to_int(s + 1);

    } else if (s[0] == 'X') {

        if (s[1] == 'C') {
            return 90 + roman_to_int(s + 2);
        } else if (s[1] == 'L'){
            return 40 + roman_to_int(s + 2);
        } else {
            return 10 + roman_to_int(s + 1);
        }

    } else if (s[0] == 'V') {

        return 5 + roman_to_int(s + 1);

    } else if (s[0] == 'I') {

        if (s[1] == 'X') {
            return 9 + roman_to_int(s + 2);
        } else if (s[1] == 'V'){
            return 4 + roman_to_int(s + 2);
        } else {
            return 1 + roman_to_int(s + 1);
        }
    }
}