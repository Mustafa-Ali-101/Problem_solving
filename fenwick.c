#include <stdio.h>
#include <stdlib.h>

// Fenwick Tree (Binary Indexed Tree) structure
typedef struct {
    int *BIT;   // Array to store the tree
    int n;      // Size of the array
} FenwickTree;

// Function to initialize the Fenwick Tree
FenwickTree* createFenwickTree(int n) {
    FenwickTree* tree = (FenwickTree*)malloc(sizeof(FenwickTree));
    tree->BIT = (int*)calloc(n + 1, sizeof(int)); // Create an array of size n+1 (1-based indexing)
    tree->n = n;
    return tree;
}

// Function to perform Add(i, y): Add value y to the ith element
void add(FenwickTree* tree, int i, int y) {
    while (i <= tree->n) {
        tree->BIT[i] += y;
        i += (i & -i); // Move to the next index
    }
}

// Function to perform Partial-sum(i): Return the sum of the first i elements
int partialSum(FenwickTree* tree, int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree->BIT[i];
        i -= (i & -i); // Move to the previous index
    }
    return sum;
}

// Function to deallocate the Fenwick Tree
void freeFenwickTree(FenwickTree* tree) {
    free(tree->BIT);
    free(tree);
}

// Example usage
int main() {
    int n = 10; // Size of the array
    FenwickTree* tree = createFenwickTree(n);

    // Example operations:
    add(tree, 1, 5);  // Add 5 to the first element
    add(tree, 2, 3);  // Add 3 to the second element
    add(tree, 5, 7);  // Add 7 to the fifth element

    // Query the partial sums
    printf("Partial sum of first 5 elements: %d\n", partialSum(tree, 5));  // Output: 15
    printf("Partial sum of first 2 elements: %d\n", partialSum(tree, 2));  // Output: 8

    freeFenwickTree(tree); // Clean up
    return 0;
}
