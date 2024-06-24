#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}
int main(void) {

    int list[] = {6,1,3,2,4,7};

    int max = max_profit(list, 6);


    printf("The output is => %d \n", max);
    return 0;
}