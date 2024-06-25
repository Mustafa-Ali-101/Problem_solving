#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int jumpRecursive(int index, int range, int* nums, int numsSize, int best_jump, int steps) {
    // Base Case
    if (range >= numsSize - 1) {
        return steps;
    }

    // Set best_jump so far
    if (nums[index] + index > best_jump) {
        best_jump = nums[index] + index;
    }

    // Reached end of range
    if (index == range) {
        steps++;
        range += best_jump;
    }

    // Recursive Call
    jumpRecursive(index + 1, range, nums, numsSize, best_jump, steps);
}

int jump(int* nums, int numsSize) {
    int steps = 0;
    int range = 0;
    int bestJump = 0;

    for (int i = 0; i < numsSize; i++) {
        // Test for range out of bound
        if (range >= numsSize - 1) break;

        // Set bestJump so far
        if (nums[i] + i > bestJump) {
            bestJump = nums[i] + i;
        }

        // Check frr end of range
        if (i == range) {
            range = bestJump;
            steps++;
        }
    }
    
    return steps;
}



int main(void) {

    int list[] = {2,3,1,1,4};

    printf("Steps: %d ", jump(list, 5));
    return 0;
}