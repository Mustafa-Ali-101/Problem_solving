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

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  int left = 0;
  int right = numsSize - 1;
  (*returnSize) = 2;
  int* returnArray = (int*) malloc(sizeof(int) * (*returnSize));
  returnArray[0] = -1;
  returnArray[1] = -1;

  while (left <= right)
  {
    int mid = left + ((right - left) / 2);
    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      returnArray[0] = mid;
      returnArray[1] = mid;

      // Search Right Array
      int l = mid + 1;
      int r = right;
      while (l <= r)
      {
        int m = l + ((r - l) / 2);
        if (nums[m] > target) {
          r = m - 1;
        } else {
          returnArray[1] = m;
          l = m + 1;
        }
      }
      
      // Search Left Array
      l = left;
      r = mid - 1;
      while (l <= r)
      {
        int m = l + ((r - l) / 2);
        if (nums[m] < target) {
          l = m + 1;
        } else {
          returnArray[0] = m;
          r = m - 1;
        }
      }

      break;;
    }
      
  }

  return returnArray;
}


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
}


// Main For Test
int main(void) {

  int arr[] = {5,7,7,8,8,10};
  int size = 6;

  int s;
  int* r = searchRange(arr, size, 8, &s);

  printf("%d ", r[0]);
  printf("%d ", r[1]);
  return 0;
}
