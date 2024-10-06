#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;     
    struct TreeNode *right;
};

// Recursive function
int sumOfNodes(struct TreeNode* root, int* tilt) {
    // Base Case
    if (root == NULL) {
        // Don't set the tilt
        return 0;
    }


    // Recursive Case
    int left = sumOfNodes(root->left, tilt);
    int right = sumOfNodes(root->right, tilt);

    int absolute = abs(left - right);

    // Set the tilt if possible
    *tilt = (*tilt) > absolute? (*tilt) : absolute;

    return left + right;
}

int findTilt(struct TreeNode* root) {
    int tilt = 0;

    // Call the recursive function
    sumOfNodes(root, &tilt);

    return tilt;
}