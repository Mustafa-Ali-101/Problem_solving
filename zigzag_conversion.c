#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int length = strlen(s);
    int index = 0;
    char* result = (char*) malloc(sizeof(char) * length + 1);
    result[length] = '\0';

    int jump = 2 * numRows - 2;
    for (int r = 0; r < numRows; r++) {
       int j = r;

       while (j < length) {
            result[index] = s[j];
            index++;
            j += jump;

            // Middle Rows
            if (r > 0 && r < numRows - 1 && (j - 2 * r) < length) {
                result[index] = s[j - 2 * r];
                index++;
            }
       }
       
    }

    return result;
}


int main(void) {

    printf(convert("PAYPALISHIRING", 3));
    return 0;
}