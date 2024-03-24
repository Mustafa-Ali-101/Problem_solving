#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 100

//Structure to represent a hash table entry
typedef struct HashTableEntry {
    int key;
    int value;
    struct HashTableEntry* next;
} HashTableEntry;

// Structure to represent a hash table
typedef struct HashTable {
    int size;
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
            return entry->value;
        }
        entry = entry->next;
    }
    
    // If not found, return -1
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


