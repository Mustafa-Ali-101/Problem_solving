#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "helper.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

bool binarySearch(int* list, int num) {
  int l = 0;
  int r = num - 1;

  while (l <= r) {
    int mid = (r + l) / 2;

    if (list [mid] == num) {
      return true;
    } else if (list[mid] < num) {
      l = mid + 1;
    } else {
      r = mid - 2;
    }
  }

  return false;
}


// Two Sum
int** twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int index = 0;
    int** result = (int**) malloc(sizeof(int*) * (1000));
    
    int left = 0;
    int right = numsSize - 1;
    
    // All TwoSums
    while (left < right) {
      // For Duplicates
      if (left > 0 && nums[left] == nums[left - 1]) {left++; continue;};
      if (right < numsSize - 1 && nums[right] == nums[right + 1]) {right--; continue;};

      // Find Two Sums
      if (nums[left] + nums[right] > target) {
        right--;
      } else if (nums[left] + nums[right] < target) {
        left++;
      } else {
        int* list = (int*) malloc(sizeof(int) * 3);
        list[0] = -1 * target;
        list[1] = nums[left];
        list[2] = nums[right];
        result[index] = list;
        index++;
        // Increase and Decrease
        left++;
        right--;
      }
    }

    *returnSize = index;
    return result;
}
// Leetcode
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  // check
  if (numsSize <= 2) return NULL;
  
  // All Variables
  int** result = malloc(sizeof(int*) * 3000);
  int twoSumSize;
  int returnIndex = 0;

  // 1 - Sort the Array
  qsort(nums, numsSize, sizeof(int), cmpfunc);

  // 2 - Loop over Every unique Number
  for (int i = 0; i < numsSize; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    // 3 - Find Two Sums for that Number in the Remaining List
    int** iThreeSum = twoSum(nums + (sizeof(int) * i), numsSize - i, -1 * nums[i], &twoSumSize);

    // Loop over TwoSum Results
    for (int j = 0; j < twoSumSize; j++) {
      // add the threeSum to the original
      result[returnIndex] = iThreeSum[j];
      returnIndex++; // Increase Index
    }

    // free result
    // Free the memory allocated for the twoSum results.
    for (int j = 0; j < twoSumSize; j++) {
      free(iThreeSum[j]);
    }
    free(iThreeSum);
  }

  // Set returnSize
  (*returnSize) = returnIndex;

  // Set rerurnColumnSizes;
  (*returnColumnSizes) = malloc(sizeof(int) * returnIndex);
  for (int i = 0; i < returnIndex; i++) {
    (*returnColumnSizes)[i] = 3;
  }
  return result;  
}

// Recursion
struct ListNode* swapPairs(struct ListNode* head) {
  // Base Case
  if (head == NULL) return NULL;
  if (head->next == NULL) return head;

  // Recursive Case
  struct ListNode* temp = head->next;
  head->next = swapPairs(temp->next);
  temp->next = head;
  
  return temp;
}
// Main For Test
int main(void) {


  return 0;
}