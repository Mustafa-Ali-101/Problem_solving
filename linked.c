#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp = head;
    int size = 0;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    size = ceil(size / 2);

    temp = head;

    for (int i = 0;i < size; i++) {
        temp = temp->next;
    }

    return temp;
}


int getDecimalValue(struct ListNode* head) {    int total = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        total = total * 2;
        total += temp->val;

        temp = temp->next;
    }

    return total;
}

int main(void) {

    struct ListNode* myList = malloc(sizeof(struct ListNode));
    struct ListNode* myList1 = malloc(sizeof(struct ListNode));
    struct ListNode* myList2 = malloc(sizeof(struct ListNode));
    struct ListNode* myList3 = malloc(sizeof(struct ListNode));

    myList->val = 1;
    myList->next = myList1;
    myList1->val = 0;
    myList1->next = myList2;
    myList2->val = 1;
    myList2->next = myList3;
    myList3->val = 0;
    myList3->next = NULL;

    printf("%d \n", getDecimalValue(myList));

    return 0;
}