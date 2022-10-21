#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();

        sort(nums.begin(), nums.end());

        if (len < 3) return 0;

        if (target > 0 && nums[0] > target)
            return nums[0] + nums[1] + nums[2];
        else if (target < 0 && nums[len - 1] < target)
            return nums[len - 1] + nums[len - 2] + nums[len - 3];

        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(target - ans) > abs(target - sum))
                    ans = sum;
                int nextLeftSum = nums[i] + nums[left + 1] + nums[right];
                int nextRightSum = nums[i] + nums[left] + nums[right - 1];
                if (abs(target - nextLeftSum) > abs(target - nextRightSum))
                    right--;
                else if (abs(target - nextLeftSum) < abs(target - nextRightSum))
                    left++;
                else {
                    right--;
                    left++;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution solution = Solution();
    vector<int> nums({1, 1, 1, 5, 5, 5, 5, 5, 5});
    int target = 14;
    int ans = solution.threeSumClosest(nums, target);
    cout << ans << endl;
    return 0;
}
