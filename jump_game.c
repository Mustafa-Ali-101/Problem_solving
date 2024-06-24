#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool canJump(int* nums, int numsSize) {
    int maxJump = 0;

    // If the array is only one element
    // return true
    if (numsSize == 1) return true;

    for (int i = 0; i < numsSize; i++) {
        // Increment the jump if possible
        // What this element can reach
        if (i + nums[i] > maxJump) {
            maxJump = i + nums[i];

            // If maxJump exceed the array
            // early termination
            if (maxJump >= numsSize - 1) return true;
        }

        

        // If the element can only reach itself
        // return false
        if (maxJump == i) return false;
    }

    return true;
}

int main(void) {

    int list[] = {2, 0, 0};

    printf("%d \n", canJump(list, 3));


    return 0;
}