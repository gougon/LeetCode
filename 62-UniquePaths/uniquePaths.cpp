#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return dp(m, n);
    }

    int recursive(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (m < 0 || n < 0) return 0;
        if (map[m][n] > 0) return map[m][n];
        
        int left = uniquePaths(m, n - 1);
        int top = uniquePaths(m - 1, n);
        map[m][n] = left + top;
        return map[m][n];
    }

    int dp(int m,  int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
private:
    unordered_map<int, unordered_map<int, int>> map;
};

int main(int argc, char *argv[]) {
    int m = 3, n = 7;
    Solution sol = Solution();
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
