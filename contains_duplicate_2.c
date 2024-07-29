#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "hash_table.h" 

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

    HashTable* hashTable = createHashTable(1000);

    int i = 0;

    for (i = 0; i < numsSize; i++)
    {
        // Find an equivalent element
        int number = search(hashTable, nums[i]);
        if (number == nums[i]) return true;

        // Add the Element
        insert(hashTable, nums[i]);

        // Remove First
        if (i >= k) {
            delete(hashTable, nums[i - k]);
        } 
    }
    
    return false;
}


int main(void) {


    return 0;
}