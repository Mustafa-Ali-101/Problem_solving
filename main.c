#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"


bool binarySearch(int* list, int num) {
  int l = 0;
  int r = num - 1;

  while (l <= r) {
    int mid = (r + l) / 2;

    if (list [mid] == num) {
      return true;
    } else if (list[mid] < num) {
      l = mid + 1;
    } else {
      r = mid - 2;
    }
  }

  return false;
}
long main(void) {

  HashTable* t = createHashTable(14);



  for (int i = 0; i < 100; i++) {
    if (i % 2 == 0) insert(t, i);
  }

  printHashTable(t);

  return 0;
}