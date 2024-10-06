#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"

int lengthOfLongestSubstring(char* s) {
    HashTable* table = createHashTable(5);
    
    int longest = 0;

    int start = 0;
    int end = 0;

    while (s[end] != '\0')
    {
        // Test for this specific char in string
        if (s[end] == search(table, s[end])) {
            // Set Length
            int length = end - start;
            longest = length > longest ? length : longest;

            // Remove from Table
            delete(table, s[start]);

            // Increment Start
            start++;
        } else {
            // Add to Table
            insert(table, s[end]);


            // Increment End
            end++;
        }
    }
    

    return longest;
}

int main(void) {
    int value = lengthOfLongestSubstring(" ");

    printf(" \n %d \n", value);

    return 0;
}