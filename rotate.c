#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>



void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;

    // Rotate Big array
    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;

        left++;
        right--;
    } 

    // Rotate First Portion
    left = 0;
    right = k - 1;
    while (left < right) {
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;

        left++;
        right--;
    }

    // Rotate Second Portion
     left = k;
    right = numsSize - 1;
    while (left < right) {
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;

        left++;
        right--;
    }
}


int main(void) {

    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rotate(list, 10, 3);


    for (int i = 0; i < 10; i++)
    {
        printf("%d ", list[i]);
    }
    
    return 0;
}