#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "hash_table.h"

bool isFirst(HashTable* table, int value) {
    if (search(table, value - 1) == (value - 1)) return false;

    return true;
}

int longestConsecutive(int* nums, int numsSize) {
    int longest = 0;

    if (numsSize == 0) return longest;

    HashTable* hashTable = createHashTable(numsSize);

    // Insert All Numbers
    for (int i = 0; i < numsSize; i++) {
        insert(hashTable, nums[i]);
    }

    // Count longest consecutive
    for (int i = 0; i < numsSize; i++) {
        // First element in consecutive run
        if (isFirst(hashTable, nums[i])) {
            int length = 1;

            while (search(hashTable, nums[i] + length) == (nums[i] + length))
            {
                length++;
            }
            
            // Compare with Longest so far
            longest = length > longest ? length : longest;
        }
    }

    freeHashTable(hashTable);

    return longest;
}

int main(void) {

}