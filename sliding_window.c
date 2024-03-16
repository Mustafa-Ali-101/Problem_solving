#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"



// maximum sum of ‘k’ consecutive elements in the array
int maxSum(int * seq,int seqSize, int k) {
    int maxSum = 0;
    for (int i = 0; i <= seqSize - k; i++) {

        int ithSum = 0;
        for (int j = 0; j < k; j++) {
            ithSum += seq[i + j];
        }

        if (ithSum > maxSum) {
            maxSum = ithSum;
        }
    }

    return maxSum;
}

int maxSumSliding(int * seq, int seqSize, int k) {
    int maxSum = 0;
    int currentSum = 0;
    if (k > seqSize) return -1;
    for (int i = 0; i < k; i++) {
        currentSum += seq[i];
        maxSum = currentSum;
    }

    for (int i = k; i < seqSize; i++) {
        currentSum += seq[i] - seq[i - k];
        if (currentSum > maxSum) maxSum = currentSum;
    }

    return maxSum;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize <= 1) return false;
    if (numsSize == 0 && k == 0) return true;



    int setSize = 3;
    node** set = makeHashTable(setSize);
    int loops = k;
    if (k > numsSize) loops = numsSize;

    // working with the first window
    for (int i = 0; i < loops; i++) {
        if (isInHashTable(set, setSize, nums[i])) return true;
        addToHashTable(set, setSize, nums[i]);
    }

    for (int i = k; i < numsSize; i++) {
        deleteFromHashTable(set, setSize, nums[i - (k + 1)]);
        if (isInHashTable(set, setSize, nums[i])) return true;
        addToHashTable(set, setSize, nums[i]);
    }


    return false;
}

int missingNumber(int* nums, int numsSize) {
    node** hashSet = makeHashTable(numsSize);
    for (int i = 0; i < numsSize; i++) {
        addToHashTable(hashSet, numsSize, nums[i]);
    }

    for (int i = 0; i <= numsSize; i++) {
        if (!isInHashTable(hashSet, numsSize, i)) return i;
    }

    return -1;
}

int* numToList(long long num, int* returnSize) {
    int capacity = 10;
    int* list = malloc(sizeof(int) * 10);
    int index = 0;

    while(num > 0) {
        int ithNum = num % 10;

        

        if (index == capacity) {
            capacity *= 2;
            list = realloc(list, capacity * sizeof(int));
        }
        list[index] = ithNum;
        index++;

        num = num / 10;
    }

    // Realloc if possible
    list = realloc(list, index * sizeof(int));

    // reverse the array
    for (int i = 0; i < (index / 2); i++) {
        int temp = list[i];
        list[i] = list[index - 1 - i];
        list[index - 1 - i] = temp;
    }

    *returnSize = index;
    return list;
}

int divisorSubstrings(int num, int k) {
    int kBeauty = 0;
    int size;
    int* arrayFromNum = numToList(num, &size);

    int sub = 0;

    // First Window
    for (int i = 0; i < k; i++) {
        sub += arrayFromNum[i] * pow(10, k - 1 - i);
    }
    if (sub != 0 && num % sub == 0) kBeauty++;


    for (int i = k; i < size; i++) {
        sub = sub % (int) pow(10, k - 1);
        sub *= 10;
        sub += arrayFromNum[i];
        if (sub != 0 && num % sub == 0) kBeauty++;
    }

    free(arrayFromNum);

    return kBeauty;
}


int main(void) {
    int size;
    int* array = numToList(430043, &size);


    for (int i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }

    printf("\n###############\n ");

    printf("%d\n", divisorSubstrings(430043, 2));


    return 0;
}

