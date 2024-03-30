#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;

    // Calculate the maximum possible number of quadruplets
    int maxQuadruplets = numsSize * (numsSize - 1) * (numsSize - 2) * (numsSize - 3) / 24; // 4!

    int** result = (int**)malloc(sizeof(int*) * maxQuadruplets);
    if (!result) {
        // Handle memory allocation failure
        return NULL;
    }

    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Outer loop
    for (int i = 0; i < numsSize - 3; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // ThreeSum
        int three = target - nums[i];
        for (int j = i + 1; j < numsSize - 2; j++) {
            // Skip duplicates
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // TwoSum
            long long two = (long long)three - nums[j];
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                long long sum = (long long)nums[left] + nums[right]; // Use long long for sum

                if (sum == two) {
                    // Found a match
                    int* quadruplet = (int*)malloc(sizeof(int) * 4);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[left];
                    quadruplet[3] = nums[right];
                    result[(*returnSize)] = quadruplet;
                    (*returnSize)++;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < two) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    // Set column sizes (assuming all quadruplets have 4 elements)
    int* columns = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        columns[i] = 4;
    }
    (*returnColumnSizes) = columns;

    return result;
}


// Example usage
int main() {
    // Example input (modify as needed)
    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 0;
    int returnSize;
    int* returnColumnSizes;

    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    // Print the quadruplets (you can modify this part as needed)
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Clean up memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}