#include <stdio.h>
#include <stdlib.h>

// Function to sort squares of a sorted array
void sortedSquares(int* nums, int numsSize, int* result) {
    int left = 0;                // Left pointer
    int right = numsSize - 1;    // Right pointer
    int index = numsSize - 1;    // Index to fill the result array (start from the end)

    while (left <= right) {
        int leftVal = abs(nums[left]);
        int rightVal = abs(nums[right]);
        
        if (leftVal > rightVal) {
            result[index] = leftVal * leftVal;
            left++;
        } else {
            result[index] = rightVal * rightVal;
            right--;
        }
        index--;
    }
}

// Helper function to print an array
void printArray(int* arr, int size) {
	int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Dynamically allocate memory for the input array and result array
    int* nums = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));
int i;
    if (nums == NULL || result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get the array elements from the user
    printf("Enter %d integers (sorted in non-decreasing order):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Process the array to get sorted squares
    sortedSquares(nums, n, result);

    // Print the result
    printf("Sorted squares of the array: ");
    printArray(result, n);

    // Free the allocated memory
    free(nums);
    free(result);

    return 0;
}
