#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition for a doubly linked list node
struct ListNode {
    int val;
    struct ListNode* prev;
    struct ListNode* next;
};

// Function to create a new binary tree node
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to convert BST to doubly linked list
void convertToDoublyLinkedList(struct TreeNode* root, struct ListNode** head, struct ListNode** prev) {
    if (!root) return;

    // Traverse the left subtree
    convertToDoublyLinkedList(root->left, head, prev);

    // Create a new doubly linked list node
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = root->val;
    newNode->prev = *prev;
    newNode->next = NULL;

    // Link the previous node with the current one
    if (*prev) {
        (*prev)->next = newNode;
    } else {
        // If this is the first node, set it as head
        *head = newNode;
    }
    
    // Update the previous pointer
    *prev = newNode;

    // Traverse the right subtree
    convertToDoublyLinkedList(root->right, head, prev);
}

// Wrapper function to initiate conversion
struct ListNode* bstToDoublyLinkedList(struct TreeNode* root) {
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;
    convertToDoublyLinkedList(root, &head, &prev);
    return head;
}

// Function to print the doubly linked list
void printDoublyLinkedList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Creating a sample BST
    struct TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(5);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);

    // Convert BST to doubly linked list
    struct ListNode* head = bstToDoublyLinkedList(root);

    // Print the doubly linked list
    printDoublyLinkedList(head);

    // Free memory (not shown here for brevity)

    return 0;
}

