#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//struct TreeNode* buildRec(int* preorder, int* inorder)
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // Base case
    if (preorderSize == 0 || inorderSize == 0) return NULL; 

    struct TreeNode* newNode = malloc(sizeof(struct TreeNode));
    newNode->val = preorder[0];

    // Search for rootIndex of the preorder node
    // Locate the root in inorder to find the left and right subtrees
    int rootIndex = 0;
    while (rootIndex < inorderSize && inorder[rootIndex] != preorder[0]) {
        rootIndex++;
    }
    
    // Call Left Branch
    newNode->left = buildTree(preorder + 1, rootIndex, inorder, rootIndex);
    newNode->right = buildTree(preorder + rootIndex + 1, preorderSize - rootIndex - 1, 
        inorder + rootIndex + 1, preorderSize - rootIndex);
    

    return newNode;
}



void printPreorder(struct TreeNode *node) {
    if (node == NULL)
        return;

    // Print current node's value
    printf("%d ", node->val);

    // Recur on left subtree
    printPreorder(node->left);

    // Recur on right subtree
    printPreorder(node->right);
}



int main(void) {
    // Example tree construction
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};
    
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};

    // Print the tree
    printPreorder(buildTree(preorder, 5, inorder, 5));

    return 0;
}