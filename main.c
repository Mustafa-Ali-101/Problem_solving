#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"

typedef struct list_node {
    int value;
    struct list_node * next;
} node;

node* makeStack() {
    node* result = NULL;
    return result;
}

bool pushStack(node** head, int val) {
    node* result = (node*) malloc(sizeof(node));
    result->value = val;

    result->next = (*head);

    (*head) = result;

    return true;
}

int popStack(node** head) {
    int result = -1 ;
    if (*head != NULL) {
      result = (*head)->value;
      (*head) = (*head)->next;
    }
    return result;
}

bool isEmptyStack(node* head) {
  return head == NULL;
}

int calPoints(char** operations, int operationsSize);
int main()
{

  char* game[] = {"5","2","C","D","+"};

  int number = calPoints(game, 5);


  printf("%d \n", number);
  return 0;
}

int calPoints(char** operations, int operationsSize) {

  node* stack = makeStack();
  int total = 0;

  for (int i = 0; i < operationsSize; i++) {

    if (strcmp(operations[i], "+") == 0) {

      int one = popStack(&stack);
      int two = popStack(&stack);

      total += one + two;

      pushStack(&stack, two);
      pushStack(&stack, one);
      pushStack(&stack, one + two);

    } else if (strcmp(operations[i], "D") == 0) {

      int one = popStack(&stack);

      total += one * 2;

      pushStack(&stack, one);
      pushStack(&stack, one * 2);

    } else if (strcmp(operations[i], "C") == 0) {

      total -= popStack(&stack);

    } else {

      pushStack(&stack, atoi(operations[i]));
      total += atoi(operations[i]);

    }
  }

  return total;
}