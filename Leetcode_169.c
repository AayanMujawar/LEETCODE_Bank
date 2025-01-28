#include <stdio.h>
#include <stdlib.h>

int find_majority_element(int* nums, int n) {
    int count = 0, candidate = 0;
int i;
    // Boyer-Moore Voting Algorithm to find majority element
    for ( i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    int n;
int i;
    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the input array
    int* nums = (int*)malloc(n * sizeof(int));

    // Get the array elements from the user
    printf("Enter the elements of the array: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Find the majority element
    int majority_element = find_majority_element(nums, n);

    // Print the result
    printf("The majority element is: %d\n", majority_element);

    // Free allocated memory
    free(nums);

    return 0;
}

