#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to reverse a section of the string
void reverse(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse words in the string
char* reverseWords(char* s) {
    int length = 0;
    int shift = 0;
    bool allowSpace = false;

    // Remove leading, trailing, and extra spaces
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' && !allowSpace) {
            shift++;
        } else {
            s[i - shift] = s[i];
            length++;
            if (s[i] == ' ') {
                allowSpace = false;
            } else {
                allowSpace = true;
            }
        }
    }

    // Trim the trailing space if it exists
    if (length > 0 && s[length - 1] == ' ') {
        length--;
    }
    s[length] = '\0';

    // Step 1: Reverse the entire string
    reverse(s, 0, length - 1);

    // Step 2: Reverse each word in the reversed string
    int left = 0;
    for (int right = 0; right <= length; right++) {
        if (s[right] == ' ' || s[right] == '\0') {
            reverse(s, left, right - 1);
            left = right + 1;
        }
    }

    return s;
}

int main() {
    char s[] = "  the sky  is blue  ";
    printf("Original: '%s'\n", s);
    char* result = reverseWords(s);
    printf("Reversed: '%s'\n", result); // Expected output: 'blue is sky the'

    char s2[] = "t ";
    printf("Original: '%s'\n", s2);
    result = reverseWords(s2);
    printf("Reversed: '%s'\n", result); // Expected output: 't'

    return 0;
}
