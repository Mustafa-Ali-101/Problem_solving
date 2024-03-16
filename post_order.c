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

// Return the postorder traversal of an n-ary tree
int* postorder(Node* root, int* returnSize) {
    node* stack = makeStack(); // create a stack
    int available = 10; // initialize the capacity of the output array
    int index = 0; // initialize the index of the output array
    int* list = malloc(sizeof(int) * available); // allocate memory for the output array

    if (root == NULL) { // if the tree is empty
        *returnSize = 0; // set the return size to zero
        return list; // return the empty array
    }

    pushStack(&stack, root); // push the root node to the stack

    while (!isEmptyStack(stack)) // while the stack is not empty
    {
        Node* ithNode = popStack(&stack); // pop a node from the stack

        // check if the output array has enough space
        if (index == available) {
            available *= 2; // double the capacity
            list = realloc(list, available * sizeof(int)); // reallocate memory
        }
        // add the node value to the output array at the front
        list[index] = ithNode->val;
        index++;

        // if the node has children
        if (ithNode->numChildren > 0) {
            // push its children from left to right to the stack
            for(int i = 0; i < ithNode->numChildren; i++) {
                pushStack(&stack, ithNode->children[i]);
            }
        }
    }

    // reverse the output array to get the postorder traversal
    for (int i = 0; i < index / 2; i++) {
        int temp = list[i];
        list[i] = list[index - i - 1];
        list[index - i - 1] = temp;
    }

    // reallocate memory to fit the output size
    list = realloc(list, index * sizeof(int));

    // update the return size
    *returnSize = index;
    return list;
}

int main(void) {
    node* stack = makeStack();

    struct Node myNode;
    myNode.val = 4;
    myNode.numChildren = 0;
    myNode.children = NULL;

    pushStack(&stack, &myNode);

    printf("%d \n", popStack(&stack)->val);
    return 0;
}