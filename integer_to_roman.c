#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int intList[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* romanList[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Allocate enough memory for the result
    char* result = malloc(20 * sizeof(char)); // Maximum length of a Roman numeral for numbers <= 3999 is 15 characters
    if (result == NULL) {
        return NULL;
    }
    result[0] = '\0'; // Initialize the result string as empty

    int index = 0;

    while (num > 0) {
        while (num >= intList[index]) {
            strcat(result, romanList[index]);
            num -= intList[index];
        }
        index++;
    }

    return result;
}

int main() {
    int num = 1994;
    char* roman = intToRoman(num);
    printf("Roman numeral of %d is %s\n", num, roman);
    free(roman); // Free the allocated memory
    return 0;
}
