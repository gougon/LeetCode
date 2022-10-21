#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> hashMap;

        sort(nums.begin(), nums.end());

        if (nums.size() < 3 || nums[0] > 0)
            return {};

        for (int i = 0; i < nums.size(); i++)
            hashMap[nums[i]] = i;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j != i + 1 && nums[j] == nums[j-1]) continue;
                int required = -(nums[i] + nums[j]);
                if (hashMap.find(required) != hashMap.end() && hashMap[required] > j)
                    ans.push_back({ nums[i], nums[j], required });
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solution = Solution();
    vector<int> nums({1, 1, 1, -1, -1, 5, 5, 5, 5});
    vector<vector<int>> ans = solution.threeSum(nums);
    return 0;
}
