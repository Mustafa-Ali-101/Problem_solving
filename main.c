#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "imp_list.h"
#include "hash.h"

node* two_sorted(node* list1, node* list2);
char * addBinary(char * a, char * b);





int main() {

  char * x = "100";
  char * y = "110010";

  printf("%s\n", addBinary(x, y));
  return 0;
}


node* two_sorted(node* list1, node* list2) {
  node* queue = new_node(0);
  node* temp1 = list1;
  node* temp2 = list2;
  while (temp1 != NULL || temp2 != NULL) {
    /* if one of them is null */
    if (temp1 == NULL) { 
      append(&queue, temp2->value);
      temp2 = temp2->next;
    } else if (temp2 == NULL) {
      append(&queue, temp1->value);
      temp1 = temp1->next;
    } else { // if none of them is null
      if (temp1->value > temp2->value) {
        append(&queue, temp2->value);
        temp2 = temp2->next; 
      } else if (temp1->value < temp2->value) {
        append(&queue, temp1->value);
        temp1 = temp1->next;        
      } else {
        append(&queue, temp2->value);
        append(&queue, temp1->value);
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
    }
  }

  return queue->next;
}


char * addBinary(char * a, char * b){
    int length_a = 1;
    int length_b = 1;
    int quot = 0;

    int m;
    for (int i = 0; a[i] != '\0'; i++) {
        length_a++;
    }

    for (int i = 0; b[i] != '\0'; i++) {
        length_b++;
    }

    if (length_a >= length_b) {
        m = length_a + 1;
    } else {
        m = length_b + 1;
    }

    char* result = malloc(sizeof(char) * m);

    result[m - 1] = '\0';


    for (int i = 0; i < m - 1; i++) {
        if (i <= (length_a - 2) && i <= (length_b - 2)) {

            // setting the index in result
            if (( (int)a[(length_a - 2) - i] + (int)b[(length_b - 2) - i] + quot ) % 2 == 0) {
                result[m - i - 2] = '0';
            } else {
                result[m - i - 2] = '1';

            }

            // /* setting the quot */
            if (( (int)a[(length_a - 2) - i] + (int)b[(length_b - 2) - i] + quot ) < 98) {
              quot = 0;
            } else {
              quot = 1;
            }

        } else if (i > (length_a - 2) && i <= (length_b - 2)) {
            // setting the index in result
            if (( (int)b[(length_b - 2) - i] + quot ) % 2 == 0) {
                result[m - i - 2] = '0';
                quot = 1;
            } else {
                result[m - i - 2] = '1';
                quot = 0;
            }

            // setting the quotient
            if (( (int)b[(length_b - 2) - i] + quot ) == 49) quot = 0;


        } else if (i <= (length_a - 2) && i > (length_b - 2)) {
            // setting the index in result
            if (( (int)a[(length_a - 2) - i] + quot ) % 2 == 0) {
                result[m - i - 2] = '0';
                quot = 1;
            } else {
                result[m - i - 2] = '1';
                quot = 0;
            }

            // setting the quotient
            if (( (int)b[(length_b - 2) - i] + quot ) == 49) quot = 0;

        } else {
            result[m - i - 2] = (char)(quot + 48);
            quot = 0;
        }
    }
  if (result[0] == '0') {
    return result + 1;
  } else {
    return result;
  }
}