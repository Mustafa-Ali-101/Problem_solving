#include <malloc.h>

// make the given char lower case
char toLower(char c) {
  if (c >= 65 && c <= 90) {
    return c + 32;
  } else {
    return c;
  }
}

// if a given char vowel
bool isVowel(char c) {
  char toLowerC = toLower(c);
  return 
  ( toLowerC == 'a' ||
  toLowerC == 'e' ||
  toLowerC == 'i' ||
  toLowerC == 'o' ||
  toLowerC == 'u' );
}

// return the sum of the digits in some number
int sumOfDigits(int number) {
  int sum = 0;
  while (number != 0) {
    sum += number % 10;
    number = number / 10;
  }

  return sum;
}

// Comparator function for integers qsort
int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

// compute the Average of an array
double average(int* nums, int numsSize) {
  double avg = 0;
  for (int i = 0; i < numsSize; i++) {
    avg += nums[i];
  }

  return avg / numsSize;
}

// given height and width => computer area
int area(int h, int w) {
    return h * w;
}

// minimum of two values
int minimum(int x, int y) {
    if (x < y) return x;
    return y;
}

// used by qsort as a compare function
int cmpfunc(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}