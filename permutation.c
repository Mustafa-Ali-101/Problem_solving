#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"

bool isASolution(int numsSize, int k) {
    return k == numsSize;
}

void processSolution(int* solution, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", solution[i]);
    }

    printf("\n");
}

int* consturctCandidates(int* nums, int numsSize, int* solution, int k, int* candIndex) {
    int* candidates = malloc(sizeof(int) * numsSize);
    (*candIndex) = 0;

    // build a hashtable
    HashTable* hashTable =  createHashTable(numsSize);
    for(int j = 0; j < k; j++) {
        insert(hashTable, solution[j]);
    }

    for(int i = 0; i < numsSize; i++) {
        
        if (search(hashTable, nums[i]) != nums[i]) {
            candidates[(*candIndex)] = nums[i];
            (*candIndex)++;    
        }
    }

    freeHashTable(hashTable);

    return candidates;
}



// Modified constructCandidates to handle duplicates
int* constructCandidatess(int* nums, int numsSize, int* solution, int k, int* candIndex) {
    int* candidates = malloc(sizeof(int) * numsSize);
    *candIndex = 0;

    // Track used elements in the current recursion level
    bool used[numsSize];
    memset(used, 0, sizeof(used));

    for (int i = 0; i < numsSize; i++) {
        bool alreadyInSolution = false;
        for (int j = 0; j < k; j++) {
            if (solution[j] == nums[i]) {
                alreadyInSolution = true;
                break;
            }
        }
        if (!alreadyInSolution && !used[i]) {
            candidates[*candIndex] = nums[i];
            (*candIndex)++;
            used[i] = true;
        }
    }

    return candidates;
}



void backtrack(int* nums, int numsSize, int* solution, int k) {
    // if is a solution
    if (isASolution(numsSize, k)) {
        processSolution(solution, k);
    } else {
        // Test if extendable
        if (k < numsSize) {
            //Construct Candidates
            int candIndex;
            int* candidates = constructCandidatess(nums, numsSize, solution, k, &candIndex);

            for (int m = 0; m < candIndex; m++) {
                solution[k] = candidates[m];
                backtrack(nums, numsSize, solution, k + 1);
            }
        }
    }

    return;
}


void permutation(int * nums, int numsSize) {
    int* solutionVector = malloc(sizeof(int) * numsSize);
    backtrack(nums, numsSize, solutionVector, 0);
}


int main (void) {

    int list[] = {1, 2, 3, 1};

    permutation(list, 4);


    return 0;
}