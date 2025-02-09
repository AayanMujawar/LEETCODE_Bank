#include <stdio.h>
#include <limits.h>

// Function to calculate the maximum profit
int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;  // Initialize to maximum possible integer
    int maxProfit = 0;       // Initialize profit to 0
int i;
    for (i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            // Update minimum price
            minPrice = prices[i];
        } else {
            // Calculate profit and update maxProfit
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

// Main function
int main() {
    int n;
int i;
    // Input the size of the array
    printf("Enter the number of days: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of days.\n");
        return 1;
    }

    // Dynamically allocate memory for the prices array
    int* prices = (int*)malloc(n * sizeof(int));
    if (prices == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the prices
    printf("Enter the stock prices for %d days:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    // Calculate the maximum profit
    int profit = maxProfit(prices, n);

    // Print the result
    printf("Maximum profit: %d\n", profit);

    // Free allocated memory
    free(prices);

    return 0;
}

