#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        if (amount == 0) return 0;
        if (coins[0] > amount) return -1;
        
        vector<int> dp(amount - coins[0] + 1, INT_MAX);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            int curAmount = i + coins[0];
            int minPrevCoins = INT_MAX;
            for (int j = 0; j < coins.size() && coins[j] <= curAmount; j++) {
                int diff = curAmount - coins[j];
                dp[i] = min(dp[i], dp[diff - coins[0]] + 1);
            }
        }
        return (dp[dp.size() - 1] == INT_MAX) ? -1 : dp[dp.size() - 1];
    }
private:
    void DFS() {

    }
};

int main(int argc, char *argv[]) {
    vector<int> coins({1, 2, 5});
    int amount = 11;
    Solution sol = Solution();
    cout << sol.coinChange(coins, amount) << endl;
    return 0;
}
