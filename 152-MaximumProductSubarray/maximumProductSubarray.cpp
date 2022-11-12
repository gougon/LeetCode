#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        Sort nums, if nums of negative is even, product all element except 0, 
        if nums of negative is odd, product all element except 0 and latest one
        TC = O(nlogn + n)

        If i want to go through 1 pass to find answer, the element will affect the answer will ne 0 / -, 
        so i can use 2 array to store these message, 
        because 0 will never be part of answer (if max > 0), so i can divide array into subarrays, 
        then i can count each subarray's negative nums
        if even, store it into maxCandidate
           odd,  i is first negative, j is latest negative, max(start~i-1, start~j-1, i+1~end, j+1~end) store it into maxCandidate
        TC = O(n)
        */
        vector<int> maxDp(nums.size());
        vector<int> minDp(nums.size());
        maxDp[0] = nums[0];
        minDp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxDp[i] = max(max(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]), nums[i]);
            minDp[i] = min(min(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]), nums[i]);
        }
        
        return *max_element(maxDp.begin(), maxDp.end());
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> nums({
        {2, 3, -2, 4}, 
        {-1, 0, -1}, 
        {0}, 
        {-1}, 
        {-1, -2, -3}, 
        {1, 2, 3}, 
        {2, 3, -2, -3, 4}, 
        {-2, 1, 2, 3, -2}, 
        {0, 2}
    });

    Solution sol = Solution();
    for (auto n: nums)
        cout << sol.maxProduct(n) << endl;
    return 0;
}
