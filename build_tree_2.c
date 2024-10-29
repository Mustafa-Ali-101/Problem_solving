#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    // Base case
    if (inorderSize == 0 || postorderSize == 0) return NULL; 

    // The root value is the last element in the postorder traversal
    int rootVal = postorder[postorderSize - 1];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    // Find the root in inorder to separate left and right subtrees
    int rootIndex = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }

    // Build left and right subtrees
    root->left = buildTree(inorder, rootIndex, postorder, rootIndex);
    root->right = buildTree(inorder + rootIndex + 1, inorderSize - rootIndex - 1, 
                            postorder + rootIndex, postorderSize - rootIndex - 1);

    return root;
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