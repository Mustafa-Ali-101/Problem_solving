#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
// #include "hash_table.h"
#include "helper.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void nextPermutation(int* nums, int numsSize) {
  // Variables
  int lastPeakIndex = -1;
  int replacedIndex = -1;

  // Set vars
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i - 1]) lastPeakIndex = i;
  }
  // Test for No Next Permutation
  if (lastPeakIndex == -1) {
    qsort(nums, numsSize, sizeof(int), compare);
    return;
  }
  replacedIndex = lastPeakIndex - 1;
  // Modify lastPeakIndex if needed
  for (int i = lastPeakIndex + 1; i < numsSize; i++) {
    if (nums[i] > nums[replacedIndex] && nums[i] < nums[lastPeakIndex]) lastPeakIndex = i;
  }

  // Swap
  int temp = nums[replacedIndex];
  nums[replacedIndex] = nums[lastPeakIndex];
  nums[lastPeakIndex] = temp;

  // sort
  int* sortArray = nums + replacedIndex + 1;
  qsort(sortArray, numsSize - (replacedIndex + 1), sizeof(int), compare);

  return;
}


int search(int* nums, int numsSize, int target) {
  int left = 0;
  int right = numsSize - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;

    // Left Subarray
    if (nums[mid] >= nums[left]) {
      if (target > nums[mid] || target < nums[left]) {
          left = mid + 1;
      } else {
          right = mid - 1;
      }
    }
    // Right Subarray 
    else {
      if (target < nums[mid] || target > nums[right]) {
        right = mid - 1;
      } else {
        left = mid + 1;  
      }
    }

  }

  return -1;
}
// Main For Test
int main(void) {

  int arr[] = {5,1,3};
  int size = 3;

  printf("%d \n", search(arr, size, 3));
  return 0;
}
