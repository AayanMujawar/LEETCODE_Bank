#include <stdio.h>
#include <stdlib.h>

void product_except_self(int* nums, int n, int* result) {
    // Create arrays for prefix and suffix products
    int* prefix = (int*)malloc(n * sizeof(int));
    int* suffix = (int*)malloc(n * sizeof(int));
int i;
    // Compute prefix products
    prefix[0] = 1;
    for (i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // Compute suffix products
    suffix[n - 1] = 1;
    for ( i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // Compute the result by multiplying prefix and suffix products
    for ( i = 0; i < n; i++) {
        result[i] = prefix[i] * suffix[i];
    }

    // Free allocated memory
    free(prefix);
    free(suffix);
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the input array
    int* nums = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
int i;
    // Get the array elements from the user
    printf("Enter the elements of the array: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Call the function to calculate the product except self
    product_except_self(nums, n, result);

    // Print the result
    printf("Result: ");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free allocated memory
    free(nums);
    free(result);

    return 0;
}

