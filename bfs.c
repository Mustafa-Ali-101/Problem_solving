#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "queue.h"

struct TreeNode {
    int val;
    struct TreeNode *left;    
    struct TreeNode *right;
};

// Global Variables Needed
int* modes;
int modesIndex;
int modeCount;
int prev;
int prevCount;

// helper function make modes array using DFS
void dfs_traversal(struct TreeNode* root) {
    // Base Case
    if (root == NULL) return;

    // Recursive Call Left
    dfs_traversal(root->left);

    // Work At Hand
    if (root->val == prev) {
        prevCount++;
    } else {
        // Test For The Mode
        if (prevCount > modeCount) {
            modes[0] = prev;
            modesIndex = 1;
            modeCount = prevCount;
        } else if (prevCount == modeCount) {
            modes[modesIndex] = prev;
            modesIndex++;
        }

        // Reset
        prev = root->val;
        prevCount = 1;
    }


    // Recursive Call Right
    dfs_traversal(root->right);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    // Set All Varailbles And Arrays
    modes = malloc(sizeof(int) * 10000);
    modesIndex = 0;
    modeCount = 0;
    prev = INT_MAX;
    prevCount = INT_MIN;

    dfs_traversal(root);

    // Test For The Mode
    if (prevCount > modeCount) {
        modes[0] = prev;
        modesIndex = 1;
        modeCount = prevCount;
    } else if (prevCount == modeCount) {
        modes[modesIndex] = prev;
        modesIndex++;
    }

    // Realloc the result and Return
    modes = realloc(modes, sizeof(int) * modesIndex);
    (*returnSize) = modesIndex;
    return modes;
}

int main (void) {
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

    three3->val = 2;
    three3->left = NULL;
    three3->right = NULL;

    four4->val = 3;
    four4->left = NULL;
    four4->right = NULL;

    five5->val = 4;
    five5->left = NULL;
    five5->right = NULL;


    int size;
    int* result = findMode(one1, &size);


    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}