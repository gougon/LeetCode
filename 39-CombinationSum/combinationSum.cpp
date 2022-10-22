#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, bool> hashmap;
        
    }
};

int main(int argc, char *argv[]) {
    vector<int> candidates({2, 3, 6, 7});
    int target = 7;
    Solution sol = Solution();
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    Utils<int>::printNestedVector(ans);
    return 0;
}
