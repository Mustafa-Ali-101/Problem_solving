#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool isBadVersion(int num) {
    if (num > 5) return true;
    return false;
}

int firstBadVersion(int n) {
    int min = 0;
    int max = n;

    while (min <= max) {
        int mid = ((max - min) / 2) + min;

        if (isBadVersion(mid)) {
            if (!isBadVersion(mid - 1)) {
                return mid;
            }

            max = mid - 1;
        } else {
            if (isBadVersion(mid + 1)) {
                return mid + 1;
            }

            min = mid + 1;
        }

    }
}


