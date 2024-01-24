#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "helper.h"


char* reverseVowels(char* s);

int main()
{
  char myString[] = {'n', 'e', 'd','e', 'a', 'r', '\0'};

  char* reversed = reverseVowels(myString);


  printf(reversed);
  //printf("%d \n", ('a' == a));
  return 0;
}


char* reverseVowels(char* s) {
  int start = 0;
  int end = 0;

  for(int i = 0; s[i] != '\0'; i++) {
    end++;
  }

  // make the array that will be modified
  char* arr = malloc(sizeof(char) * (end + 1));
  arr[end + 1] = '\0';
  for (int i = 0; i <= end; i++) {
    arr[i] = s[i];
  }

  while(end > start) {
    if (isVowel(s[start]) && isVowel(s[end])) {
      arr[start] = s[end];
      arr[end] = s[start];
      start++;
      end--;
    } else if (isVowel(s[start])){
      end--;
    } else if (isVowel(s[end])){
      start++;
    } else {
      start++;
      end--;
    }
  }


  return arr;    
}
