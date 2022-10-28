#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        DFS(nums, 0, used, path);
        return perms;
    }
private:
    vector<vector<int>> perms;

    void DFS(vector<int>& nums, int depth, vector<bool>& used, vector<int>& path) {
        int n = nums.size();
        if (depth == n) {
            perms.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            DFS(nums, depth + 1, used, path);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 2, 3});
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.permute(nums));
    return 0;
}
