#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <limits.h>



// Function that removes all duplicates of a sorted array
// except for two coppies of that array
int removeDuplicate(int* list, int listSize) {
	int dup = 1;
	int steps = 0;
	int i = 1;

	// Loop through the array
	for (i; i < listSize; i++) {

		// calculate the steps to be jumped
		if (list[i] != list[i - 1]) {
			if (dup > 2) {
				steps += dup - 2;
			}
			dup = 1;
		} else { // just increment the duplication
			dup++;
		}

		// jump to right place
		list[i - steps] = list[i];
	}

	// calculate steps again
	// because of the last element
	if (dup > 2) {		
		steps += dup - 2;
	}

	return i - steps;
}
int main(void) {

	int list[] = {1,1,1,2,2,3};

	int len = removeDuplicate(list, 6);

	for (int i = 0; i < len; i++) {
		printf("%d ", list[i]);}

	return 0;}
