#include <iostream>
#include <vector>
using namespace std;

// Returns the number of ways to make the given amount using the available coins.
int coinChange(int coins[], int n, int amount) {
    // dp[i][j] stores the number of ways to make amount j using the first i coins.
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case: one way to make amount 0 using any number of coins (choose nothing).
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table for each coin and each possible amount.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            // If the current coin can be used, add ways that exclude it and include it.
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            } else {
                // Otherwise, the current coin cannot be used for this amount.
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Return the number of ways for the full set of coins and requested amount.
    return dp[n][amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 5;
    int n = sizeof(coins) / sizeof(coins[0]);

    cout << "Number of ways to make change for " << amount << " = "
         << coinChange(coins, n, amount) << endl;

    return 0;
}