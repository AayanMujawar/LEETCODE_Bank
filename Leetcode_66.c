#include <stdio.h>
#include <stdlib.h>

int* increment_large_integer(int* digits, int n, int* new_size) {
	int i;
    for ( i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *new_size = n;
            return digits;
        }
        digits[i] = 0;
    }

    // If all digits are 9, we need an extra digit
    int* result = (int*)malloc((n + 1) * sizeof(int));
    result[0] = 1;
    for (i = 1; i <= n; i++) {
        result[i] = 0;
    }
    *new_size = n + 1;
    return result;
}

int main() {
    int n;
int i;
    // Get the size of the array from the user
    printf("Enter the number of digits: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the input array
    int* digits = (int*)malloc(n * sizeof(int));

    // Get the array elements from the user
    printf("Enter the digits: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &digits[i]);
    }

    // Increment the large integer
    int new_size;
    int* result = increment_large_integer(digits, n, &new_size);

    // Print the result
    printf("Result: ");
    for (i = 0; i < new_size; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Free allocated memory
    if (result != digits) {
        free(result);
    }
    free(digits);

    return 0;
}

