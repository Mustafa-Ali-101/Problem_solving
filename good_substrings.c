#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int countGoodSubstrings(char* s) {
    if (s[0] == '\0' || s[1] == '\0') return 0;
    
    int count = 0;
    for (int i = 2; s[i] != '\0'; i++)
    {
        if (s[i] != s[i - 1]&& s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
            count++;
        }
    }

    return count;
}

int main(void) {


    return 0;
}