#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} HashMapEntry;

// Hash map structure
typedef struct {
    HashMapEntry entries[MAX_WORDS];
    int size;
} HashMap;

void initHashMap(HashMap *map) {
    map->size = 0;
}

int findInHashMap(HashMap *map, const char *word) {
    for (int i = 0; i < map->size; i++) {
        if (strcmp(map->entries[i].word, word) == 0)
            return i;
    }
    return -1;
}

void incrementInHashMap(HashMap *map, const char *word) {
    int index = findInHashMap(map, word);
    if (index == -1) {
        strcpy(map->entries[map->size].word, word);
        map->entries[map->size].count = 1;
        map->size++;
    } else {
        map->entries[index].count++;
    }
}

void decrementInHashMap(HashMap *map, const char *word) {
    int index = findInHashMap(map, word);
    if (index != -1) {
        map->entries[index].count--;
    }
}

int getCountFromHashMap(HashMap *map, const char *word) {
    int index = findInHashMap(map, word);
    if (index == -1) return 0;
    return map->entries[index].count;
}

void clearHashMap(HashMap *map) {
    map->size = 0;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    int wordLength = strlen(words[0]);
    int sLength = strlen(s);
    int totalWordsLength = wordLength * wordsSize;

    if (sLength < totalWordsLength) {
        return NULL;
    }

    // Initialize reference map
    HashMap refMap;
    initHashMap(&refMap);
    for (int i = 0; i < wordsSize; i++) {
        incrementInHashMap(&refMap, words[i]);
    }

    // Allocate enough space for possible indices
    int *result = (int *)malloc(sLength * sizeof(int));

    for (int offset = 0; offset < wordLength; offset++) {
        int size = 0;
        HashMap seenMap;
        initHashMap(&seenMap);

        for (int i = offset; i + wordLength <= sLength; i += wordLength) {
            char currentWord[wordLength + 1];
            strncpy(currentWord, s + i, wordLength);
            currentWord[wordLength] = '\0';

            if (findInHashMap(&refMap, currentWord) == -1) {
                clearHashMap(&seenMap);
                size = 0;
                continue;
            }

            incrementInHashMap(&seenMap, currentWord);
            size++;

            while (getCountFromHashMap(&seenMap, currentWord) > getCountFromHashMap(&refMap, currentWord)) {
                char firstWord[wordLength + 1];
                int start = i - (size - 1) * wordLength;
                strncpy(firstWord, s + start, wordLength);
                firstWord[wordLength] = '\0';
                decrementInHashMap(&seenMap, firstWord);
                size--;
            }

            if (size == wordsSize) {
                result[*returnSize] = i - (size - 1) * wordLength;
                (*returnSize)++;
            }
        }
    }

    // Resize result array to match the number of results found
    result = realloc(result, (*returnSize) * sizeof(int));
    return result;
}

int main() {
    char *s = "abbarfoofoobarthe";
    char *words[] = {"foo", "bar", "the"};
    int wordsSize = 3;
    int returnSize;
    int *result = findSubstring(s, words, wordsSize, &returnSize);

    printf("Indices: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
