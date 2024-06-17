#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


bool isASolution(bool* vector, int k) {
    if (k > 3) {
        // Compute hours
        int hours = 0;
        for (int i = 0; i < 4; i++) {
            if (vector[i]) {
                hours += 1 << (3 - i);
            }
        }

        // if Hours greater than 11
        if (hours > 11) return false;

        // Compute minutes
        int minutes = 0;
        for (int i = 4; i <= k; i++) {
            if (vector[i]) {
                minutes += 1 << (9 - i);
            }
        }

        // If Minutes greater than 59
        if (minutes > 59) return false;

        // Check For Zero or Less
        if (hours <= 0 && minutes <= 0) {
            return false;
        }
    } else {
        // Compute till k
        int hours = 0;
        for (int i = 0; i <= k; i++) {
            if (vector[i]) {
                hours += 1 << (3 - i);
            }
        }

        // if Hours greater than 11
        if (hours > 11) return false;

        // Check For Zero or Less
        if (hours <= 0) {
            return false;
        }
    }

    // Return true
    return true;
}

void processSolution(bool* solution, int index, char** solutions, int* solutionsIndex) {
    // Compute hours
    int hours = 0;
    for (int i = 0; i < 4; i++) {
        if (solution[i]) {
            hours += 1 << (3 - i);
        }
    }

    // Compute minutes
    int minutes = 0;
    for (int i = 4; i <= index; i++) {
        if (solution[i]) {
            minutes += 1 << (9 - i);
        }
    }

    // Allocate enough space for "HH:MM\0"
    char* timeString = (char*) malloc(6);
    sprintf(timeString, "%d:%02d", hours, minutes);

    // Add this solution to solution set
    solutions[*solutionsIndex] = timeString;
    (*solutionsIndex)++;
}

void backtrack(int turnedOn, int k, bool* solutionVector, char** solutions, int* index) {
    // Complete Solution
    if (turnedOn == 0 && isASolution(solutionVector, k)) {
        processSolution(solutionVector, k, solutions, index);
    } else {
        // Cannot Extend
        if (k >= 9 || turnedOn <= 0 || turnedOn >= 9) return;

        // Constructed Candidates here
        solutionVector[k + 1] = true;
        backtrack(turnedOn - 1, k + 1, solutionVector, solutions, index);

        solutionVector[k + 1] = false;
        backtrack(turnedOn, k + 1, solutionVector, solutions, index);
    }
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Variables
    char** solutions = malloc(sizeof(char*) * 1000);
    int index = 0;

    // Test for turnedOn zero
    if (turnedOn == 0) {
        char* zeroSolution = (char*) malloc(6);

        // Format the zero
        sprintf(zeroSolution, "%d:%02d", 0, 00);
        

        solutions[index] = zeroSolution;
        index++;

        (*returnSize) = index;
        return solutions;
    }

    bool* solutionVector = calloc(10, sizeof(bool));
    backtrack(turnedOn, -1, solutionVector, solutions, &index);

    free(solutionVector);
    *returnSize = index;
    return solutions;
}

int main(void) {
    
    int index = 0;
    char** listOfStrings = readBinaryWatch(2, &index);
    
    for (int j = 0; j < index; j++) {
        printf("%s\n", listOfStrings[j]);
    }

    return 0;
}