#include <iostream>
#include <vector>
using namespace std;

int targetSum(int arr[], int n, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: sum 0 is always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {

            if (arr[i - 1] <= j) {
                // exclude OR include current element
                dp[i][j] = dp[i - 1][j] ||
                           dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int result = targetSum(arr, n, target);

    if (result) {
        cout << "Found a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum." << endl;
    }

    return 0;
}