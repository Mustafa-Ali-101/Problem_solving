#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool wordPattern(char* pattern, char* s) {
    // Varialbes
    int index = 0;
    int left = 0;
    int right = 0;

    // Loop over the words
    while (true)
    {
        // a new word
        if (s[right] == ' ' || s[right] == '\0') {
            // Extract the new word
            int wordIndex = 0;
            char* ithWord = malloc((right - left + 1) * sizeof(char));

            while (left < right) {
                ithWord[wordIndex] = s[left];
                left++;
                wordIndex++;
            }
            ithWord[wordIndex] = '\0';
            left++;

            // Print it
            printf(ithWord);
            printf("\n");
        }

        // End of string s
        if (s[right] == '\0') break;
        right++;
    }


    printf("=========> %d\n", pattern[0] - 97);
}



int main(void) {

    wordPattern("ala", "I am a software engineer");
    return 0;
}