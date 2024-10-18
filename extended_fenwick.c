#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;               
    int value;            
    int height;            
    int subtree_sum;       
    struct Node *left;     
    struct Node *right;    
} Node;

int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

int subtreeSum(Node* node) {
    return (node == NULL) ? 0 : node->subtree_sum;
}

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->height = 1;
    node->subtree_sum = value; 
    node->left = node->right = NULL;
    return node;
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    
    x->right = y;
    y->left = T2;
    
    
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    
    y->subtree_sum = y->value + subtreeSum(y->left) + subtreeSum(y->right);
    x->subtree_sum = x->value + subtreeSum(x->left) + subtreeSum(x->right);
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    
    x->subtree_sum = x->value + subtreeSum(x->left) + subtreeSum(x->right);
    y->subtree_sum = y->value + subtreeSum(y->left) + subtreeSum(y->right);
    
    return y;
}


int getBalance(Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

Node* insert(Node* node, int key, int value) {
    // Perform normal BST insertion
    if (node == NULL)
        return createNode(key, value);
    
    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else { // Key already exists, update the value
        node->value += value;
        node->subtree_sum += value; // Update the subtree sum
        return node;
    }
    
    // Update height and subtree sum
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    node->subtree_sum = node->value + subtreeSum(node->left) + subtreeSum(node->right);
    
    // Balance the tree
    int balance = getBalance(node);
    
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    // Perform standard BST delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }
            free(temp);
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            // Copy the inorder successor's data to this node
            root->key = temp->key;
            root->value = temp->value;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // Update height and subtree sum
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    root->subtree_sum = root->value + subtreeSum(root->left) + subtreeSum(root->right);

    // Balance the tree
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void add(Node* root, int key, int y) {
    if (root == NULL) return;

    if (key < root->key)
        add(root->left, key, y);
    else if (key > root->key)
        add(root->right, key, y);
    else { // Key found
        root->value += y;
        root->subtree_sum += y; // Update subtree sum
    }

    // Update height and subtree sum
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));
    root->subtree_sum = root->value + subtreeSum(root->left) + subtreeSum(root->right);
}

int partialSum(Node* node, int k) {
    if (node == NULL)
        return 0;

    if (node->key >= k)
        return partialSum(node->left, k); // Only check left subtree

    return node->value + subtreeSum(node->left) + partialSum(node->right, k); // Add current node value and left subtree sum
}

typedef struct {
    Node* root;
} AVLTree;

AVLTree* createAVLTree() {
    AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
    tree->root = NULL;
    return tree;
}


int main() {
    AVLTree* tree = createAVLTree();

    // Insert elements
    tree->root = insert(tree->root, 1, 10);
    tree->root = insert(tree->root, 2, 20);
    tree->root = insert(tree->root, 3, 30);

    // Update value
    add(tree->root, 2, 5); // Add 5 to the value of key 2

    // Get partial sum
    int sum = partialSum(tree->root, 3); // Sum of keys < 3
    printf("Partial Sum: %d\n", sum); // Output: 15

    // Delete an element
    tree->root = deleteNode(tree->root, 2); // Delete key 2

    // Free memory
    // Implement a function to free the tree nodes
    return 0;
}
