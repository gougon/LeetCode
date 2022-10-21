#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (right + left) / 2;
        vector<int> ans({-1, -1});

        binarySearch(nums, ans, target, left, right, mid, 0);
        binarySearch(nums, ans, target, left, right, mid, 1);

        return ans;
    }

    void binarySearch(vector<int>& nums, vector<int>& ans, int target, int left, int right, int mid, int direction) {
        if (left > right)
            return;
            
        int n = nums.size();
        if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] < target)
            left = mid + 1;
        else {
            if (direction == 0) {
                if (mid == 0 || nums[mid - 1] != target) {
                    ans[0] = mid;
                    return;
                }
                right = mid - 1;
            }
            else {
                if (mid == n - 1 || nums[mid + 1] != target) {
                    ans[1] = mid;
                    return;
                }
                left = mid + 1;
            }
        }

        binarySearch(nums, ans, target, left, right, (right + left) / 2, direction);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({5, 6, 6, 7, 8, 8, 10});
    int target = 8;

    Utils<int>::printVector(nums);

    Solution sol = Solution();
    vector<int> ans = sol.searchRange(nums, target);

    Utils<int>::printVector(ans);
    return 0;
}
