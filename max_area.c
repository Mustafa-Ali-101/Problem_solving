#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_bing.h"


int area(int h, int w) {
    return h * w;
}

int minimum(int x, int y) {
    if (x < y) return x;
    return y;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int a = area(minimum(height[left], height[right]), right - left);
        if ( a > maxArea) {
            maxArea = a;
        }

        if (height[left] > height[right]) {
            right--;
        } else {
            left++;
        }
    }

    return maxArea;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = malloc( 2 * sizeof(int));
    hashtable* hashMap = create_table(numsSize);

    for (int i = 0; i < numsSize; i++) {
        insert(hashMap, nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        int added = target - nums[i];
        // found the two numbers
        if (nums[i] && search(hashMap, added)) {
            result[0] = i;
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] == added) {result[1] = j;break;}
            }   
        }
    }

    
    free(hashMap);

    *(returnSize) = 2;
    return result;
}
int main(void) {


    return 0;
}