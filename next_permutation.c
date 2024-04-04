#include <stdio.h>

// swap two integers in place
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int* nums, int l, int r) {
    while (l < r) {
        swap(&nums[l], &nums[r]);
        l++;
        r--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i;
    for (i = numsSize - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            break;
        }
    }

    if (i >= 0) {
        for (int j = numsSize - 1; j > i; --j) {
            if (nums[j] > nums[i]) {
                swap(&nums[i], &nums[j]);
                break;
            }
        }
        reverse(nums, i + 1, numsSize - 1);
    } else {
        // If no next permutation, sort in ascending order
        reverse(nums, 0, numsSize - 1);
    }
}

int main() {
    int nums[] = {1, 2, 3}; // Example input
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    nextPermutation(nums, numsSize);

    printf("Next permutation: ");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
