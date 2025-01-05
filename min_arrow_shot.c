#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Comparison function to sort intervals by start points
int compareIntervals(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    if (intervalA[0] < intervalB[0]) return -1;
    if (intervalA[0] > intervalB[0]) return 1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    // Sort the intervals by their start points
    qsort(points, pointsSize, sizeof(int*), compareIntervals);

    int numOfArrows = 1;
    int end = points[0][1];

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > end) {
            numOfArrows++;
            end = points[i][1];
        } else {
            end = fmin(end, points[i][1]);
        }
    }

    return numOfArrows;
}

int main() {
    int pointsSize = 2;
    int pointsColSize[] = {2, 2};
    int pointsArray[2][2] = {{-2147483646, -2147483645}, {2147483646, 2147483647}};
    int* points[2];
    for (int i = 0; i < pointsSize; i++) {
        points[i] = pointsArray[i];
    }

    int result = findMinArrowShots(points, pointsSize, pointsColSize);
    printf("Minimum number of arrows needed: %d\n", result);

    return 0;
}