#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int cmp(const void* a, const void* b) {
    return *(const int*) a - *(const int*) b;
}

void backtrack(int* candidates, int candidatesSize, int target, 
            int start, int cidx, int* returnSize, 
            int** returnColumnSizes, int** res, int* chosen) {
    if (target == 0) {
        (*returnColumnSizes)[(*returnSize)] = cidx;
        res[(*returnSize)] = (int*) malloc(cidx * sizeof(int));
        memcpy(res[(*returnSize)], chosen, cidx * sizeof(int));
        (*returnSize)++;
    } else {
        for (int i = start; i < candidatesSize; i++) {
            if (target - candidates[i] < 0) break;
            chosen[cidx] = candidates[i];
            backtrack(candidates, candidatesSize, target - candidates[i], 
                        i, cidx + 1, returnSize, 
                        returnColumnSizes, res, chosen);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    *returnSize = 0;
    int size = 1000;
    int** res = (int**) malloc(size * sizeof(int*));
    int* chosen = (int*) malloc(size * sizeof(int));
    *returnColumnSizes = (int*) calloc(size, sizeof(int));
    backtrack(candidates, candidatesSize, target, 
                0, 0, returnSize, 
                returnColumnSizes, res, chosen);
    free(chosen);
    return res;
}
int main (void) {
    
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

    return 0;
}