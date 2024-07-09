#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    int index;
    struct Node* next;
} Node;

typedef struct {
    int size;
    Node** hashMap;
    int allocated;
    int listIndex;
    int* list;
} RandomizedSet;

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* set = (RandomizedSet*) malloc(sizeof(RandomizedSet));

    // Initialize variables
    set->size = 10007;  // A prime number for better hash distribution
    set->listIndex = 0;
    set->allocated = 16;
    set->hashMap = (Node**) malloc(sizeof(Node*) * set->size);
    set->list = (int*) malloc(sizeof(int) * set->allocated);

    // Initialize all entries to NULL
    for (int i = 0; i < set->size; i++) {
        set->hashMap[i] = NULL;
    }

    return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int index = abs(val) % obj->size;

    // Check if the value already exists
    Node* temp = obj->hashMap[index];
    while (temp != NULL) {
        if (temp->val == val) return false;
        temp = temp->next;
    }

    // Reallocate memory if needed
    if (obj->listIndex == obj->allocated) {
        obj->allocated *= 2;
        obj->list = (int*) realloc(obj->list, sizeof(int) * obj->allocated);
    }

    // Add value to list
    obj->list[obj->listIndex] = val;

    // Create a new node
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->index = obj->listIndex;
    newNode->next = obj->hashMap[index];

    // Insert new node at the head of the linked list
    obj->hashMap[index] = newNode;

    obj->listIndex++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    int index = abs(val) % obj->size;

    Node* temp = obj->hashMap[index];
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->val == val) {
            // Remove from list
            int lastIndex = obj->listIndex - 1;
            int lastVal = obj->list[lastIndex];
            obj->list[temp->index] = lastVal;

            // Update the index of the moved element
            Node* lastNode = obj->hashMap[abs(lastVal) % obj->size];
            while (lastNode != NULL) {
                if (lastNode->val == lastVal) {
                    lastNode->index = temp->index;
                    break;
                }
                lastNode = lastNode->next;
            }

            obj->listIndex--;

            // Remove from hash map
            if (prev == NULL) {
                obj->hashMap[index] = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            return true;
        }
        prev = temp;
        temp = temp->next;
    }

    return false;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int randomIndex = rand() % obj->listIndex;
    return obj->list[randomIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->list);

    for (int i = 0; i < obj->size; i++) {
        Node* entry = obj->hashMap[i];
        while (entry != NULL) {
            Node* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }

    free(obj->hashMap);
    free(obj);
}


int main(void) {

    RandomizedSet* mySet = randomizedSetCreate(); 

    randomizedSetInsert(mySet, 1);
    randomizedSetInsert(mySet, -2);
    randomizedSetInsert(mySet, -3);
    randomizedSetInsert(mySet, 4);
    randomizedSetInsert(mySet, 5);

    randomizedSetRemove(mySet, 3);

    randomizedSetFree(mySet);

    return 0;
}
