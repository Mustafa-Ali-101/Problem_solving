#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int * returned = malloc(sizeof(int) * codeSize);

    if (k > 0) {
        // the first window
        int sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += code[i];
        }
        returned[0] = sum;

        // Slide the window
        for (int i = 1; i < codeSize; i++) {
            if (i + k > codeSize - 1) {
                sum += (code[i + k - codeSize]) - code[i];
            } else {
                sum += code[i + k] - code [i];
            }

            returned[i] = sum;
        }
    } else if (k < 0) {
        // the first window
        int sum = 0;
        for (int i = - 1; i >= k; i--) {
            sum += code[codeSize - 1 + i];
        }
        returned[codeSize - 1] = sum; 

        // Slide the window
        for (int i = codeSize - 2; i >= 0; i--) {
            if (i + k < 0) {
                sum += (code[codeSize + i + k]) - code[i];
            } else {
                sum += code[i + k] - code [i];
            }

            returned[i] = sum;
        }
    } else {
        for (int i = 0; i < codeSize; i++) {
            returned[i] = 0;
        }
    }


    *returnSize = codeSize;
    return returned;
}


int main(void) {

    int size;
    int code[] = {2,4,9,3};
    int* decoded = decrypt(code, 4, -2, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", decoded[i]);
    }
    return 0;
}