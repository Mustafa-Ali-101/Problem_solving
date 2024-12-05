#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hash_table_str.h"


char*** copyToArray(HashTable* hashTable, int maxLen,  int* returnSize, int** returnColumnSizes) {
    char*** result = malloc(maxLen * sizeof(char**));
    int* columnSizes = malloc(maxLen * sizeof(int));
    int resultIndex = 0;

    for(int i = 0; i< hashTable->size; i++) {
        HashTableEntry* bucketPointer = hashTable->table[i];
       
        // Only if entry is not NULL
        if (bucketPointer != NULL) {
            // Create new array of words
            char** words = malloc(maxLen * sizeof(char*));
            int wordsIndex = 0;

            // Copy words to the array
            while (bucketPointer != NULL) {
                // Create a new word
                char* word = (char*) malloc(sizeof(char) * 100);
                
                // copy to the new word
                strcpy(word, bucketPointer->word);

                // add the new word to array of words
                words[wordsIndex] = word;
                wordsIndex++;

                // Move to next word
                bucketPointer = bucketPointer->next;
            }

            // Set the array length
            columnSizes[resultIndex] = wordsIndex;

            // Put the array in the result
            result[resultIndex] = words;
            resultIndex++;
        }
    }

    // Set the resutl length
    (*returnSize) = resultIndex;

    // Set column lengths
    (*returnColumnSizes) = columnSizes;
    
    return result;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    // Create Hash Table
    HashTable* table = createHashTable(strsSize);

    // Insert the words in table
    for (int i = 0; i < strsSize; i++) {
        insert(table, strs[i]);
    }

    // return copyToArray
    return copyToArray(table, strsSize, returnSize, returnColumnSizes);
}


int main(void) {
    char* strs[] = {"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv", 
    "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuv"
};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;

    // Call the function
    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

     // Print the results
    printf("Number of groups: %d\n", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("Group %d: ", i + 1);
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }


    return 0;
}