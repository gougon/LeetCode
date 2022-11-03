#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    /*
    1 2 3
    1 12 123 13 2 23 3

    1 2 3 4
    1 12 123 1234 124 13 134 14 2 23 234 24 3 34 4
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        _rets.push_back({});
        
        vector<int> output;
        DFS(0, nums.size(), nums, output);
        return _rets;
    }
private:
    vector<vector<int>> _rets;

    void DFS(int i, const int& n, vector<int>& nums, vector<int>& output) {
        for (; i < n; i++) {
            output.push_back(nums[i]);
            _rets.push_back(output);
            DFS(i + 1, n, nums, output);
            output.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 2});
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.subsets(nums));
    return 0;
}
