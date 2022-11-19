#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSum;
        int count = 0, maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            else
                count--;

            if (count == 0) 
                maxLen = i + 1;
            
            if (prefixSum.find(count) != prefixSum.end()) 
                maxLen = max(maxLen, i - prefixSum[count]);
            else 
                prefixSum[count] = i;
        }
        return maxLen;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 1, 1, 0, 1, 1, 0});
    Solution sol = Solution();
    cout << sol.findMaxLength(nums) << endl;
    return 0;
}
