#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "queue_tree_node.h"


void bfs_traversal(struct TreeNode* root) {
    // Empty Tree
    if (root == NULL) return;

    queue* que = makeQueue();

    enqueue(que, root);


    // The Traversal
    while (!isEmptyQueue(que)) {
        // Visit The Node
        struct TreeNode* ithNode = dequeue(que);

        printf(" %d ", ithNode->val);

        // Add its Children to the queue
        if (ithNode->left != NULL) {
            enqueue(que, ithNode->left);
        }
        if (ithNode->right != NULL) {
            enqueue(que, ithNode->right);
        }
    }

    printf("\n");
    return;
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    // if one tree is NULL
    if (root1 == NULL) {
        return root2;
    } else if (root2 == NULL) {
        return root1;
    }


    // the queue to add the
    // nodes to be added
    queue* q = makeQueue();

    enqueue(q, root1);
    enqueue(q, root2);


    // Untill queue is Empty
    while (!isEmptyQueue(q)) { 
        struct TreeNode* one = dequeue(q);
        struct TreeNode* two = dequeue(q);

        // Add two nodes
        one->val += two->val;

        // Enqueue Left Children
        if (one->left != NULL && two->left != NULL) {
            enqueue(q, one->left);
            enqueue(q, two->left);
        } else if (one->left == NULL) {
            one->left = two->left;
        }

        // Enqueue Right Children
        if (one->right != NULL && two->right != NULL) {
            enqueue(q, one->right);
            enqueue(q, two->right);
        } else if (one->right == NULL) {
            one->right = two->right;
        }
    }

    return root1;
}


double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    // Empty Tree
    if (root == NULL) {
        (*returnSize) = 0;
        return NULL;
    }

    // All Variables and Arrays
    double* averages = malloc(sizeof(double) * 10000);
    int index = 0;

    int currentLevel;
    int temp;
    int nextLevel;
    long sum = 0;

    // Enqueue root
    queue* q = makeQueue();
    enqueue(q, root);
    currentLevel = 1;
    temp = 1;
    nextLevel = 0;


    // While Loop
    while (true)
    {
        // Current Level is finished
        if (temp == 0) {
            averages[index] = (double) sum / currentLevel;
            index++;

            // Next Level
            if (nextLevel == 0) break;
            currentLevel = nextLevel;
            temp = nextLevel;
            nextLevel = 0;
            sum = 0;
        } 
        else { // Continue This Level
            struct TreeNode* n = dequeue(q);
            temp--;
            sum += n->val;

            if (n->left != NULL) {
                enqueue(q, n->left);
                nextLevel++;
            }

            if (n->right != NULL) {
                enqueue(q, n->right);
                nextLevel++;
            }
        }
    }
    
    free(q);

    (*returnSize = index);
    return averages;
}
// Example usage
int main() {

    struct TreeNode* one = malloc(sizeof(struct TreeNode));
    struct TreeNode* two = malloc(sizeof(struct TreeNode));
    struct TreeNode* three = malloc(sizeof(struct TreeNode));
    struct TreeNode* four = malloc(sizeof(struct TreeNode));
    struct TreeNode* five = malloc(sizeof(struct TreeNode));

    one->val = 4;
    one->left = two;
    one->right = five;

    two->val = 2;
    two->left = three;
    two->right = four;

    three->val = 1;
    three->left = NULL;
    three->right = NULL;

    four->val = 3;
    four->left = NULL;
    four->right = NULL;

    five->val = 5;
    five->left = NULL;
    five->right = NULL;


    struct TreeNode* one1 = malloc(sizeof(struct TreeNode));
    struct TreeNode* two2 = malloc(sizeof(struct TreeNode));
    struct TreeNode* three3 = malloc(sizeof(struct TreeNode));
    struct TreeNode* four4 = malloc(sizeof(struct TreeNode));
    struct TreeNode* five5 = malloc(sizeof(struct TreeNode));

    one1->val = 4;
    one1->left = two2;
    one1->right = five5;

    two2->val = 2;
    two2->left = three3;
    two2->right = four4;

    three3->val = 1;
    three3->left = NULL;
    three3->right = NULL;

    four4->val = 3;
    four4->left = NULL;
    four4->right = NULL;

    five5->val = 5;
    five5->left = NULL;
    five5->right = NULL;

    int size;
    double* list = averageOfLevels(one, &size);

    for (int i = 0; i < size; i++) {
        printf("%f ", list[i]);
    }

    return 0;
}