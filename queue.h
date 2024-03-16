#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct listNode {
    int val;
    struct listNode * next;
} node;

typedef struct queueImp {
    node* lastNode;
    node* head;
} queue;

queue *makeQueue() {
    queue * myQueue = (queue*) malloc(sizeof(queue));
    myQueue->head = NULL;
    myQueue->lastNode = NULL;

    return myQueue;
}

bool inQueue(queue* q, int val) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;

    // the queue is empty
    if (q->head == NULL && q->lastNode == NULL) {
        q->head = newNode;
        q->lastNode = newNode;
    } else {
        // add it to queue
        q->lastNode->next = newNode;

        // change the last node pointer
        q->lastNode = newNode;
    }
    return true;
}

bool isEmptyQueue(queue* q) {
    return q->lastNode == NULL && q->head == NULL;
}

int deQueue(queue* q) {
    if (!isEmptyQueue(q)) {
        node* resultNode = q->head;
        int value = resultNode->val;

        q->head = q->head->next;
        
        // No Nodes left
        if (q->head == NULL) {
            q->lastNode = NULL;
        }

        free(resultNode);
        return value;
    } else {
        return -404;
    }
}

void printQueue(queue* q) {
    node* temp = q->head;

    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}

