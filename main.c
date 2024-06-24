#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "queue_tree_node.h"
#include "helper.h"

bool canJump(int* nums, int numsSize) {
    
}

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeLinkedList() {
  return NULL;
}

// Add a new value to the Linked List
void addToLinkedList(int value, struct ListNode** list) {
  struct ListNode* newNode = malloc(sizeof(struct ListNode));
  newNode->val = value;
  newNode->next = NULL;
  if ((*list) == NULL) {
    (*list) = newNode;
  } else {
    newNode->next = (*list);
    (*list) = newNode;
  }
}

// Search the Linked list for a value
bool isInLinkedList(int val, struct ListNode* list) {
  struct ListNode* temp = list;
  while (temp != NULL) {
    if (temp->val == val) return true;
    temp = temp->next;
  }

  return false;
}

// make a new linked list
struct ListNode* copyLinkedList(struct ListNode* old) {
  // Base Case
  if (old == NULL) {
    return NULL;
  } else {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = old->val;
    newNode->next = copyLinkedList(old->next);

    return newNode;
  }
}


// Not Needed in this Scinario
bool isASolution(int* v, int k, int target) {
  int sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += v[i];
  }
  return sum == target;
}



// Modified
void constructCandidates(int** nc, int* n, int* cand, int candSize, struct ListNode** listOfSearched,
 int sum, int target) {
  int* candidates = malloc(sizeof(int) * candSize);
  int index = 0;
  for (int j = 0; j < candSize; j++) {

    if (!isInLinkedList(cand[j], (*listOfSearched)) && (sum + cand[j]) <= target) {candidates[index] = cand[j]; index++;}
  }


  (*nc) = candidates;
  (*n) = index;
  return;
}


void processSolution(int* v, int k, int** sols, int* columnSizes, int* index) {
  int* s = malloc(sizeof(int) * (k + 1));
  for (int i = 0; i <= k; i++) {
    s[i] = v[i];
  }

  sols[(*index)] = s;
  columnSizes[(*index)] = k + 1;
  (*index)++;
  return;
}


void backtrack(int* v, int k, int target, int* cand, int candSize, int** sol, int* columnSizes, int* index,
              struct ListNode** listOfSearched) {
  // Base Case
  int sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += v[i];
  }
  if (sum == target) { // isASolution
    processSolution(v, k, sol, columnSizes, index);
  } else {
    k = k + 1;
    int* candidates;
    int candLength;
    constructCandidates(&candidates, &candLength, cand, candSize, listOfSearched, sum, target);

    struct ListNode* alreadySearched = copyLinkedList((*listOfSearched));
    for (int i = 0; i < candLength; i++) {
      v[k] = candidates[i];
      backtrack(v, k, target, cand, candSize, sol, columnSizes, index, &alreadySearched);
      addToLinkedList(candidates[i], &alreadySearched);
    }
    // Free Memory
    free(candidates);
  }
  return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  int** solutions = malloc(sizeof(int*) * 150);
  int* columnSizes = malloc(sizeof(int) * 150);
  int index = 0;
  int* vector = malloc(sizeof(int) * target);
  struct ListNode* alreadySearched = makeLinkedList();
  backtrack(vector, -1, target, candidates, candidatesSize, solutions, columnSizes, &index, &alreadySearched);

  (*returnSize) = index;
  (*returnColumnSizes) = columnSizes;
  return solutions;
}

// Main For Test
int main() {
    int candidates[] = {2,3,5};
    int numSize = sizeof(candidates) / sizeof(candidates[0]);
    int target = 8;
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum(candidates, numSize, target, &returnSize, &returnColumnSizes);
    printf("Solution set:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]); // Clean up memory
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}