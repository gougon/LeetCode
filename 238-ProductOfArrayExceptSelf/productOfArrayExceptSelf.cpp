#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

#define ll long long

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int right = 1;
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            ans[i] = ans[i] * right;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 2, 3, 4});
    Solution sol = Solution();
    Utils<int>::printVector(sol.productExceptSelf(nums));
    return 0;
}
