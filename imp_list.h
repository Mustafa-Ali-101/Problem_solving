#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct list_node {
    int value;
    struct list_node * next;
} node;

node * make_list(int * a, int l) {
    node * head;
    head = malloc(sizeof(node));
    int i;
    node * temp = head;
    for (i = 0; i < l - 1; i++) {
        temp->value = a[i];
        temp->next = malloc(sizeof(node));
        temp = temp->next;
    }
    temp->value = a[i];
    temp->next = NULL;
    return head;
}

node first(node* head) {
    return *head;
}

node * but_first(node * head) {
    return head->next;
}

void print_list (node * head) {
    node * temp = head;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

/* function to make a new node */
node* new_node(int v) {
    /* malloc a new node */
    node* n = malloc(sizeof(node));

    /* set the value and next */
    n->value = v;
    n->next = NULL;

    /* return the new node */
    return n;
}


/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list. */
void push(node ** head, int new) {
    /* allocate node */
    node * tmp = malloc(sizeof(node));

    /* put in the data  */
    tmp->value = new;

    /* Make next of new node as head */
    tmp->next = *head;

    /* move the head to point to the new node */
    *head = tmp;
}


/* Given a node prev_node, insert a new node after the given prev_node */
void insert_after(node* prev_node, int new) {
    /* check if the given prev_node is NULL */
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* allocate new node */
    node* tmp = malloc(sizeof(node));

    /* put in the data */
    tmp->value = new;

    /* Make next of new node as next of prev_node */
    tmp->next = prev_node->next;

    /* move the next of prev_node as new_node */
    prev_node->next = tmp;
}


/* Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end */
void append(node** head, int new) {
    /* allocate node */
    node* new_node = malloc(sizeof(node));

    /* temperary pointer to node */
    node* tmp = *head;

    /* put in the data */
    new_node->value = new;

    /* This new node is going to be the last node, so make next of it as NULL */
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new* node as head */
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    /* Else traverse till the last node */
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    
    
    /* Change the next of last node */
    tmp->next = new_node;
}


/* Given a reference (pointer ot pointer) to the head of a list, delete the first node */
void pop(node** phead) {
    // Check if head is NULL
    if (*phead == NULL) {
        printf("The list is empty\n");
        return;
    }

    /* make a temporary pointer to node (the first node)*/
    node* to_free = *phead;

    /* change the head pointer to the next node */
    *phead = (*phead)->next;

    /* free the temporary pointer to node */
    free(to_free);
}


/* Given a head of a list, delete the last node in the list */ 
void delete(node** head) {
    // Check if head is NULL
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }


    // Initialize two pointers for traversal and finding the previous node of the last node
    node* temp = *head;
    node* prev = NULL;

    

    /* increase tmp until it points to (the one before last node), then change the before last to point to NULL */
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }


    // Check if prev is NULL
    if (prev == NULL) {
        // Make head point to NULL
        *head = NULL;
    } else {
        // Make prev's next point to NULL
        prev->next = NULL;
    }

    free(temp);
}


/* Given a pointer to a node delete the node after it */
void delete_after(node* p_node) {
    /* a to_free node pointer */
    node* to_free = p_node->next;
    
    /* change the following pointer to the one after it */
    p_node->next = (p_node->next) -> next;

    free(to_free);
}


// A function that deletes a node at a specific position of a linked list
void delete_at_position(node** head, int pos)
{
    // Check if pos is valid
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    // Check if pos is 1
    if (pos == 1) {
        // Call delete_at_beginning function with head as an argument
        pop(head);
        return;
    }


    // Initialize two pointers for traversal and finding the previous node of the position
    node *temp = *head;
    node *prev = NULL;

    // Initialize a variable for counting the nodes
    int count = 1;

    // Loop until temp is NULL or count is equal to pos
    while (temp != NULL && count < pos)
    {
        // Assign temp to prev
        prev = temp;
        // Move temp to the next node
        temp = temp->next;
        // Increment count by 1
        count++;
    }

    // delete at the position if found
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}


node find(node* head, int v) {
    /* a pointer to the beginning of the list */
    node* temp = head;

    /* retutn node */
    node return_node;
    bool found = false;

    /* loop through the list to the specified node or the null pointer*/
    while (temp != NULL) {
        if (temp->value == v) {
            found = true;
            return_node = *temp;
            return return_node;
        }
        temp = temp->next;
    }

    /* if the specified node not found */
    return_node.value = -1;
    return_node.next = NULL;
    return return_node;

}

/* return the length of a linked list */
int length_of_list(node* head) {
    node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/* the length of a linked list recursively */
int length_of_list_r (node* head) {
    if (head == NULL) {
        return 0;
    } else {
        return 1 + length_of_list_r(head->next);
    }
}

/* detect if there is a loop in the linked list */
bool is_loop(node* head) {
    node* temp = head;
    node* iter;
    int until = 0;
    while (temp != NULL) {
        until++;
        temp = temp->next;
        iter = head;
        for (int i = 0; i < until; i++) {
            if(iter == temp) {
                return true;
            } else {
                iter = iter->next;
            }
        }
    }
    return false;
}


// A function that detects if there is a loop in a linked list using the tortoise and hare algorithm
bool tortoise_and_hare(node* head) {
    node* tortoise = head;
    node* hare = head->next;

    while(hare->next != NULL && hare->next->next != NULL) {
        if(hare == tortoise) {
            return true;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return false;
}

// Returns count of nodes present in loop.
int count_nodes(node* n)
{
    int res = 1;
    node* temp = n;
    while (temp->next != n) {
        res++;
        temp = temp->next;
    }
    return res;
}

/* This function detects and counts loop nodes in the list. If loop is not there then returns 0 */
int count_nodes_in_loop(node* list)
{
    node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point
           then there is a loop */
        if (slow_p == fast_p)
            return count_nodes(slow_p);
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}


/* Given a linked list, the job is to return a pointer to a reversed version of it */
node* reverse(node* head) {
    /* create a new pointer to node from the first value of list */
    node* h = new_node(head->value);

    /* loop from the second value to the end adding a new node in the front at each step */
    node* temp = head->next;
    while (temp != NULL) {
        push(&h, temp->value);
        temp = temp->next;
    }

    /* return the pointer (it is modified by the push function) */
    return h;
}

bool equal_lists(node* list1, node* list2) {
    /* loop through the first list and see if its elements equal the second's */
    while(list1 != NULL && list2 != NULL) {
        if (list1->value != list2->value) return false;
        list1 = list1->next;
        list2 = list2->next;
    }

    /* now we terminated, if the second is equal to the first then true */
    if (list2 == list1) return true;

    /* Else false (this means the second is longer than the first or the other way around)*/
    return false;
}

bool is_palindrome(node* l) {
    /* reverse list */
    node* m = reverse(l);
    /* see if list is equal to the mirror image */
    return equal_lists(l, m);
}

/* returns a version of the sorted list without duplicates */
node* remove_duplicates(node* head) {
    /* integer variable to hold the current value */
    int current = head->value;

    /* make a new list */
    node* result = malloc(sizeof(node));
    result->value = head->value;
    result->next = NULL;

    /* loop through the list */
    node* temp = head->next;
    while (temp != NULL) {
        /* if the value is the same as current */
        if(temp->value == current) {
            temp = temp->next; // continue
        } else { // else : there is a new value 
            append(&result, temp->value); // add it and make it the current
            current = temp->value;
            temp = temp->next;
        }
    }
    return result;
}