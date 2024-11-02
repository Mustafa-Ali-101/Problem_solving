#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareChars(const void *a, const void *b) {
    return *(const char *)a - *(const char *)b;
}

bool isAnagram(char* s, char* t) {
    int sLength = strlen(s);
    int tLength = strlen(t);

    // If the lengths of the string don't match
    if (sLength != tLength) {
        return false;
    }

    // Sort both strings
    qsort(s, sLength, sizeof(char), compareChars);
    qsort(t, tLength, sizeof(char), compareChars);

    // Match both strings
    for (int i = 0; i < sLength; i++) {
        if (s[i] != t[i]) return false;
    }

    return true;
}

int main(void) {

    return 0;
}