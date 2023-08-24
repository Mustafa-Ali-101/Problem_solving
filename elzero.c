#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

/* STARTING OF MAIN FUNCTION */
int main(void) {
    /* ALL VARIABLES */
    char char_array[] = "Mustafa Nedeer";
    char* str_array[] = {"body", "tails", "heads"};
    int int_array[] = {3, 2, 4};
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
    int int_var = 0;
    printf("RETURN TYPE INTEGER: %d\n", int_var);




    /* Test For Float */
    float fl_var = 7.23;
    printf("RETURN TYPE FLOAT: %f\n", fl_var);




    /* Test For Integer Array */
    int* arr_var = twoSum(int_array, 3, 6, &int_var);
    printf("RETURN TYPE ARRAY: [");
    for (int i = 0; i < 2; i++) {
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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i;
    int max = 0;
    int complement = 0;
    int * p = malloc(2 * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
    }
    
    int * hash_table = malloc(max * sizeof(int));
    for (i = 0; i < max; i++) {
        hash_table[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        hash_table[nums[i]] = 1;
    }
    for (i = 0; i < numsSize; i++) {
        complement = target - nums[i];
        if (hash_table[nums[i]] && hash_table[complement]) {
            for (int j = 0; i < numsSize; i++) {
                if (nums[j] == complement) {
                    p[0] = i;
                    p[1] = j;
                    return p;
                }
            }
        }
    }

}