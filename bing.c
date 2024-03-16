#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// A helper function to find all the paths from a node to the leaf nodes
void findPaths(struct TreeNode* node, char* path, char** result, int* returnSize) {
    // Base case: if the node is null, return
    if (node == NULL) {
        return;
    }
    // Append the node's value to the path, separated by a "->"
    char buffer[12]; // A buffer to store the node's value as a string
    sprintf(buffer, "%d", node->val); // Convert the node's value to a string
    strcat(path, buffer); // Concatenate the buffer to the path
    // If the node is a leaf, add the path to the result and return
    if (node->left == NULL && node->right == NULL) {
        result[*returnSize] = malloc(strlen(path) + 1); // Allocate memory for the path
        strcpy(result[*returnSize], path); // Copy the path to the result
        (*returnSize)++; // Increment the return size
        return;
    }
    // Recursively call the function on the node's left and right children, passing the same path and result
    strcat(path, "->"); // Add a "->" to the path
    int len = strlen(path); // Store the length of the path
    findPaths(node->left, path, result, returnSize); // Call the function on the left child
    path[len] = '\0'; // Restore the path to its original length
    findPaths(node->right, path, result, returnSize); // Call the function on the right child
}

// A function to find all the paths from the root to the leaf nodes in a binary tree
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    // Initialize an empty string and an empty list of strings
    char* path = malloc(1000); // Allocate memory for the path
    path[0] = '\0'; // Set the path to an empty string
    char** result = malloc(1000 * sizeof(char*)); // Allocate memory for the result
    *returnSize = 0; // Set the return size to zero
    // Call the helper function with the root, the path, and the result
    findPaths(root, path, result, returnSize);
    // Return the result
    return result;
}
