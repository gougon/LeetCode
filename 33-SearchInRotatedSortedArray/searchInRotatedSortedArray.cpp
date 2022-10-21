#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int m = (r - l) / 2 + l;
        int pivot = nums[0];

        if (n == 1)
            return target == nums[0] ? 0 : -1;

        return binarySearch(nums, target, l, r, m, pivot);
    }

    int binarySearch(vector<int>& nums, int target, int l, int r, int m, int pivot) {
        bool isTargetPostArr = pivot <= target;
        bool isCurPostArr = pivot <= nums[m];
        if (l > r)
            return -1;

        if (target == nums[m]) {
            return m;
        }

        if (isCurPostArr) {
            if (isTargetPostArr) {
                if (target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else {
                l = m + 1;
            }
        }
        else {
            if (!isTargetPostArr) {
                if (target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        m = floor(r - l) / 2 + l;

        return binarySearch(nums, target, l, r, m, pivot);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({5, 6, 7, 1, 2, 3});
    int target = 1;
    Solution sol = Solution();
    int ans = sol.search(nums, target);
    cout << ans << endl;
    return 0;
}
