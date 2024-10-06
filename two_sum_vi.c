#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to perform in-order traversal and store values in an array
void inorder(struct TreeNode* root, int* nums, int* index) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, nums, index);      // Traverse left subtree
    nums[(*index)++] = root->val;          // Store the node value
    inorder(root->right, nums, index);     // Traverse right subtree
}

// Function to find if there are two elements that add up to the target
bool findTarget(struct TreeNode* root, int k) {
    if (root == NULL) {
        return false;
    }

    // Create an array to store the node values
    int nums[10000];  // Assuming the BST has at most 10000 nodes
    int index = 0;

    // Fill the array with the in-order traversal of the BST
    inorder(root, nums, &index);

    // Two-pointer technique to find two numbers that sum to k
    int left = 0;
    int right = index - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
            return true;  // Found the target sum
        } else if (sum < k) {
            left++;  // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }
    return false; // No such pair found
}

// Helper function to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    // Create a simple BST
    struct TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(7);

    int target = 9;
    if (findTarget(root, target)) {
        printf("Found two elements that sum to %d.\n", target);
    } else {
        printf("No two elements found that sum to %d.\n", target);
    }

    // Free allocated memory (not shown for simplicity)

    return 0;
}
