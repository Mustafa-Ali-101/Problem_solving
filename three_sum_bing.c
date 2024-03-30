#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "helper.h"

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int * result = malloc(sizeof(int) * 2);
    (*returnSize) = 2;

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        // Target Found
        if (nums[left] + nums[right] == target) {
            result[0] = nums[left];
            result[1] = nums[right];
            return result;
        } else if (nums[left] + nums[right] > target) {
            right--;
        } else {
            left++;
        }
    }
    return result;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if (numsSize < 3) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare); // Sort the array first

    int** result = (int**)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip the same result

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates

                left++;
                right--;
            }
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3; // Each row has 3 columns
    }

    return result;
}

int main(void) {
    int nums[] = {2,7,11,15};

    int size;

    int * r = twoSum(nums, 4, 22, &size);

    for (int i = 0; i < size; i++) {
        printf("%d\n", r[i]);
    }
    return 0;
}