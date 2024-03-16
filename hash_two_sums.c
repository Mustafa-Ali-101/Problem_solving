#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
  int val;
  struct node* next;
} node;

// return a hash table of a specified size
node** makeHashTable(int size) {
  node** hashTable =(node**) malloc(sizeof(node*) * size);
  for (int i = 0; i < size; i++) {
    hashTable[i] = NULL;
  }
  return hashTable;
}


// return a hash number for given a number
// and a hash size
int hashFun(int num, int size) {
    long prime = num * 31;
    unsigned result = prime % size;

    return result;
}


// return a boolean after adding to the hash
bool addToHashTable(node** hash, int size, int num) {
  unsigned index = hashFun(num, size);

  node* newNode = (node*) malloc(sizeof(node));
  newNode->val = num;

  if (hash[index] == NULL) {
    newNode->next = NULL;
  } else {
    newNode->next = hash[index];
  }
  

  hash[index] = newNode;
  return true;
}


// a boolean value if the given number is in table
bool isInHashTable(node** hash, int size, int num) {
  unsigned index = hashFun(num, size);

    node* temp;

    if (hash[index] == NULL) {
        temp = NULL;
    } else {
        temp = hash[index];
    }


    while (temp != NULL) {
        if (temp->val == num) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}


// return true if deleted or false if not found
bool deleteFromHashTable(node** hash, int size, int num) {
  unsigned index = hashFun(num, size);

  // if the indexed is null
  if (hash[index] == NULL) {
    return false;
  }

  // if the first in index should be deleted
  // then I should remove it. "modify hash"
  // this is the best approach
  // or make a poiner to tha hash[index] ==> not good

  while (hash[index]->val == num) {
    hash[index] = hash[index]->next;
    if (hash[index] == NULL) return true;
  }
  node* prev = hash[index];
  node* temp = hash[index]->next;

  while (temp != NULL) {
    if (temp->val == num) {
      prev->next = temp->next;
      temp = prev->next;
    } else {
      prev = temp;
      temp = temp->next;
    }
  }

  return true;
}


// print the hash table by indeces
void print_hash_table (node** table, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (table[i] == NULL) {
            printf("%d -----> NULL\n", i);
        } else {
            node* p = table[i];
            printf("%d -----> ", i);
            while (p != NULL) {
                printf("%d -> ", p->val);
                p = p->next;
            }
            printf("END\n");
        }
    }
}