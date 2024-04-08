#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "helper.h"

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // Define hash tables for rows, columns, and boxes
    HashTable* rows[9];
    HashTable* cols[9];
    HashTable* boxes[9];
    
    // Initialize hash tables
    for (int i = 0; i < 9; i++) {
        rows[i] = createHashTable(9);
        cols[i] = createHashTable(9);
        boxes[i] = createHashTable(9);
    }
    
    // Iterate over each cell in the board
    for (int i = 0; i < boardSize; i++) { // Every Row
        for (int j = 0; j < *boardColSize; j++) { // Every Cell
            char num = board[i][j];
            if (num != '.') {
                int n = num - '0';
                int boxIndex = (i / 3) * 3 + j / 3;
                
                // Check if the number is already in the current row, column, or box
                if (search(rows[i], n) == n || search(cols[j], n) == n || search(boxes[boxIndex], n) == n) {
                    return false;
                }
                
                // Insert the number into the current row, column, and box
                insert(rows[i], n);
                insert(cols[j], n);
                insert(boxes[boxIndex], n);
            }
        }
    }
    
    // Free hash tables
    for (int i = 0; i < 9; i++) {
        freeHashTable(rows[i]);
        freeHashTable(cols[i]);
        freeHashTable(boxes[i]);
    }
    
    return true;
}


int main(void) {
    return 0;
}