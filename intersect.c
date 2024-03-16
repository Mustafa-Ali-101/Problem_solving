#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


// Comparator function for integers qsort
int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Allocate memory for interArray with a reasonable initial size
    int interSize = 0;
    int interCapacity = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* interArray = malloc(sizeof(int) * interCapacity);
    // Check the return value of malloc
    if (interArray == NULL) {
        // Handle the error case
        printf("Memory allocation failed\n");
        *returnSize = 0;
        return NULL;
    }

    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    int left = 0;
    int right = 0;
    while (left < nums1Size && right < nums2Size)
    {
        if (nums1[left] == nums2[right]) {
            // Check if interArray is full and realloc if necessary
            if (interSize == interCapacity) {
                interCapacity *= 2;
                interArray = realloc(interArray, sizeof(int) * interCapacity);
                // Check the return value of realloc
                if (interArray == NULL) {
                    // Handle the error case
                    printf("Memory allocation failed\n");
                    *returnSize = 0;
                    return NULL;
                }
            }
            interArray[interSize] = nums1[left];
            interSize++;
            left++;
            right++;
        } else if (nums1[left] > nums2[right]) {
            right++;
        } else {
            left++;
        }
    }
    
    *returnSize = interSize;

    // Free the unused memory
    interArray = realloc(interArray, sizeof(int) * interSize);

    return interArray;
}


int main (void) {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};

    int size = 0;
    int * result = intersect(nums1, 4, nums2, 2, &size);

    for (int i = 0; i < size; i++) {
        printf("%d  ", result[i]);
    }

    return 0;
}