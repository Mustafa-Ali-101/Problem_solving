#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int l = 0;
    int r = arrSize - 1;
    int mid;
    int i;
    int index = 0;
    *returnSize = k;

    int* result = (int*) malloc(sizeof(int) * k);

    // Binary Search to find index of element
    while (l <= r)
    {
        mid = ceil(l + (r - l) / 2.0);

        printf("%d \n", arr[mid]);

        if (arr[mid] > x) {
            r = mid - 1;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            break;
        }
    }

    // Make a window of this element and extend it to be K length
    l = mid;
    r = mid;
    for (i = 0; i < k - 1; i++) {
        if (l == 0) {
            r++;
            continue;
        }
        if (r >= arrSize) {
            l--;
            continue;

        }
        if (abs(x - arr[r + 1]) < abs(x - arr[l - 1])) {
            r++;
        } else {
            l--;
        }
    }

    for (i = l; i <= r; i++) {
        result[index] = arr[i];
        index++;
    }

    return result;
}


int main(void) {

    int list[] = {1, 3};
    int n;
    findClosestElements(list, 2, 1, 2, &n);
    return 0;
}