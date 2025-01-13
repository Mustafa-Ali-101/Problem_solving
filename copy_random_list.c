#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a Node.
 */
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
	// Base Case
    if (head == NULL) return NULL;

    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* tweak = malloc(sizeof(struct Node));
    
    newNode->val = head->val;
    
    // Tweaking
    tweak->random = newNode;
    tweak->next = head->next;
    head->next = tweak;

    newNode->next = copyRandomList(head->next->next);

    newNode->random = head->random == NULL ? NULL : head->random->next->random;

    return newNode;
}