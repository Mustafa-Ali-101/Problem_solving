typedef struct {
    int* numbers;
    int size;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* newObj = malloc(sizeof(NumArray));
    newObj->numbers = nums;
    newObj->size = numsSize;
    return newObj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;
    right = right >= obj->size ? obj->size - 1: right;

    for (; left <= right; left++) {
        sum += obj->numbers[left];
    }

    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/


int main(void) {
    return 0;
}