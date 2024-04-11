#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct listNode {
    struct TreeNode* val;
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
bool enqueue(queue *q, struct TreeNode* val) {
    node *newNode = (node*) malloc(sizeof(node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        return false;
    }
    newNode->val = val;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->head = newNode;
    } else {
        q->lastNode->next = newNode;
    }
    q->lastNode = newNode;
    return true;
}

// Function to remove an element from the queue
struct TreeNode* dequeue(queue *q) {
    if (isEmptyQueue(q)) {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    node *tempNode = q->head;
    struct TreeNode* val = tempNode->val;
    q->head = q->head->next;

    if (q->head == NULL) {
        q->lastNode = NULL;
    }

    free(tempNode);
    return val;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    // Empty Tree
    if (root == NULL) {
        (*returnSize) = 0;
        return NULL;
    }
    // Variables
    int** arrayOfArrays = malloc(sizeof(int*) * 2000);
    int* columnSizes = malloc(sizeof(int) * 2000); // Adjusted size
    int index = 0;
    int columnIndex = 0; // Has to Be Reset
    int levelIndicator = 1; // Initial Value Is 1
    queue* q = makeQueue();
    enqueue(q, root);

    // While The Next Level Is Not Empty
    while (!isEmptyQueue(q)) { // Changed condition
        int nextNumOfChildren = 0;
        int* ithArray = malloc(sizeof(int) * levelIndicator);
        columnIndex = 0;
        arrayOfArrays[index] = ithArray;
        columnSizes[index] = levelIndicator;
        index++;

        // dequeue all nodes for that level
        for (int i = 0; i < levelIndicator; i++) {
            struct TreeNode* n = dequeue(q);
            if (n->left != NULL) {
                nextNumOfChildren++;
                enqueue(q, n->left);
            }
            if (n->right != NULL) {
                nextNumOfChildren++;
                enqueue(q, n->right);
            }

            ithArray[columnIndex] = n->val;
            columnIndex++;
        }

        levelIndicator = nextNumOfChildren;
    }

    (*returnSize) = index;
    (*returnColumnSizes) = columnSizes;
    return arrayOfArrays;
}

// Main For Test
int main(void) {

  struct TreeNode* one = malloc(sizeof(struct TreeNode));
  struct TreeNode* two = malloc(sizeof(struct TreeNode));
  struct TreeNode* three = malloc(sizeof(struct TreeNode));

  one->val = 1;
  one->left = two;
  return 0;
}