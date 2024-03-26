#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for INT_MAX

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    unsigned closest = INT_MAX;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                return sum; // Exact match found
            }
        }
    }

    return closest;
}


// Main For Test
int main(void) {

  int arr[] = {-1,2,1,-4};

  printf("%d\n", threeSumClosest(arr, 4, 1));
  return 0;
}