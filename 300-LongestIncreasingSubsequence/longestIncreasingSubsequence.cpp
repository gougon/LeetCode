#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp({nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            if (cur > dp[dp.size() - 1])
                dp.push_back(cur);
            else {
                auto itr = lower_bound(dp.begin(), dp.end(), cur);
                *itr = cur;
            }
        }
        return dp.size();
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({3, 2, 1});

    Solution sol = Solution();
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}
