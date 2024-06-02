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
        int placeValue = 3;
        for (int i = 0; i < 4; i++) {
            hours += (int)vector[i] * pow(2, placeValue);

            // if Hours greater than 12
            if (hours > 12) return false; 

            placeValue--;
        }

        // Compute minutes
        int minutes = 0;
        int valuePlace = 5;
        for (int i = 4; i <= k; i++) {
            minutes += (int)vector[i] * pow(2, valuePlace);

            // If Minutes greater than 60
            if (minutes > 60) return false;

            valuePlace--;
        }

        // Check For Zero or Less
        if (hours <= 0 && minutes <= 0) {
            return false;
        }
    } else {
        // Compute till k
        int hours = 0;
        int placeValue = 3;
        for (int i = 0; i <= k; i++) {
            hours += (int)vector[i] * pow(2, placeValue);

            // if Hours greater than 12
            if (hours > 12) return false; 

            placeValue--;
        }

        // Check For Zero or Less
        if (hours <= 0) {
            return false;
        }
    }

    // Return true
    return true;
}

void processSolution(bool* solution, int index, char** solutions, int* solutionsIndex) {
    if (index > 3) {
        // Compute hours
        int hours = 0;
        int placeValue = 3;
        for (int i = 0; i < 4; i++) {
            hours += (int)solution[i] * pow(2, placeValue);
            placeValue--;
        }

        // Compute minutes
        int minutes = 0;
        int valuePlace = 5;
        for (int i = 4; i <= index; i++) {
            minutes += (int)solution[i] * pow(2, valuePlace);
            valuePlace--;
        }

        char* hoursString = (char*) malloc(4);
        char minutesString[3];
        sprintf(hoursString, "%d", hours);
        sprintf(minutesString, "%02d", minutes);

        // Add SemiColon
        strcat(hoursString, ":");
        strcat(hoursString, minutesString);

        // Add this solution to solution set
        solutions[*solutionsIndex] = hoursString;
        (*solutionsIndex)++;
        return;
    } else {
        // Compute hours
        int hours = 0;
        int placeValue = 3;
        for (int i = 0; i <= index; i++) {
            hours += (int)solution[i] * pow(2, placeValue);
            
            placeValue--;
        }

        char* hoursString = (char*) malloc(4);
        sprintf(hoursString, "%d", hours);
        

        // Add SemiColon and minutes
        strcat(hoursString, ":00");

        // Add this solution to solution set
        solutions[*solutionsIndex] = hoursString;
        (*solutionsIndex)++;
        return;
    }
}


void backtrack(int turedOn, int k, bool* solutionVector, char** solutions, int* index) {
    
    // Complete Solution
    if (isASolution(solutionVector, k)) {
        processSolution(solutionVector, k, solutions, index);
    } else {
        // Cannot Extend
        if (k >= 9 || turedOn <= 0 || turedOn >= 9) return;

        // Constructed Candidates here
        solutionVector[k + 1] = true;
        backtrack(turedOn - 1, k + 1, solutionVector, solutions, index);

        solutionVector[k + 1] = false;
        backtrack(turedOn, k + 1, solutionVector, solutions, index);
    }
}
char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Variables
    char** solutions = malloc(sizeof(char*) * 100);
    int index = 0;

    bool* solutionVector = malloc(sizeof(bool) * 10);
    backtrack(turnedOn, -1, solutionVector, solutions, &index);

    free(solutionVector);
    (*returnSize) = index;
    return solutions;
}

int main(void) {
    int index = 0;
    char** listOfStrings = readBinaryWatch(0, &index);
    
    for (int j = 0; j < index; j++) {
        printf("%s\n", listOfStrings[j]);
    }

    return 0;
}