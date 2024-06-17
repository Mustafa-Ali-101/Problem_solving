#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SOLUTION_SIZE 300

void processSolution(bool* solution, int index, char** solutions, int* solutionsIndex) {
    int hours = 0;
    for (int i = 0; i < 4; i++) {
        if (solution[i]) {
            hours += 1 << (3 - i);
        }
    }

    int minutes = 0;
    for (int i = 4; i <= index; i++) {
        if (solution[i]) {
            minutes += 1 << (9 - i);
        }
    }

    if (hours > 11 || minutes > 59) {
        return;
    }

    char* timeString = (char*)malloc(6 * sizeof(char));
    sprintf(timeString, "%d:%02d", hours, minutes);
    solutions[*solutionsIndex] = timeString;
    (*solutionsIndex)++;
}

void backtrack(int turnedOn, int k, bool* solutionVector, char** solutions, int* index) {
    if (turnedOn == 0) {
        processSolution(solutionVector, k, solutions, index);
        return;
    }
    if (k == 9) {
        return;
    }

    solutionVector[k + 1] = true;
    backtrack(turnedOn - 1, k + 1, solutionVector, solutions, index);

    solutionVector[k + 1] = false;
    backtrack(turnedOn, k + 1, solutionVector, solutions, index);
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** solutions = (char**)malloc(MAX_SOLUTION_SIZE * sizeof(char*));
    int index = 0;
    bool* solutionVector = (bool*)calloc(10, sizeof(bool));

    backtrack(turnedOn, -1, solutionVector, solutions, &index);

    free(solutionVector);
    *returnSize = index;
    return solutions;
}

int main() {
    int returnSize;
    int num = 2;
    char** times = readBinaryWatch(num, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", times[i]);
        free(times[i]);
    }
    free(times);
    return 0;
}
