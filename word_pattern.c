#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define ALPHABET_SIZE 26

int wordPattern(char *pattern, char *s) {
    char *wordMap[ALPHABET_SIZE] = {0}; // Maps characters to words
    char **words = malloc(1000 * sizeof(char *)); // Dynamic allocation for words
    int wordCount = 0;

    // Split the string `s` into words
    char *token = strtok(s, " ");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    // If the number of words does not match the length of the pattern, return 0
    if (wordCount != strlen(pattern)) {
        free(words); // Free allocated memory
        return 0;
    }

    for (int i = 0; i < strlen(pattern); i++) {
        int index = pattern[i] - 'a';

        // Check if the mapping exists
        if (wordMap[index] == NULL) {
            // If no mapping exists, create one
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                // Check if the word is already assigned to another character
                if (wordMap[j] != NULL && strcmp(wordMap[j], words[i]) == 0) {
                    free(words); // Free allocated memory
                    return 0;  // Conflict in mapping
                }
            }
            wordMap[index] = words[i];
        } else {
            // If a mapping exists, check if it matches the current word
            if (strcmp(wordMap[index], words[i]) != 0) {
                free(words); // Free allocated memory
                return 0;  // Mapping mismatch
            }
        }
    }

    free(words); // Free allocated memory
    return 1;  // Pattern matches
}

int main() {
    char pattern[] = "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccdd";
    char s[] = "s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s t t";
    
    if (wordPattern(pattern, s)) {
        printf("The pattern matches the string.\n");
    } else {
        printf("The pattern does not match the string.\n");
    }

    return 0;
}
