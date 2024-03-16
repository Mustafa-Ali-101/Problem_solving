#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;    
    struct TreeNode *right;
};

int mad(struct TreeNode* root, int* minimum, int leftRight) {
    // base case
    if (root->left == NULL && root->right == NULL) return root->val;

    if (root->left != NULL && root->right == NULL) {
        int left = mad(root->left, minimum, 1);
        // test for minimum
        if (abs(root->val - left) < (*minimum)) (*minimum) = abs(root->val - left);

        return left;
    } else if (root->left == NULL && root->right != NULL) {
        int right = mad(root->right, minimum, 0);
        // test for minimum
        if (abs(root->val - right) < (*minimum)) (*minimum) = abs(root->val - right);

        return right;       
    } else {
        int left = mad(root->left, minimum, 1);
        int right = mad(root->right, minimum, 0);

        // test for minimum
        if (abs(root->val - left) < (*minimum)) {(*minimum) = abs(root->val - left);}
        if (abs(root->val - right) < (*minimum)) {(*minimum) = abs(root->val - right);}

        // return value
        if (leftRight) {
            return right;
        } else {
            return left;
        }
    }
}

// A global variable to store the previous node value in the inorder traversal
int prev = -1;

// A global variable to store the minimum absolute difference
int minDiff = INT_MAX;

// inorder traversal of a BST
void dfsTraversal(struct TreeNode* root) {
    // Base Case
    if (root == NULL) return;

    // traverse left
    dfsTraversal(root->left);

    // the node itself
    // 1- test for minimum
    if (prev != -1) {
        int diff = abs(root->val - prev);

        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    // 2- set the prev
    prev = root->val;

    // traverse right
    dfsTraversal(root->right);
}
int getMinimumDifference(struct TreeNode* root) {

    prev = -1;
    minDiff = INT_MAX; 

    dfsTraversal(root);

    return minDiff;
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

    three->val = 0;
    three->left = NULL;
    three->right = NULL;

    four->val = 3;
    four->left = NULL;
    four->right = NULL;

    five->val = 6;
    five->left = NULL;
    five->right = NULL;


    int size = getMinimumDifference(one);

    printf("%d ", size);

    return 0;
}