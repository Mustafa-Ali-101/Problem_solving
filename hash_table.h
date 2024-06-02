#include <stdio.h>
#include <stdlib.h>

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

void printHashTable(HashTable* hashTable) {
    for(int i = 0; i< hashTable->size; i++) {
        HashTableEntry* entry = hashTable->table[i];
        printf("%d -> ", i);
        while (entry != NULL) {
            printf("%d -> ", entry->value);
            entry = entry->next;
        }
        printf("NULL\n");
    }

    return;
}
