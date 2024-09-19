#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct qNode {
    int value;
    struct qNode* next;
} qNode;

typedef struct q {
    qNode* head;
    qNode* tail;
} queue;

queue* makeQueue() {
    queue* q = malloc(sizeof(queue));

    // Memory Allocation failed
    if (q == NULL) {return NULL;}

    q->head = NULL;
    q->tail = NULL;

    return q;
}

bool enqueue(queue* q, int val) {
    // Make a new node
    qNode* n = malloc(sizeof(qNode));

    // Memory Allocation failed
    if (n == NULL) {return false;}

    // Set the values
    n->next = NULL;
    n->value = val;

    // Modigy the tail of the queue
    if (q->tail == NULL) {
        q->tail = n;
        q->head = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }

    return true;
}

bool isEmptyQueue(queue* q) {
    return q->head == NULL;
}

int dequeue(queue* q) {
    // Assuming the queue in not empty
    int result = q->head->value;

    // Store the current head to free it later
    qNode* temp = q->head;

    // Modify the head
    q->head = q->head->next;

    // Modify the tail if needed
    if (q->head == NULL) {
        q->tail = NULL;
    }

    // Free the old head node
    free(temp);

    return result;
}

