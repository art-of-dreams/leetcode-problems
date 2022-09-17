// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing
// a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve
// any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

// Constraints:

//     1 <= prices.length <= 10^5
//     0 <= prices[i] <= 10^4

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int res = 0;
    pricesSize -= 1;

    while (pricesSize >= 0) {
        for (int i = pricesSize; i >= 0; i--) {
            int current = prices[pricesSize] - prices[i];

            if (current > res) {
                res = current;
            }
        }

        pricesSize -= 1;
    }

    return res;
}

int maxProfit2(int* prices, int pricesSize) {
    int minPrice = INT_MAX;
    int res = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (res < (prices[i] - minPrice)) {
            res = prices[i] - minPrice;
        }
    }

    return res;
}

int main() {
    int values[] = {7,6,4,3,1};
    printf("%d\n", maxProfit((int*)&values, sizeof(values) / sizeof(int)));
    printf("%d\n", maxProfit2((int*)&values, sizeof(values) / sizeof(int)));
}
