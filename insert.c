#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, 
            int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = malloc((intervalsSize + 1) * sizeof(int*));
    int resultIndex = 0;
    int* columnSizes = malloc(sizeof(int) * (intervalsSize + 1));


    if (intervalsSize == 0)
    {
        result[0] = newInterval;
        *returnSize = 1;
        columnSizes[0] = 2;
        *returnColumnSizes = columnSizes;
        return result;
    }

    for (int i = 0; i < intervalsSize; i++)
    {
        if (intervals[i][1] < newInterval[0])
        {
            result[resultIndex++] = intervals[i];
        }
        else if (intervals[i][0] > newInterval[1])
        {
            result[resultIndex++] = newInterval;
            newInterval = intervals[i];
        }
        else
        {
            newInterval[0] = fmin(newInterval[0], intervals[i][0]);
            newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        }
    }
    
    result[resultIndex++] = newInterval;

    *returnSize = resultIndex;
    for (int i = 0; i < resultIndex; i++)
    {
        columnSizes[i] = 2;
    }
    *returnColumnSizes = columnSizes;
    return result;
}

int main(void) {
    return 0;
}