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

// A helper function to traverse the tree inorder and store the values and frequencies in arrays
void inorder(struct TreeNode* root, int* values, int* freqs, int* size, int* maxFreq) {
    if (root == NULL) return; // base case
    inorder(root->left, values, freqs, size, maxFreq); // recursive call for left subtree

    // the Node At Hand
    if (*size > 0 && values[*size - 1] == root->val) { // if the current value is the same as the previous one
        freqs[*size - 1]++; // increment the frequency of the last element
    } else { // if the current value is different from the previous one
        values[*size] = root->val; // append the current value to the values array
        freqs[*size] = 1; // set the frequency of the current value to 1
        (*size)++; // increment the size of the arrays
    }
    if (freqs[*size - 1] > *maxFreq) { // if the frequency of the current value is greater than the maximum frequency
        *maxFreq = freqs[*size - 1]; // update the maximum frequency
    }
    inorder(root->right, values, freqs, size, maxFreq); // recursive call for right subtree
}

// A function to find the mode in a binary search tree
int* findMode(struct TreeNode* root, int* returnSize){
    int* values = (int*)malloc(10000 * sizeof(int)); // an array to store the values in the tree
    int* freqs = (int*)malloc(10000 * sizeof(int)); // an array to store the frequencies of the values
    int size = 0; // the size of the arrays
    int maxFreq = 0; // the maximum frequency of any value
    inorder(root, values, freqs, &size, &maxFreq); // traverse the tree in order and fill the arrays
    int* modes = (int*)malloc(size * sizeof(int)); // an array to store the modes
    int modeCount = 0; // the number of modes
    for (int i = 0; i < size; i++) { // loop through the arrays
        if (freqs[i] == maxFreq) { // if the frequency of the current value is equal to the maximum frequency
            modes[modeCount] = values[i]; // append the current value to the modes array
            modeCount++; // increment the number of modes
        }
    }
    *returnSize = modeCount; // set the return size to the number of modes
    return modes; // return the modes array
}
