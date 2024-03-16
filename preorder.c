#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>



// Define the Node type
typedef struct Node {
    int val;
    int numChildren;
    struct Node** children;
} Node;

// Define the list node type for the stack
typedef struct list_node {
    Node* val;
    struct list_node * next;
} node;

// Create a new node with a given value
node* newNode(Node* val) {
    node* result = (node*) malloc(sizeof(node));
    result->val = val;
    result->next = NULL;
    return result;
}

// Create an empty stack
node* makeStack() {
    node* result = NULL;
    return result;
}

// Push a node to the stack
void pushStack(node** head, Node* val) {
    node* result = newNode(val); // create a new node
    result->next = (*head); // link it to the previous head
    (*head) = result; // update the head pointer
}

// Check if the stack is empty
bool isEmptyStack(node* head) {
  return head == NULL;
}

// Pop a node from the stack
Node* popStack(node** stack) {
    if (isEmptyStack(*stack)) {
        printf("Couldn't Pop An Empty Stack");
        return NULL;
    } else {
        Node* poped = (*stack)->val; // get the value of the top node
        node* temp = *stack; // store the top node
        (*stack) = (*stack)->next; // update the stack pointer
        free(temp); // free the memory of the top node
        return poped;
    }
}




////////////
int* preorder(struct Node* root, int* returnSize) {
    node* stack = makeStack();
    int capacity = 10;
    int index = 0;
    int* list = malloc(sizeof(int) * capacity);


    pushStack(&stack, root);

    while (!isEmptyStack(stack)) {
        Node* ithNode = popStack(&stack);

        if (index == capacity) {
            capacity *= 2;
            list = realloc(list, sizeof(int) * capacity);
        }

        list[index] = ithNode->val;
        index++;

        // if the node has children
        if (ithNode->numChildren > 0) {
            // push its children from right to left to the stack
            for(int i = ithNode->numChildren - 1; i >= 0; i--) {
                pushStack(&stack, ithNode->children[i]);
            }
        }

        free(ithNode);
    }

    // Realloc if Possible
    list = realloc(list , index * sizeof(int));
    *returnSize = index;
    return list;
}