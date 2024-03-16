#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 100

// Node structure for the linked list
typedef struct node {
    int key;
    struct node *next;
} node;

// Hash table structure
typedef struct hashtable {
    node *heads[TABLE_SIZE];
} hashtable;

// Function to create a new hash table
hashtable* create_table() {
    hashtable *table = (hashtable*) malloc(sizeof(hashtable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        table->heads[i] = NULL;
    }
    return table;
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table
void insert(hashtable *table, int key) {
    // Apply the hash function to find the index
    int index = hash(key);
    
    // Create a new node
    node *new_node = (node*) malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;

    // Insert the node at the beginning of the linked list
    if (table->heads[index] == NULL) {
        table->heads[index] = new_node;
    } else {
        new_node->next = table->heads[index];
        table->heads[index] = new_node;
    }
}

// Function to search for a key in the hash table
node* search(hashtable *table, int key) {
    int index = hash(key);
    node *current = table->heads[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the hash table
void print_table(hashtable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node *current = table->heads[i];
        printf("Index %d: ", i);
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main function
// int main() {
//     hashtable *ht = create_table();
    
//     // Insert some keys into the hash table
//     insert(ht, 1);
//     insert(ht, 2);
//     insert(ht, 3);
//     insert(ht, 11); // This will cause a collision with key 1

//     // Search for a key
//     node *found = search(ht, 11);
//     if (found != NULL) {
//         printf("Key found: %d\n", found->key);
//     } else {
//         printf("Key not found\n");
//     }

//     // Print the hash table
//     print_table(ht);

//     // Free the allocated memory
//     // Note: In a real program, you would also need to free the nodes
//     free(ht);

//     return 0;
// }
