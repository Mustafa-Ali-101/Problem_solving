#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Global Variables
int max;

int dfsTraversal(struct TreeNode* root) {
    // Base Case
    if (root == NULL) return 0;

    // Recursive Call Left
    int leftWing = dfsTraversal(root->left);

    // Recursive Call Right
    int rightWing = dfsTraversal(root->right);

    // The Node At Hand
    // Test For Maximum
    if (leftWing + rightWing > max) {
        max = leftWing + rightWing;
    }

    // Return Bigger of Paths
    if (leftWing > rightWing) {
        return leftWing + 1;
    } else {
        return rightWing + 1;
    }
}

int diameterOfBinaryTree(struct TreeNode* root) {
    max = 0;
    dfsTraversal(root);

    return max;
}

int main (void) {
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

    three->val = 2;
    three->left = NULL;
    three->right = NULL;

    four->val = 3;
    four->left = NULL;
    four->right = NULL;

    five->val = 4;
    five->left = NULL;
    five->right = NULL;


    int size;
    int* result = findMode(one, &size);


    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}