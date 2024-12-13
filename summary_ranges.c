#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = malloc(sizeof(char*) * 20);
    int resultSize = 0;

    int index = 0;

    while (index < numsSize)
    {
        // Start of the run
        int start = nums[index];

        while (index < numsSize && nums[index] + 1 == nums[index + 1])
        {
            index++;
        }
        
        char* range = malloc(sizeof(char) * 50);
        range[0] = '\0';
        if (start != nums[index]) {
            char startStr[12];
            char indexStr[12];
            sprintf(startStr, "%d", start);
            sprintf(indexStr, "%d", nums[index]);

            strcat(range, startStr);
            strcat(range, "->");
            strcat(range, indexStr);
        } else {
            sprintf(range, "%d", nums[index]);
        }
        result[resultSize] = range;
        resultSize++;

        index++;
    }

    (*returnSize) = resultSize;
    return result;
}

int main(void) {


    return 0;
}