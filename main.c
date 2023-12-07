#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "imp_list.h"
//#include "hash.h"

typedef struct treenode {
  int val;
  struct treenode* left;
  struct treenode* right;
} treenode;

node* two_sorted(node* list1, node* list2);
treenode* make_node(int n);
bool insert(treenode** root, int n);
bool search(treenode* root, int n);
void depth_first(treenode* root, int length);
void depth_recursive(treenode* root);
void breadth_first(treenode* root, int n);
int* inorderTraversal(treenode* root, int* returnSize);
bool isSymmetricEqual(treenode* root1, treenode* root2);
int sumTree(treenode* root);
int maxOfThree(int a, int b, int c);
int maxNode(treenode* root);
bool canSum(int target, int* list, int listLength);
void appendNewNode(node** head, int val);
node* reverseLinkedList (node* head);
bool isArrayPal(int* li, int length);
node* recFun(node* l1, node* l2, int over);


int main() {
  return 0;
}


node* two_sorted(node* list1, node* list2) {
  node* queue = new_node(0);
  node* temp1 = list1;
  node* temp2 = list2;
  while (temp1 != NULL || temp2 != NULL) {
    /* if one of them is null */
    if (temp1 == NULL) { 
      append(&queue, temp2->val);
      temp2 = temp2->next;
    } else if (temp2 == NULL) {
      append(&queue, temp1->val);
      temp1 = temp1->next;
    } else { // if none of them is null
      if (temp1->val > temp2->val) {
        append(&queue, temp2->val);
        temp2 = temp2->next; 
      } else if (temp1->val < temp2->val) {
        append(&queue, temp1->val);
        temp1 = temp1->next;        
      } else {
        append(&queue, temp2->val);
        append(&queue, temp1->val);
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
    }
  }

  return queue->next;
}

treenode* make_node(int n) {
  treenode* r = malloc(sizeof(treenode));
  r->left = NULL;
  r->right = NULL;
  r->val = n;

  return r;
}

bool insert(treenode** root, int n) {
  if ((*root) == NULL) {
    (*root) =  make_node(n);
    return true;
  } else if ((*root)->val == n) {
    return false;
  } else if ((*root)->val > n) {
    insert(&((*root)->left), n);
    return true;
  } else {
    insert(&((*root)->right), n);
    return true;   
  }

}

bool search(treenode* root, int n) {
  if (root == NULL) {
    return false;
  } else if(root->val == n) {
    return true;
  } else if(root->val > n) {
    return search(root->left, n);
  } else {
    return search(root->right, n);
  }
}

void depth_first(treenode* root, int length) {
  treenode* stack[length];
  int counter = 1;
  stack[counter] = root;
  while(counter > 0) {
    treenode* current = stack[counter];
    printf("%d\n", current->val);
    counter--;
    if (current->right != NULL) {
      counter++;
      stack[counter] = current->right;
    }
    if (current->left != NULL) {
      counter++;
      stack[counter] = current->left;
      //counter++;
    }
  }
}

void depth_recursive(treenode* root) {
  treenode* temp = root;
  if (temp != NULL) {
    printf("%d\n", temp->val);
    depth_recursive(temp->left);
    depth_recursive(temp->right);
  }
}

void breadth_first(treenode* root, int n) {
  treenode * queue[n];
  int counter = 0;
  int index = 0;
  queue[counter] = root;
  //counter++;
  while (counter >= index) {
    treenode* current = queue[index];
    index++;
    printf("%d\n", current->val);
    if (current->left != NULL) {
      counter++;
      queue[counter] = current->left;
    }
    if (current->right != NULL) {
      counter++;
      queue[counter] = current->right;
    }
  }
}

int* inorderTraversal(treenode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        //int* empty = NULL;
        return NULL;
    } else {
        int leftSize;
        int rightSize;

        // recursive calls to the subtrees
        int * left = inorderTraversal(root->left, &leftSize);
        int * right = inorderTraversal(root->right, &rightSize);

        // make the big list
        *returnSize = leftSize + rightSize + 1;
        int*  notEmpty = malloc(sizeof(int) /** (*returnSize)*/);


        // add the left subtree to the list
        int j = 0;
        for (; j < leftSize; j++) {
          notEmpty[j] = left[j];
        }


        // adding the root val to the list
        notEmpty[j] = root->val;
        j++;


        // add the right subtree to the list
        for (int i = 0; i < rightSize; i++) {
          notEmpty[i + j] = right[i];
        }


        free(left);
        free(right);
        return notEmpty;
    }
}

bool isSameTree(treenode* p, treenode* q) {
    if (p == NULL && q == NULL) {
      return true;
    } else if (p == NULL){
      return false;
    } else if (q == NULL) {
      return false;
    } else {
      return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

bool isSymmetricEqual(treenode* root1, treenode* root2) {
    if (root1 == NULL && root2 == NULL) {
      return true;
    } else if (root1 != NULL && root2 == NULL) {
      return false;
    } else if (root2 != NULL && root1 == NULL) {
      return false;
    } else {
      return root1->val == root2->val && isSymmetricEqual(root1->left, root2->right) && isSymmetricEqual(root1->right, root2->left);
    }
}

int sumTree(treenode* root) {
  if (root == NULL) {
    return 0;
  } else {
    return root->val + sumTree(root->left) + sumTree(root->right);
  }
}

int maxOfThree(int a, int b, int c) {
  if (a > b) {
    if (a > c) {
      return a;
    } else {
      return c;
    }
  } else {
    if (b > c) {
      return b;
    } else {
      return c;
    }
  }
}

int maxNode(treenode* root) {
  if (root == NULL) {
    return 0;
  } else {
    return maxOfThree(root->val, maxNode(root->left), maxNode(root->right));
  }
}

void merge(node* list1, node* list2,node* rr) {
    if (list1 == NULL) { rr->next = list2;}
    else if (list2 == NULL) { rr->next = list1;}
    else {
        node* NewNode = malloc(sizeof(node));
        if (list1->val >= list2->val) {
            NewNode->val = list1->val;
            merge(list1->next, list2, rr->next);
        } else {
            NewNode->val = list2->val;
            merge(list1, list2->next, rr->next);            
        }
    }
}

node* mergeTwoLists(node* list1, node* list2) {
    node* ReturnPointer = malloc(sizeof(node));
    merge(list1, list2, ReturnPointer);

    return ReturnPointer->next;
}

bool canSum(int target, int* list, int listLength) {
  if (target == 0) return true;
  if (target < 0) return false;

  for (int i = 0; i < listLength; i++) {
    if (canSum(target - list[i], list, listLength)) return true;
  }

  return false;
}

void appendNewNode(node** head, int val) {
    node* temp = *head;
    node* newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = NULL;
    

    if (temp == NULL) {
        *head = newNode;
        //return newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }   
}

node* reverseLinkedList (node* head) {
    if (head == NULL) {
        return NULL;
    } else {
        node* new = reverseLinkedList(head->next);
        appendNewNode(&new, head->val);
        return new;
    }
}

bool isArrayPal(int* li, int length) {
  int first = 0;
  int last = length - 1;
  while (last > first) {
    if (li[last] != li[first]) return false;
    last--;
    first++;
  }

  return true;
}

node* recFun(node* l1, node* l2, int over) {
  if (over == 0 && l1 == NULL && l2 == NULL) {
    return NULL;
  } else {
    node* newNode = malloc(sizeof(node));


    int digit = over;
    if (l1 != NULL) {digit += l1->val; l1 = l1->next;}
    if (l2 != NULL) {digit += l2->val; l2 = l2->next;}

    if (digit < 10) {
      newNode->val = digit;
      newNode->next = recFun(l1->next, l2->next, 0);
      return newNode;
    } else {
      newNode->val = digit - 10;
      newNode->next = recFun(l1->next, l2->next, 1);
      return newNode;
    }
  }
}

