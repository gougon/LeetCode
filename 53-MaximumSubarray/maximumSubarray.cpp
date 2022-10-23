#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxSub(n);
        maxSub[0] = nums[0];
        int ret = nums[0];

        for (int i = 1; i < n; i++) {
            maxSub[i] = max(maxSub[i - 1] + nums[i], nums[i]);
            ret = max(maxSub[i], ret);
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({-1, 1, -3, 4, -1, 2, 1, -5, 4});
    Solution sol = Solution();
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}
