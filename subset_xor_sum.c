#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


void processSolution(int* sol, int length, int* totalSum) {
    int xorSum = 0;

    // loop over the solution array
    for (int i = 0; i <= length; i++) {
        xorSum = xorSum ^ sol[i];
    }

    (*totalSum) += xorSum;
}



void backtrack(int* nums, int numsSize, int* selected, int selectedSize, int* solution, int length, int* total) {
    


    // Process Solution
    int xorSum = 0;
    for (int i = 0; i <= length; i++) {
        xorSum = xorSum ^ solution[i];
    }
    (*total) += xorSum;    


    // Construct Candidates
    int candIndex = 0;
    int* candidates = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        bool isIn = false;

        // Search in solution vector
        for (int j = 0; j < length; j++) {
            if (nums[i] == solution[j]) {
                isIn = true;
            }
        }

        // Search in selected set
        for (int k = 0; k < selectedSize; k++) {
            if (nums[i] == selected[k]) {
                isIn = true;
            }
        }

        if (!isIn) {
            candidates[candIndex] = nums[i];
            candIndex++;
        }

    }

    for (int i = 0; i < candIndex; i++) {
        printf("%d ", candidates[i]);
    }

    // 
    for (int c = 0; c < candIndex; c++) {
        solution[length] = candidates[candIndex];
        length++;

        backtrack(nums, numsSize, selected, selectedSize, solution, length, total);

        selected[selectedSize] = candidates[candIndex];
        selectedSize++;
    }

    free(candidates);

    return;
}

int subsetXORSum(int* nums, int numsSize) {
    int totalSum = 0;
    int* solVector = malloc(sizeof(int) * numsSize * 2);
    int* selected = malloc(sizeof(int) * numsSize * 2);
    selected[0] = 5;
    
    backtrack(nums, numsSize, selected, 1, solVector, -1, &totalSum);

    return totalSum;
}



int main(void) {


    int list[] = {5,1,6}; // 2

    

    printf("%d\n", subsetXORSum(list, 3));

    return 0;
}





int subsetXORSum(int* nums, int numsSize) {
    int totalSum = 0;
    int totalSubsets = 1 << numsSize; // There are 2^numsSize subsets

    // Iterate over all possible subsets
    for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++) {
        int xorSum = 0;
        for (int i = 0; i < numsSize; i++) {
            // Check if the ith element is in the current subset
            if (subsetMask & (1 << i)) {
                xorSum ^= nums[i];
            }
        }
        totalSum += xorSum;
    }
    return totalSum;
}