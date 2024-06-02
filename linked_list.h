#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* makeLinkedList() {
  return NULL;
}

// Add a new value to the Linked List
void addToLinkedList(int value, struct ListNode** list) {
  struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
  newNode->val = value;
  newNode->next = NULL;
  if ((*list) == NULL) {
    (*list) = newNode;
  } else {
    newNode->next = (*list);
    (*list) = newNode;
  }
}

bool removeFromLinkedList(int value, struct ListNode** list) {
    if ((*list) == NULL) return false;
    struct ListNode* temp = (*list);
    struct ListNode* prev = (*list);

    if (temp->val == value) {
      (*list) = temp->next;
      return true;
    }

    temp = temp->next;
    // While Loop
    while (temp != NULL) {
        if (temp->val == value) {
            prev->next = temp->next;
            return true;
        }

        temp = temp->next;
        prev = prev->next;
    }

    return false;
}
// Search the Linked list for a value
bool isInLinkedList(int val, struct ListNode* list) {
  struct ListNode* temp = list;
  while (temp != NULL) {
    if (temp->val == val) return true;
    temp = temp->next;
  }

  return false;
}

// make a new linked list
struct ListNode* copyLinkedList(struct ListNode* old) {
  // Base Case
  if (old == NULL) {
    return NULL;
  } else {
    struct ListNode* newNode =(struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->val = old->val;
    newNode->next = copyLinkedList(old->next);

    return newNode;
  }
}

void printLinkedList(struct ListNode* list) {
    struct ListNode* temp = list;
    
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return;
}

