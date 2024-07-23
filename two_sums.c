#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*) malloc(sizeof(int) * 2);

    int left = 0;
    int right = numbersSize - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            result[0] = left + 1;
            result[1] = right + 1;

            return result;
        }
    }
    

    return result;
}


int main(void) {

    int list[] = {2,7,11,15};
    int size;
    int* result = twoSum(list, 4, 18, &size);


    printf("%d %d \n", result[0], result[1]);

    return 0;
}