#include <stdio.h>
#include <stdlib.h>

// Structure to represent a hash table entry
typedef struct HashTableEntry {
    int key;
    int value;
    struct HashTableEntry* next;
} HashTableEntry;

// Structure to represent a hash table
typedef struct HashTable {
    int size;
    // List "Array" of pointers to Entries 
    HashTableEntry** table;    
} HashTable;

// Function to create a new hash table entry
HashTableEntry* newEntry(int key, int value) {
    HashTableEntry* entry = (HashTableEntry*) malloc(sizeof(HashTableEntry));
    entry->key = key;
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Hash function to calculate hash code
unsigned int hashCode(HashTable* hashTable, int key) {
    return (unsigned int) key % hashTable->size;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, int key, int value) {
    int bucket = hashCode(hashTable, key);
    HashTableEntry* entry = hashTable->table[bucket];
    
    // Check if the key already exists in the hash table
    while (entry != NULL) {
        if (entry->key == key) {
            // the same number then set the new index
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    
    // Insert new entry
    entry = newEntry(key, value);
    entry->next = hashTable->table[bucket];
    hashTable->table[bucket] = entry;
}

// Function to search for a value by key in the hash table
int search(HashTable* hashTable, int key) {
    int bucket = hashCode(hashTable, key);
    HashTableEntry* entry = hashTable->table[bucket];
    
    while (entry != NULL) {
        if (entry->key == key) {
            // return the index
            return entry->value;
        }
        entry = entry->next;
    }
    
    // If not found, return -1
    // valid because there isn't a negative index
    return -1;
}

// Function to create a new hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*) malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (HashTableEntry**) malloc(sizeof(HashTableEntry*) * size);
    
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    
    return hashTable;
}

// Function to free the hash table
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        HashTableEntry* entry = hashTable->table[i];
        while (entry != NULL) {
            HashTableEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

// LeetCode Two Sum Problem Solution
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*) malloc(sizeof(int) * (*returnSize));
    HashTable* hashTable = createHashTable(numsSize);
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = search(hashTable, complement);
        
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            freeHashTable(hashTable);
            return result;
        }
        
        insert(hashTable, nums[i], i);
    }
    
    freeHashTable(hashTable);
    *returnSize = 0;
    return NULL;
}

// Main function to test the solution
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* indices = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
    
    if (indices != NULL) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found!\n");
    }
    
    return 0;
}
