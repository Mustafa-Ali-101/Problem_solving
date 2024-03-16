#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


typedef struct list_node {
    int val;
    struct list_node * next;
} node;

node* makeStack() {
    node* result = NULL;
    return result;
}

bool pushStack(node** head, int val) {
    node* result = (node*) malloc(sizeof(node));
    result->val = val;

    result->next = (*head);

    (*head) = result;

    return true;
}

int popStack(node** head) {
    int result = -1 ;
    if (*head != NULL) {
      result = (*head)->val;
      (*head) = (*head)->next;
    }
    return result;
}

bool isEmptyStack(node* head) {
  return head == NULL;
}
