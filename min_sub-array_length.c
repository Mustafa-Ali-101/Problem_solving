#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int minLength = INT_MAX;
    int sum = nums[0];
    int left = 0;
    int right = 0;

    while (right < numsSize) {
        // Compare to targe
        if (sum >= target) {
            // Better Solution
            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
            }

            // Remove the first Element
            sum -= nums[left];
            left++;
        } else {
            right++;
            sum += nums[right];
        }
    }

    return minLength == INT_MAX ? 0 : minLength;
}


int main(void) {

    return 0;
}