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

// A global variable to store the previous node value in the inorder traversal
int prev = -1;

// A global variable to store the minimum absolute difference
int minDiff = INT_MAX;

// A helper function to traverse the tree in order and update the minimum difference
void inorder(struct TreeNode* root) {
    if (root == NULL) return; // base case
    inorder(root->left); // recursive call for left subtree
    if (prev != -1) { // if the previous node value is valid
        int diff = abs(root->val - prev); // calculate the difference between the current and previous node values
        if (diff < minDiff) { // if the difference is smaller than the minimum difference
            minDiff = diff; // update the minimum difference
        }
    }
    prev = root->val; // update the previous node value to the current node value
    inorder(root->right); // recursive call for right subtree
}

// A function to find the minimum absolute difference in a binary search tree
int getMinimumDifference(struct TreeNode* root) {
    prev = -1; // reset the previous node value to -1
    minDiff = INT_MAX; // reset the minimum difference to the maximum integer
    inorder(root); // traverse the tree in order and update the minimum difference
    return minDiff; // return the minimum difference
}
