#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
    // Variables
    int i;

    // Make an array with each ascii character having a spot
    int sMappings[128];
    int tMappings[128];
    for (i = 0; i < 128; i++) {
        sMappings[i] = -1;
        tMappings[i] = -1;
    }

    for (i = 0; s[i] != NULL; i++) {
        // This specific character hasn't been mapped
        if (sMappings[s[i]] == -1) {
            // Check for the availability of the tMapping
            if (tMappings[t[i]] == -1) {
                // We can map character s to t and reserve t
                sMappings[s[i]] = t[i];
                tMappings[t[i]] = s[i];
            } else { // tMapping is not available
                return false;
            }

        } // Mapped but to a different value 
        else if (sMappings[s[i]] != t[i]) { 
            return false;
        }
    }

    return true;
}


int main(void) {

    return 0;
}