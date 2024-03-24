#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort.
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// TwoSum function using two pointers technique.
void twoSum(int *nums, int numsSize, int target, int **results, int *returnSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        } else {
            // Allocate memory for the new pair and store the result.
            results[*returnSize] = (int *)malloc(2 * sizeof(int));
            results[*returnSize][0] = nums[left];
            results[*returnSize][1] = nums[right];
            (*returnSize)++;
            
            // Move the pointers and skip duplicates.
            do { left++; } while (left < right && nums[left] == nums[left - 1]);
            do { right--; } while (left < right && nums[right] == nums[right + 1]);
        }
    }
}

// ThreeSum function.
int **threeSum(int *nums, int numsSize, int *returnSize) {
    // Sort the array.
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Allocate memory for the results.
    int **results = (int **)malloc(numsSize * numsSize * sizeof(int *));
    *returnSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Skip duplicates.
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Call twoSum for the remaining part of the array.
        int newTarget = -nums[i];
        int twoSumSize = 0;
        int **twoSumResults = (int **)malloc((numsSize - i - 1) * sizeof(int *));
        twoSum(&nums[i + 1], numsSize - i - 1, newTarget, twoSumResults, &twoSumSize);
        
        // Store the results from twoSum into the final results array.
        for (int j = 0; j < twoSumSize; j++) {
            results[*returnSize] = (int *)malloc(3 * sizeof(int));
            results[*returnSize][0] = nums[i];
            results[*returnSize][1] = twoSumResults[j][0];
            results[*returnSize][2] = twoSumResults[j][1];
            (*returnSize)++;
        }
        
        // Free the memory allocated for the twoSum results.
        for (int j = 0; j < twoSumSize; j++) {
            free(twoSumResults[j]);
        }
        free(twoSumResults);
    }
    
    return results;
}

// Example usage.
int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int **triplets = threeSum(nums, numsSize, &returnSize);
    
    // Print the triplets.
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d]\n", triplets[i][0], triplets[i][1], triplets[i][2]);
        free(triplets[i]); // Don't forget to free the memory!
    }
    free(triplets); // Free the memory allocated for the triplets.
    
    return 0;
}
