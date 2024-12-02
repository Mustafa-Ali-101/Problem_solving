#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_LEN 52


// Hash map structure
typedef struct {
    int entries[MAX_LEN];
} HashMap;

void initHashMap(HashMap* map) {
    for (int i = 0; i < MAX_LEN; i++) {
        map->entries[i] = 0;
    }
}

bool isInHashMap(HashMap* map, const char c) {
    int count;
    if (c > 90) {
        count = map->entries[c - 97];
    } else {
        count = map->entries[c - 39];
    }

    return count > 0;
}

void incrementInHashMap(HashMap *map, const char c) {
    if (c > 90) {
        map->entries[c - 97]++;
    } else {
        map->entries[c - 39]++;
    }
}

void decrementInHashMap(HashMap *map, const char c) {
    if (c > 90) {
        map->entries[c - 97]--;
    } else {
        map->entries[c - 39]--;
    }
}

int getCountFromHashMap(HashMap *map, const char c) {
    if (c > 90) {
        return map->entries[c - 97];
    } else {
        return map->entries[c - 39];
    }
}

void printHashMap(HashMap* map) {
    for (int i = 0; i < MAX_LEN; i++)
    {
        if (i <= 25) {
            printf("%c -> %d", i + 97, map->entries[i]);
        } else {
            printf("%c -> %d", i + 39, map->entries[i]);
        }

        printf("\n");
    }
}


char* minWindow(char* s, char* t) {
    if (strlen(s) < strlen(t)) {
        char* result = malloc(sizeof(char) * 1);
        result[0] = '\0';
        return result;
    };

    // vars
    int tCount = 0;
    int seenCount = 0;
    HashMap tRef;
    HashMap seenMap;
    initHashMap(&tRef);
    initHashMap(&seenMap);

    for (int i = 0; i < strlen(t); i++)
    {
        if (!isInHashMap(&tRef, t[i])) {
            tCount++;
        }
        incrementInHashMap(&tRef, t[i]);
    }
    

    int minWindow = INT_MAX;
    int indices[2] = {-1, -1};

    int left = 0;
    int right = 0;

    while (s[right] != '\0')
    {
        if (isInHashMap(&tRef, s[right])) {
            incrementInHashMap(&seenMap, s[right]);

            // Check if this character satisfies the needed count
            if (getCountFromHashMap(&tRef, s[right]) == 
                getCountFromHashMap(&seenMap, s[right])) {
                    seenCount++;

                    // Check if the window is valid
                    while (seenCount == tCount) {
                        int length = right - left + 1;
                        
                        if (minWindow > length) {
                            minWindow = length;
                            indices[0] = left;
                            indices[1] = right;
                        } 

                        // Optimize solution
                        if (isInHashMap(&tRef, s[left])) {
                            decrementInHashMap(&seenMap, s[left]);

                            // Not a valid solution anymore
                            if (getCountFromHashMap(&tRef, s[left]) > 
                                getCountFromHashMap(&seenMap, s[left])) {
                                    seenCount--;
                            }
                        }
                        
                        left++;
                    }

            }
        }

        // Increment right
        right++;
    }
    
    // Solution fount
    if (minWindow < INT_MAX) {
        int resultLen = (indices[1] - indices[0]) + 2;

        char* result = (char*) malloc(sizeof(char) * resultLen);
        strncpy(result, s + indices[0], resultLen);

        result[resultLen - 1] = '\0';
        return result;
    }
    char* result = malloc(sizeof(char) * 1);
    result[0] = '\0';
    return result;
}


int main(void) {
    HashMap m;
    initHashMap(&m);

    char* string = "cabwefgewcwaefgcf";

    printf("\n");
    printf(minWindow(string, "cae"));


    return 0;
}