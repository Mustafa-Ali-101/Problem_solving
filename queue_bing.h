#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct listNode {
    int val;
    struct listNode *next;
} node;

typedef struct queueImp {
    node *lastNode;
    node *head;
} queue;

// Function to create a new queue
queue *makeQueue() {
    queue *myQueue = (queue*) malloc(sizeof(queue));
    if (!myQueue) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    myQueue->head = NULL;
    myQueue->lastNode = NULL;
    return myQueue;
}

// Function to check if the queue is empty
bool isEmptyQueue(queue *q) {
    return q->head == NULL;
}

// Function to add an element to the queue
bool enqueue(queue *q, node* n) {
    // node *newNode = (node*) malloc(sizeof(node));
    // if (!newNode) {
    //     fprintf(stderr, "Memory allocation failed.\n");
    //     return false;
    // }
    // newNode->val = val;
    // newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->head = n;
    } else {
        q->lastNode->next = n;
    }
    q->lastNode = n;
    return true;
}

// Function to remove an element from the queue
node* dequeue(queue *q) {
    if (isEmptyQueue(q)) {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        return INT_MIN;
    }

    node *tempNode = q->head;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->lastNode = NULL;
    }

    return tempNode;
}

// Function to print the queue
void printQueue(queue *q) {
    node *current = q->head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}


