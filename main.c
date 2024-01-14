#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "imp_list.h"
#include "hash_imp.h"

typedef struct treenode
{
  int val;
  struct treenode
      *left;
  struct treenode
      *right;
} treenode;

typedef struct integerNode {
  int value;
  struct integerNode* next;
} intNode;

int *getRowRecursive(int rowIndex, int *returnSize);
int *getRow(int rowIndex, int *returnSize);
bool isPalindrome(char *s);
bool isAlphaNum(char c);
char lower(char big);
int *preorderTraversal(treenode *root, int *returnSize);
char *convertToTitle(int columnNumber);
int titleToNumber(char* columnTitle);
intNode** makeHashTable(int size);
intNode* makeInt (int x);
void addToHashTable(intNode** h,int i, int len);
bool isInTable(int x, intNode** h,int len);
bool containsDuplicate(int* nums, int numsSize);
void moveZeroes(int* nums, int numsSize);


int main()
{
  int nums[] = {1, 0, 0, -4, 5, 6, 7, 8, 9};

  moveZeroes(nums, 9);
  

  for (int i = 0; i < 9; i++) {
    printf("%d\n", nums[i]);
  }
  return 0;
}

// I should Use Memoization because tha Algorithm is Very Slow
int *getRowRecursive(int rowIndex, int *returnSize)
{
  if (rowIndex == 0)
  {
    *returnSize = 1;
    int *returnedArray = malloc(sizeof(int));
    returnedArray[0] = 1;
    return returnedArray;
  }
  else
  {
    int theSize;
    *returnSize = rowIndex + 1;
    int *returnedArray = malloc((rowIndex + 1) * sizeof(int));
    returnedArray[0] = 1;
    returnedArray[rowIndex] = 1;
    for (int i = 1; i < rowIndex; i++)
    {
      returnedArray[i] = getRowRecursive(rowIndex - 1, &theSize)[i - 1] + getRowRecursive(rowIndex - 1, &theSize)[i];
    }

    return returnedArray;
  }
}

int *getRow(int rowIndex, int *returnSize)
{
  int index = rowIndex + 1;
  int **arrayOfArrays = malloc(index * sizeof(int *));

  // set the first array which is the base case
  arrayOfArrays[0] = malloc(sizeof(int));
  arrayOfArrays[0][0] = 1;

  // looping over the arrayOfArrays to set the inner arrays
  for (int i = 1; i < index; i++)
  {
    arrayOfArrays[i] = malloc((i + 1) * sizeof(int));

    // set the first and last items in the inner array
    arrayOfArrays[i][0] = 1;
    arrayOfArrays[i][i] = 1;

    // looping over the inner array
    for (int j = 1; j < i; j++)
    {
      arrayOfArrays[i][j] = arrayOfArrays[i - 1][j - 1] + arrayOfArrays[i - 1][j];
    }
  }

  *returnSize = index;
  return arrayOfArrays[rowIndex];
}

bool isAlphaNum(char c)
{
  return (((int)c >= 65 && (int)c <= 90) || ((int)c >= 97 && (int)c <= 122) || ((int)c >= 48 && (int)c <= 57));
}

char lower(char big)
{
  int ascii = (int)big;
  if (ascii >= 65 && ascii <= 90)
  {
    ascii += 32;
    return (char)ascii;
  }
  else
  {
    return big;
  }
}

bool isPalindrome(char *s)
{
  // First we have to know the length of the string
  int len = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    len++;
  }

  // Then we make two integers one at the begging and one at the end
  int start = 0;
  int end = len - 1;

  // All the work in here
  while (start != end && end > start)
  {
    if (!isAlphaNum(s[start]))
    {
      start++;
      continue;
    }
    else if (!isAlphaNum(s[end]))
    {
      end--;
      continue;
    }
    else
    {
      if (lower(s[start]) != lower(s[end]))
        return false;
      start++;
      end--;
    }
  }
  return true;
}

bool hasCycle(node *head)
{
  if (head == NULL)
    return false;

  node *turtle = head;
  node *tale = head;

  while (tale->next != NULL && tale->next->next != NULL)
  {
    tale = tale->next->next;
    turtle = turtle->next;

    if (tale == turtle)
      return true;
  }

  return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(treenode *root, int *returnSize)
{
  if (root == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
  else
  {
    int left;
    int right;
    int *leftArray = preorderTraversal(root->left, &left);
    int *rightArray = preorderTraversal(root->right, &right);

    *returnSize = left + right + 1;
    int *returnedArray = malloc(sizeof(int) * (*returnSize));

    returnedArray[0] = root->val;

    for (int i = 0; i < left; i++)
    {
      returnedArray[i + 1] = leftArray[i];
    }

    for (int i = 0; i < right; i++)
    {
      returnedArray[left + i] = rightArray[i];
    }

    return returnedArray;
  }
}

int *postorderTraversal(treenode *root, int *returnSize)
{
  if (root == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
  else
  {
    int left;
    int right;
    int sum;
    int *leftArray = postorderTraversal(root->left, &left);
    int *rightArray = postorderTraversal(root->right, &right);

    sum = left + right + 1;
    *returnSize = sum;
    int *returnedArray = malloc(sizeof(int) * (sum));

    returnedArray[sum - 1] = root->val;

    for (int i = 0; i < left; i++)
    {
      returnedArray[i] = leftArray[i];
    }

    for (int i = 0; i < right; i++)
    {
      returnedArray[left + i] = rightArray[i];
    }

    free(leftArray);
    free(rightArray);
    return returnedArray;
  }
}

node *getIntersectionNode(node *headA, node *headB)
{
  node *tempA = headA;
  node *tempB = headB;

  while (tempA != NULL)
  {
    while (tempB != NULL)
    {
      if (tempA == tempB)
      {
        return tempA->val;
      }
      tempB = tempB->next;
    }
    tempA = tempA->next;
  }

  return NULL;
}

char* convertToTitle(int columnNumber) {
  // allocate the alpha array and make it all null
  char* returned = NULL;


  // loop to convert the number to letters
  int len = 0;
  while(columnNumber > 0) {
    // remainder of the number divided by 26
    int alpha = (columnNumber - 1) % 26;


    // quotient of the number divided by 26
    columnNumber = (columnNumber - 1) / 26;


    // allocate one more space for the output array
    returned = realloc(returned, (len + 1) * sizeof(char));

    // assign the letter to the output array
    returned[len] = 'A' + alpha;

    len++;
  }


  // reverse the output array
  for(int i = 0; i < len / 2; i++) {
    char temp = returned[i];
    returned[i] = returned[len - i - 1];
    returned[len - i - 1] = temp;
  }

  // this is to add a null terminator to the output array
  returned = realloc(returned, sizeof(char) * (len + 1));
  returned[len] = '\0';
  return returned;
}

int titleToNumber(char* columnTitle) {
    int len = 0;
    int total = 0;

    // set length of the string given
    for(int i = 0; columnTitle[i] != '\0'; i++) {
      len++;
    }

    // caluculate the total number
    for(int i = len - 1; i >= 0; i--) {
      total = total + (((int) columnTitle[i]) - 64) * pow(26, (len - 1) - i);
    }

    return total;
}


/* return a pointer to the hash table of pointers to intNodes */
intNode** makeHashTable(int size) {

    intNode** h =(intNode**) malloc(size * sizeof(intNode*));

    /* initializing the hash table */
    for (int i = 0; i < size; i++) {
        h[i] = NULL;
    }
    return h;
}

intNode* makeInt (int x) {
  intNode* result = malloc(sizeof(intNode));
  result->value = x;
  result->next = NULL;
  return result;
}

void addToHashTable(intNode** h,int i, int len) {
  intNode* iNode = makeInt(i);

  int index = abs((iNode->value)) % len;
  
  //intNode* temp = p;
  iNode->next = h[index];
  h[index] = iNode;
}

bool isInTable(int x, intNode** h,int len) {
  int index = abs(x) % len;
  intNode* temp = h[index];

  while(temp != NULL) {
    if (temp->value == x) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}


bool containsDuplicate(int* nums, int numsSize) {
  int tableLength = numsSize;
  intNode** table = makeHashTable(tableLength);

  for (int i = 0; i < numsSize; i++) {
    if (isInTable(nums[i],table, tableLength)) {
      return true;
    } else {
      addToHashTable(table, nums[i], tableLength);
    }
  }

  return false;
}

void moveZeroes(int* nums, int numsSize) {
  int leftPointer = numsSize;
  int rightPointer = numsSize;


  // setting the left and right
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == 0) {
      leftPointer = i;
      rightPointer = i + 1;
      break;
    }
  }

  for (rightPointer; rightPointer < numsSize; rightPointer++) {
    if (nums[rightPointer]) {
      nums[leftPointer] = nums[rightPointer];
      nums[rightPointer] = 0;
      leftPointer++;
    }
  }
}