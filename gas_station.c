#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    // Check if there is a solution
    int totalGas = 0;
    int totalCost = 0;
    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
    }

    if (totalGas < totalCost) {
        return -1; 
    }

    // Now we guarantee there exists a solution
    int total = 0;
    int result = 0;
    for (int i = 0; i < gasSize; i++) {
        total += gas[i] - cost[i];

        if (total < 0) {
            total = 0;
            result = i + 1;
        }
    }
    
    return result;
}


int main(void) {
    int gas[] = {1,2,3,4,5};
    int cost[] = {3,4,5,1,2};

    printf("%d \n", canCompleteCircuit(gas,5,cost,5));
    return 0;
}