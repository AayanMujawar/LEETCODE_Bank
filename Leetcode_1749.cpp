int maxAbsoluteSum(int* nums, int numsSize) {
    int max_sum = 0, min_sum = 0;
    int curr_max = 0, curr_min = 0;

    for (int i = 0; i < numsSize; i++) {
        curr_max = (nums[i] > curr_max + nums[i]) ? nums[i] : curr_max + nums[i];
        max_sum = (max_sum > curr_max) ? max_sum : curr_max;

        curr_min = (nums[i] < curr_min + nums[i]) ? nums[i] : curr_min + nums[i];
        min_sum = (min_sum < curr_min) ? min_sum : curr_min;
    }

    return (max_sum > abs(min_sum)) ? max_sum : abs(min_sum);
}

