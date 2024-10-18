#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to determine if ransomNote can be constructed from magazine
bool canConstruct(char *ransomNote, char *magazine) {
    int letterCount[26] = {0};  // Array to store the frequency of each letter in the magazine

    // Count the frequency of each letter in the magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        letterCount[magazine[i] - 'a']++;
    }

    // Check if there are enough letters in the magazine to form the ransom note
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (letterCount[ransomNote[i] - 'a'] == 0) {
            return false;  // Not enough letters
        }
        letterCount[ransomNote[i] - 'a']--;  // Use one letter from the magazine
    }

    return true;
}

int main() {
    // Test cases
    char ransomNote1[] = "a";
    char magazine1[] = "b";
    char ransomNote2[] = "aa";
    char magazine2[] = "ab";
    char ransomNote3[] = "aa";
    char magazine3[] = "aab";

    printf("Test 1: %s\n", canConstruct(ransomNote1, magazine1) ? "true" : "false");  // Expected output: false
    printf("Test 2: %s\n", canConstruct(ransomNote2, magazine2) ? "true" : "false");  // Expected output: false
    printf("Test 3: %s\n", canConstruct(ransomNote3, magazine3) ? "true" : "false");  // Expected output: true

    return 0;
}
