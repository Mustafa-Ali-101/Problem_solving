#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Total elements in the result array
    *returnSize = matrixSize * (*matrixColSize);
    
    // Allocate space for the result array
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    if (!result) return NULL; // Check memory allocation

    // Initialize boundaries
    int top = 0, bottom = matrixSize;
    int left = 0, right = *matrixColSize;
    int index = 0; // Index for the result array

    // Traverse the matrix in a spiral order
    while (top < bottom && left < right) {
        // Traverse from left to right across the top row
        for (int i = left; i < right; i++) {
            result[index++] = matrix[top][i];
        }
        top++; // Move the top boundary down
        
        // Traverse from top to bottom along the right column
        for (int i = top; i < bottom; i++) {
            result[index++] = matrix[i][right - 1];
        }
        right--; // Move the right boundary left
        
        // Traverse from right to left across the bottom row, if applicable
        if (top < bottom) {
            for (int i = right - 1; i > left - 1; i--) {
                result[index++] = matrix[bottom - 1][i];
            }
            bottom--; // Move the bottom boundary up
        }
        
        // Traverse from bottom to top along the left column, if applicable
        if (left < right) {
            for (int i = bottom - 1; i > top - 1; i--) {
                result[index++] = matrix[i][left];
            }
            left++; // Move the left boundary right
        }
    }

    return result;
}



int main() {
    // Example input matrix
    int rows = 3, cols = 3;
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Converting static 2D array to pointer-to-pointer
    int* matrix[3];
    for (int i = 0; i < rows; i++) {
        matrix[i] = mat[i];
    }
    
    // Column sizes
    int matrixColSize[3] = {3, 3, 3};
    int returnSize;
    
    // Call the function
    int* result = spiralOrder(matrix, rows, matrixColSize, &returnSize);
    
    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    
    // Free allocated memory
    free(result);
    
    return 0;
}
