#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Macro for MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Comparison function to sort intervals by start points
int compareIntervals(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, 
            int* returnSize, int** returnColumnSizes) {
    // Base case
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Sort the intervals
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);

    // Allocate space for the result (at most intervalsSize intervals)
    int** result = malloc(intervalsSize * sizeof(int*));
    int resultIndex = 0;

    // Initialize the first interval to merge
    int start = intervals[0][0];
    int end = intervals[0][1];

    // Process all intervals
    for (int i = 1; i < intervalsSize; i++) {
        // If intervals overlap, extend the 'end'
        if (intervals[i][0] <= end) {
            end = MAX(end, intervals[i][1]);
        } else {
            // Store the current merged interval
            int* mergedInterval = malloc(2 * sizeof(int));
            mergedInterval[0] = start;
            mergedInterval[1] = end;
            result[resultIndex++] = mergedInterval;

            // Update to the new interval
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Add the final interval to the result
    int* mergedInterval = malloc(2 * sizeof(int));
    mergedInterval[0] = start;
    mergedInterval[1] = end;
    result[resultIndex++] = mergedInterval;

    // Prepare the column sizes array
    *returnColumnSizes = malloc(resultIndex * sizeof(int));
    for (int i = 0; i < resultIndex; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    // Return the size of the result array
    *returnSize = resultIndex;
    return result;
}

int main(void) {
    // Example intervals as int** (array of arrays)
    int interval1[] = {15, 20};
    int interval2[] = {5, 10};
    int interval3[] = {12, 25};
    int interval4[] = {0, 30};

    // Create an array of pointers to these intervals
    int *intervals[] = {interval1, interval2, interval3, interval4};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Sort the intervals
    qsort(intervals, n, sizeof(int *), compareIntervals);

    // Print the sorted intervals
    printf("Sorted intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d, %d]\n", intervals[i][0], intervals[i][1]);
    }

    return 0;
}