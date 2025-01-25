#include <stdio.h>
#include <stdlib.h>

// Function to remove duplicates in-place
int removeDuplicates(int* nums, int numsSize) {
	int j ;
    if (numsSize == 0) return 0;

    int i = 0; // Pointer for the last unique element

    for (j= 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;             // Move to the next position for a unique element
            nums[i] = nums[j]; // Update the position with the new unique element
        }
    }

    return i + 1; // The number of unique elements
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int* nums = (int*)malloc(n * sizeof(int));
    int i;
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the array elements
    printf("Enter %d elements in sorted non-decreasing order:\n", n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Call the function to remove duplicates
    int k = removeDuplicates(nums, n);

    // Output the results
    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: ");
    for ( i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Free allocated memory
    free(nums);

    return 0;
}

