#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    char s = letters[0];

    for (int i = 0; i < lettersSize; i++) {
        if (letters[i] > target) {
            return letters[i];
        } 
    }

    return s;
}


int main(void) {

    return 0;
}