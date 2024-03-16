#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct arrayNode {
  int val;
  int index;
  struct arrayNode* next;
} arrayNode;


typedef struct list_node {
  int value;
  struct list_node * next;
} node;

node* make_stack();
bool push(node** head, int val);
int pop(node** head);
int peek(node* head);
bool isEmpty(node* head);
void print_stack(node* head);
arrayNode** makeHashTable(int size);
int hash_function(int num, int size);
void addToTable(int num, int index, arrayNode** table, int size);
arrayNode* retrieve(int num, arrayNode** table, int size);
void printHashTable(arrayNode** hash, int size);


int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);



int main()
{
  return 0;
}

node* make_stack() {
  return NULL;
}

bool push(node** head, int val) {
    node* result = malloc(sizeof(node));
    result->value = val;
    if ((*head) == NULL) {
      result->next = NULL;
      (*head) = result;
    } else {
      result->next = (*head);
      (*head) = result;
    }

    return true;
}

int pop(node** head) {
    int result = -1;
    if ((*head) != NULL){
      result = (*head)->value;
      (*head) = (*head)->next;
    }
    return result;
}

int peek(node* head) {
    int result = -1;
    if (head != NULL){
      result = head->value;
    }
    return result;
}

bool isEmpty(node* head) {
  return (head == NULL);
}

void print_stack(node* head) {
  node* temp = head;
  while(temp != NULL) {
    printf("%d --> ", temp->value);
    temp = temp->next;
  }
  printf(" NULL\n");
}



/* return a pointer to the hash table of pointers to arrayNodes */
arrayNode** makeHashTable(int size) {

    arrayNode** h = malloc(size * sizeof(arrayNode*));

    /* initializing the hash table */
    for (int i = 0; i < size; i++) {
        h[i] = NULL;
    }
    return h;
}

/* return the hash to the given number and hash size */
int hash_function(int num, int size) {
  unsigned result = 0;
  result = num * 31;
  result = result % size;
  return result;
}

// given a num and index add the arrayNode of both to the table of size size
void addToTable(int num, int index, arrayNode** table, int size) {
    
  unsigned hashIndex = (num * 31) % size;

  arrayNode* arr = malloc(sizeof(arrayNode));
  arr->val = num;
  arr->index = index;


  arr->next = table[hashIndex];
  table[hashIndex] = arr;
}


// return a pointer to the arrayNode needed from the hashtable
arrayNode* retrieve(int num, arrayNode** table, int size) {
  unsigned hashIndex = (num * 31) % size;

  arrayNode* temp = table[hashIndex];
  while (temp != NULL)
  {
    if (temp->val == num) {
      return temp;
    }
    temp = temp->next; 
  }
  
  return NULL;
}


void printHashTable(arrayNode** hash, int size) {
  for (int i = 0; i < size; i++) {
    printf("Index: %d => ", i);
    arrayNode* temp = hash[i];
    while (temp != NULL) {
      printf("%d ", temp->val);
      temp = temp->next;
    }
    printf("\n");
  }
} 
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

  int theSize = nums1Size;

  // allocate, set to -1 and set returnSize variable
  *returnSize = nums1Size;
  int* returnArray = (int*) malloc(sizeof(int) * theSize);
  for(int i = 0; i < theSize; i++) {
    returnArray[i] = -1;
  }

  // make an empty stack
  node* stack = make_stack();

  // a hash table of arrayNodes of (integer, index) from nums1
  arrayNode** hashTable = makeHashTable(theSize);

  // set all entries of hashtable
  for (int i = 0; i < theSize; i++) {
    addToTable(nums1[i], i, hashTable, theSize);
  }


  // The Algorithm itself goes here
  for (int i = 0; i < nums2Size; i++) {
    int peekOfStack = peek(stack);
    if (!isEmpty(stack) && nums2[i] > peekOfStack) {
      while (!isEmpty(stack))
      {
        int nextNumber = pop(&stack);
        arrayNode* pToNode = retrieve(nextNumber, hashTable, theSize);
        returnArray[pToNode->index] = nums2[i];
      }
    }

    if (retrieve(nums2[i], hashTable, theSize)) {
      push(&stack, nums2[i]);
    }
  }





  return returnArray;
}