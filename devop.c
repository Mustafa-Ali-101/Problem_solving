#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "queue_tree_node.h"
#include "helper.h"

// Not Needed in this Scinario
bool isASolution(int* v, int k, int target) {
  int sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += v[i];
  }
  return sum == target;
}

// Modified
void constructCandidates(int** nc, int* n, int* cand, int candSize, HashTable* hashSet, int target) {
  int* candidates = malloc(sizeof(int) * candSize);
  int index = 0;
  for (int j = 0; j < candSize; j++) {
    if ((j <= 0 || cand[j] != cand[j - 1]) && search(hashSet, cand[j]) != cand[j] && target >= cand[j]) {candidates[index] = cand[j]; index++;}
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
              HashTable* hashSet) {
  // Base Case
  if (target == 0) { // isASolution
    processSolution(v, k, sol, columnSizes, index);
  } else {
    int* candidates;
    int candLength;
    constructCandidates(&candidates, &candLength, cand, candSize, hashSet, target);
    
    k = k + 1;
    //struct ListNode* alreadySearched = copyLinkedList((*listOfSearched));
    for (int i = 0; i < candLength; i++) {
      v[k] = candidates[i];
      backtrack(v, k, target - candidates[i], cand, candSize, sol, columnSizes, index, hashSet);
      insert(hashSet, candidates[i]);
    }
    // Add remove Here
    for (int i = 0; i < candLength; i++) {
      delete(hashSet, candidates[i]);
    }
    // Free Memory
    free(candidates);
  }
  return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  qsort(candidates, candidatesSize, sizeof(candidates[0]), compare);

  int** solutions = malloc(sizeof(int*) * 150);
  int* columnSizes = malloc(sizeof(int) * 150);
  int index = 0;
  int* vector = malloc(sizeof(int) * target);
  HashTable* hashSet = createHashTable(candidatesSize);

  backtrack(vector, -1, target, candidates, candidatesSize, solutions, columnSizes, &index, hashSet);

  freeHashTable(hashSet);

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