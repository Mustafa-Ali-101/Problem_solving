#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MIN_INT -1234759

typedef struct list_node {
    int value;
    struct list_node * next;
} node;

node* make_stack(int n) {
    node* result = malloc(sizeof(node));
    result -> value = n;
    result -> next = NULL;
    return result;
}

bool push_s(node** head, int val) {
    node* result = malloc(sizeof(node));
    result->value = val;
    result->next = *head;
    (*head) = result;

    return true;
}

int pop_s(node** head) {
    int result = MIN_INT;
    if (*head == NULL) {
        return result;
    } else {
        result = (*head)->value;
        (*head) = (*head)->next;
    }
    return result;
}