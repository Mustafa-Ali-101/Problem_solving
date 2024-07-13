#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int trap(int* height, int heightSize) {
    // Empty Input
    if (heightSize == 0) return 0;

    int total = 0;
    int left = 0;
    int right = heightSize - 1;
    
    int maxL = height[left];
    int maxR = height[right];

    while (right > left) {
        if (height[left] < height[right]) {
            // Shift
            left++;

            // MaxL
            maxL = height[left] > maxL ? height[left] : maxL;

            // Calculate "Smart Move"
            total += maxL - height[left];
        } else {
            // Shift
            right--;

            // MaxR
            maxR = height[right] > maxR ? height[right] : maxR;

            //Calculate
            total += maxR - height[right];
        }
    }

    return total;
}

int main(void) {
    int list[] = {0,1,0,2,1,0,1,3,2,1,2,1};  // 12


    printf("%d \n", trap(list, 12));

    return 0;
}