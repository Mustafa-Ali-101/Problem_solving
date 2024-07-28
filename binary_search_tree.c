#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insertTree(struct TreeNode** root, int v) {
    struct TreeNode* n;
    // Base Case
    if (*root == NULL) {
        n = (struct TreeNode*) malloc(sizeof(struct TreeNode));

        n->val = v;
        n->left = NULL;
        n->right = NULL;

        *root = n;

        return;
    }

    if (v > (*root)->val) {
        insertTree(&((*root)->right), v);
    } else if (v < (*root)-> val) {
        insertTree(&((*root)->left), v);
    } else {
        return;
    }
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    insertTree(&root, val);

    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) return root;
    
    // Binary Search for the val
    if (root->val > key) {
       root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
       root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        } else {
            // Find Successor of current node
            struct TreeNode* temp = root->right;

            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            
            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }
    }
    
    return root;
}



void inorder(struct TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}


int main() {
    struct TreeNode *root = NULL;
    insertIntoBST(root, 50);
    insertIntoBST(root, 30);
    insertIntoBST(root, 70);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    inorder(root);
    return 0;
}