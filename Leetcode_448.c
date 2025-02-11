int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* hash = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num >= 1 && num <= numsSize) {
            hash[num - 1] = 1;
        }
    }
    int* result = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (hash[i] == 0) {
            result[count++] = i + 1;
        }
    }
    *returnSize = count;
    free(hash);
    return result;
}

