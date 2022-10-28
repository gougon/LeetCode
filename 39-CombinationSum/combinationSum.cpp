#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;

        DFS(candidates, ans, {}, 0, target);
        return ans;
    }
private:
    void DFS(vector<int>& candidates, vector<vector<int>>& ans, vector<int> output, int start, int target) {
        if (start == candidates.size()) return;

        for (int i = start; i < candidates.size(); i++) {
            output.push_back(candidates[i]);
            int sum = vecSum(output);
            if (sum == target) {
                ans.push_back(output);
            }
            else if (sum < target) {
                DFS(candidates, ans, output, i, target);
            }
            output.pop_back();
        }
        return;
    }

    int vecSum(vector<int>& vec) {
        int sum = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum += vec[i];
        }
        return sum;
    }
};

int main(int argc, char *argv[]) {
    vector<int> candidates({2});
    int target = 1;
    Solution sol = Solution();
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    Utils<int>::printNestedVector(ans);
    return 0;
}
