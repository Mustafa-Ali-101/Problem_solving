#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Helper function to check if the current solution is a complete permutation
bool isASolution(int numsSize, int k) {
    return k == numsSize;
}

// Helper function to print the current solution
void processSolution(int* solution, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Modified constructCandidates to handle duplicates
int* constructCandidates(int* nums, int numsSize, int* solution, int k, int* candIndex) {
    int* candidates = malloc(sizeof(int) * numsSize);
    *candIndex = 0;

    bool used[numsSize];
    memset(used, 0, sizeof(used));

    for (int i = 0; i < numsSize; i++) {
        bool alreadyInSolution = false;
        for (int j = 0; j < k; j++) {
            if (solution[j] == nums[i]) {
                alreadyInSolution = true;
                break;
            }
        }
        if (!alreadyInSolution && !used[i]) {
            candidates[*candIndex] = nums[i];
            (*candIndex)++;
            used[i] = true;

            // Skip duplicates
            while (i + 1 < numsSize && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }

    return candidates;
}

// Backtracking function to generate permutations
void backtrack(int* nums, int numsSize, int* solution, int k) {
    if (isASolution(numsSize, k)) {
        processSolution(solution, k);
    } else {
        if (k < numsSize) {
            int candIndex;
            int* candidates = constructCandidates(nums, numsSize, solution, k, &candIndex);

            for (int m = 0; m < candIndex; m++) {
                solution[k] = candidates[m];
                backtrack(nums, numsSize, solution, k + 1);
            }
            free(candidates);
        }
    }
}

// Main function to generate all permutations
void permutation(int* nums, int numsSize) {
    int* solutionVector = malloc(sizeof(int) * numsSize);

    // Sort the array to handle duplicates
    qsort(nums, numsSize, sizeof(int), compare);

    backtrack(nums, numsSize, solutionVector, 0);

    free(solutionVector);
}

// Example usage
int main() {
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    permutation(nums, numsSize);
    return 0;
}

