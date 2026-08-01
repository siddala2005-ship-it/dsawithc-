#include <iostream>
#include <vector>
using namespace std;

int rodCut(vector<int>& price, vector<int>& pieces, int rodLength) {
    int n = pieces.size();

    vector<vector<int>> dp(n + 1, vector<int>(rodLength + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= rodLength; j++) {
            if (pieces[i - 1] <= j) {
                dp[i][j] = max(
                    price[i - 1] + dp[i][j - pieces[i - 1]],
                    dp[i - 1][j]
                );
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][rodLength];
}

int main() {
    vector<int> price = {1,5,8,9,10,17,17,20};
    vector<int> pieces = {1,2,3,4,5,6,7,8};

    cout << rodCut(price, pieces, 8);

    return 0;
}