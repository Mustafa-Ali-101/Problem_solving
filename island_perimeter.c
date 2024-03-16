#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int sum = 0;
    int colSize = gridColSize[0];

    for (int i = 0; i < gridSize; i++) {
        for (j = 0; j < colSize; j++) {
            if (grid[i][j]) {
                sum += 4;
                if (i - 1 >= 0 && grid[i - 1][j]) sum -= 1; // above
                if (i + 1 < gridSize && grid[i + 1][j]) sum -= 1; // below
                if (j - 1 >= 0 && grid[i][j - 1]) sum -= 1; // on the left
                if (j + 1 < colsSize && grid[i][j + 1]) sum -= 1; // on the right
            }
        }
    }

    return sum;
}