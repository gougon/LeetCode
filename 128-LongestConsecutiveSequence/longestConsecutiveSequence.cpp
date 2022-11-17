#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> hashNums;
        for (auto& num: nums) 
            hashNums.insert(num);

        int maxLen = 0;
        for (auto& num: nums) {
            if (hashNums.count(num) == 0 || hashNums.count(num - 1) != 0)
                continue;
            hashNums.erase(num);

            int len = 1;
            int next = num + 1;
            while (hashNums.count(next) != 0) {
                hashNums.erase(next);
                len++;
                next++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({0,3,7,2,5,8,4,6,0,1});

    Solution sol = Solution();
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}
