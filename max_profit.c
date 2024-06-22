#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int max_profit(int* prices, int pricesSize) {
    int maxProfit = 0;

    int left = 0;
    int right = 1;

    while (left < pricesSize && right < pricesSize) {
        if (prices[right] >= prices[right - 1]) {
            right++;
        } else if (right - 2 >= 0 && prices[right - 2] > prices[right - 1]) {
            // Buy (Fake Buy)
            left = right;

            right++;
        } else {
            // Sell what you have
            maxProfit += prices[right - 1] - prices[left];

            // Buy (Fake)
            left = right;

            right++;
        }
    }

    // 
    if (left == 0 && right == pricesSize) {
        maxProfit = prices[right - 1] - prices[left];
    }


    return maxProfit;
}

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

    int list[] = {7,1,5,3,6,4};

    int max = maxProfit(list, 6);


    printf("The output is => %d \n", max);
    return 0;
}