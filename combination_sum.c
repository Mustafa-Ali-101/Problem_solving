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

// Structure to represent a hash table entry
typedef struct HashTableEntry {
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
HashTableEntry* newEntry(int value) {
    HashTableEntry* entry = (HashTableEntry*) malloc(sizeof(HashTableEntry));
    entry->value = value;
    entry->next = NULL;
    return entry;
}

// Hash function to calculate hash code
unsigned int hashCode(HashTable* hashTable, int value) {
    return (unsigned int) value % hashTable->size;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, int value) {
    int bucket = hashCode(hashTable, value);
    HashTableEntry* entry = hashTable->table[bucket];
    
    // Check if the key already exists in the hash table
    while (entry != NULL) {
        if (entry->value == value) {
            return;
        }
        entry = entry->next;
    }
    
    // Insert new entry
    entry = newEntry(value);
    entry->next = hashTable->table[bucket];
    hashTable->table[bucket] = entry;
}

// Function to search for a value by key in the hash table
int search(HashTable* hashTable, int value) {
    int bucket = hashCode(hashTable, value);
    HashTableEntry* entry = hashTable->table[bucket];
    
    while (entry != NULL) {
        if (entry->value == value) {
            return value;
        }
        entry = entry->next;
    }
    
    return INT_MIN;
}

bool delete(HashTable* hashTable, int value) {
    int bucket = hashCode(hashTable, value);
    HashTableEntry* entry = hashTable->table[bucket];

    if (entry->value == value) {
        hashTable->table[bucket] = entry->next;
        return true;
    }

    HashTableEntry* prev = entry;
    entry = entry->next;

    while (entry != NULL)
    {
        if (entry->value == value) {
            prev->next = entry->next;
            return true;
        }

        entry = entry->next;
        prev = prev->next;
    }

    
    return false;
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



// Not Needed in this Scinario
bool isASolution(int* v, int k, int target) {
  int sum = 0;
  for (int i = 0; i <= k; i++) {
    sum += v[i];
  }
  return sum == target;
}

// Modified
void constructCandidates(int** nc, int* n, int* cand, int candSize, HashTable* hashSet, int target) {
  int* candidates = malloc(sizeof(int) * candSize);
  int index = 0;
  for (int j = 0; j < candSize; j++) {
    if ((j <= 0 || cand[j] != cand[j - 1]) && search(hashSet, cand[j]) != cand[j] && target >= cand[j]) {candidates[index] = cand[j]; index++;}
  }


  (*nc) = candidates;
  (*n) = index;
  return;
}

void processSolution(int* v, int k, int** sols, int* columnSizes, int* index) {
  int* s = malloc(sizeof(int) * (k + 1));
  for (int i = 0; i <= k; i++) {
    s[i] = v[i];
  }

  sols[(*index)] = s;
  columnSizes[(*index)] = k + 1;
  (*index)++;
  return;
}

void backtrack(int* v, int k, int target, int* cand, int candSize, int** sol, int* columnSizes, int* index,
              HashTable* hashSet) {
  // Base Case
  if (target == 0) { // isASolution
    processSolution(v, k, sol, columnSizes, index);
  } else {
    int* candidates;
    int candLength;
    constructCandidates(&candidates, &candLength, cand, candSize, hashSet, target);
    
    k = k + 1;
    //struct ListNode* alreadySearched = copyLinkedList((*listOfSearched));
    for (int i = 0; i < candLength; i++) {
      v[k] = candidates[i];
      backtrack(v, k, target - candidates[i], cand, candSize, sol, columnSizes, index, hashSet);
      insert(hashSet, candidates[i]);
    }
    
    // Free Memory
    free(candidates);
  }
  return;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  qsort(candidates, candidatesSize, sizeof(candidates[0]), compare);

  int** solutions = malloc(sizeof(int*) * 150);
  int* columnSizes = malloc(sizeof(int) * 150);
  int index = 0;
  int* vector = malloc(sizeof(int) * target);
  HashTable* hashSet = createHashTable(candidatesSize);

  backtrack(vector, -1, target, candidates, candidatesSize, solutions, columnSizes, &index, hashSet);

  freeHashTable(hashSet);

  (*returnSize) = index;
  (*returnColumnSizes) = columnSizes;
  return solutions;
}