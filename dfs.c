#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void addPaths(struct TreeNode* root, char** solution, int* solIndex, char* path) {
    if (root == NULL) {
        return ;
    } 
    
    // convert the node to string
    // and add it to the buffer
    char buffer[12];
    sprintf(buffer, "%d", root->val);

    // add the string(node) to path
    strcat(path, buffer);

    // if node is the last
    if (root->left == NULL && root->right == NULL) {
        // allocate memory for path in solution
        solution[(*solIndex)] = malloc(strlen(path) + 1);
        // copy the path to the solution set
        strcpy(solution[(*solIndex)], path);
        (*solIndex)++;

        return;
    }

    // not last node
    // add the arrow
    strcat(path, "->");

    // after the call to the left
    // this is helpful for that
    int len = strlen(path);
    // call the left node
    addPaths(root->left, solution, solIndex, path);
    // return the path as it was
    path[len] = '\0';
    // call the right node
    addPaths(root->right, solution, solIndex, path);

    return;
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** result = malloc(sizeof(char*) * 1000);
    char* pathBuffer = malloc(1000);
    pathBuffer[0] = '\0';

    *returnSize = 0;



    addPaths(root, result, returnSize, pathBuffer);

    return result;
}

void sumRec(struct TreeNode* root, int *sum, bool isLeftChild) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL && isLeftChild) {
        (*sum) += root->val;
        return;
    }
    
    sumRec(root->left, sum, true);
    sumRec(root->right, sum, false);
    return;
}

// Sum of Left Leaves
int sumOfLeftLeaves(struct TreeNode* root) {
    int result = 0;

    // call Recursive
    sumRec(root, &result, false);

    return result;
}




int main (void) {
    struct TreeNode* myTreeOne = malloc(sizeof(struct TreeNode));
    struct TreeNode* myTreeTwo = malloc(sizeof(struct TreeNode));
    struct TreeNode* myTreeThree = malloc(sizeof(struct TreeNode));
    struct TreeNode* myTreeFour = malloc(sizeof(struct TreeNode));
    struct TreeNode* myTreeFive = malloc(sizeof(struct TreeNode));

    myTreeOne->val = 1;
    myTreeOne->left = myTreeTwo;
    myTreeOne->right = myTreeFive;

    myTreeTwo->val = 2;
    myTreeTwo->left = myTreeThree;
    myTreeTwo->right = myTreeFour;

    myTreeThree->val = 3;
    myTreeThree->left = NULL;
    myTreeThree->right = NULL;

    myTreeFour->val = 4;
    myTreeFour->left = NULL;
    myTreeFour->right = NULL;

    myTreeFive->val = 5;
    myTreeFive->left = NULL;
    myTreeFive->right = NULL;


    
}