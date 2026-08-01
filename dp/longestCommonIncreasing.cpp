#include <bits/stdc++.h>

using namespace std;

int longestIncreasingSubSequence( vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    vector<int> arr(s.begin(), s.end());
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int m = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i - 1] == nums[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];    
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << longestIncreasingSubSequence(nums) << '\n';
    return 0;
}