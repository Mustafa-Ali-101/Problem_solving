#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct queue {
    int head;
    int tail;
    int numOfElements;
    int queueSize;
    int* values;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    q->numOfElements = 0;
    q->queueSize = size;
    q->values = (int*) malloc(sizeof(int) * size);

    return q;
}

bool enqueue(Queue* q, int val) {
    // Check if the queue is full
    if (q->numOfElements == q->queueSize) {
        printf("\n#The queue is full!#\n");
        return false;
    }

    q->values[q->tail] = val;

    // Increment Tail in a circular fashion
    q->tail = (q->tail + 1) % q->queueSize;

    q->numOfElements++;
    return true;
}

int dequeue(Queue* q) {
    // Check if the queue is empty
    if (q->numOfElements == 0) {
        printf("\n#The queue is empty!#\n");
        return INT_MIN; // Return INT_MIN if the queue is empty
    }

    int val = q->values[q->head];

    // Increment Head in a circular fashion
    q->head = (q->head + 1) % q->queueSize;

    q->numOfElements--;
    return val;
}

void freeQueue(Queue* q) {
    free(q->values);  // Free the array
    free(q);          // Free the queue structure
}
