#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int candy(int* ratings, int ratingsSize) {
    int total = 0;
    int* list = (int*) malloc(sizeof(int) * ratingsSize);

    // Traverse the list to give each child one candy
    for (int i = 0; i < ratingsSize; i++) {
        list[i] = 1;
    }

    // Traverse the list from left to right
    // to ensure every child has more than his left neighbor
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            list[i] = list[i - 1] + 1;
        }
    }

    // Travers the list from right to left
    for (int i = ratingsSize - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1] && list[i] <= list[i + 1]) {
            list[i] = list[i + 1] + 1;
        }
    }

    // Sum all candy in list
    for (int i = 0; i < ratingsSize; i++)
    {
        total += list[i];
    }
    

    return total;
}

int main(void) {
    int list[] = {1,3,4,5,2};

    candy(list, 5);
    return 0;
}