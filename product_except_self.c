#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    // Allocate Answers memory
    int* answers = (int*) malloc(sizeof(int) * numsSize);

    (*returnSize) = numsSize;

    int pre = 1;
    int post = 1;

    // caculate prefix first
    for (int i = 0; i < numsSize; i++) {
        // Prefix
        answers[i] = pre;
        pre = pre * nums[i];
    }

    // Then calculate postfix
    for (int k = numsSize - 1; k >= 0; k--) {
        answers[k] = answers[k] * post;

        post = post * nums[k];
    }

    

    return answers;
}

int main(void) {

    int list[] = {-1,1,0,-3,3};
    int returnSize;
    int* answers = productExceptSelf(list, 5, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d  ", answers[i]);
    }
    
    return 0;
}