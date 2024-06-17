#include <stdlib.h>
#include <stdio.h>

void processSolution(int* sol, int length, int* totalSum) {
    int xorSum = 0;

    // loop over the solution array
    for (int i = 0; i <= length; i++) {
        xorSum ^= sol[i];
    }

    (*totalSum) += xorSum;
}

void backtrack(int* nums, int numsSize, int* solution, int length, int* total) {
    // Process the current subset
    if (length >= 0) {
        processSolution(solution, length, total);
    }

    // Try adding each remaining number to the current subset
    for (int i = 0; i < numsSize; i++) {
        // Avoid re-adding already considered elements
        if (length == -1 || nums[i] > solution[length]) {
            solution[length + 1] = nums[i];
            backtrack(nums, numsSize, solution, length + 1, total);
        }
    }
}

int subsetXORSum(int* nums, int numsSize) {
    int totalSum = 0;
    int* solution = malloc(sizeof(int) * numsSize);

    backtrack(nums, numsSize, solution, -1, &totalSum);

    free(solution);
    return totalSum;
}

int main() {
    int nums[] = {1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = subsetXORSum(nums, numsSize);
    printf("Total XOR Sum: %d\n", result); // Output should be 6 (subsets: {}, {1}, {3}, {1,3})
    return 0;
}
