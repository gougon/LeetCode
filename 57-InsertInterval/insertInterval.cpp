#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) 
            return a.second > b.second;
        else 
            return a.first < b.first;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int, int>> q;

        for (auto interval: intervals) {
            q.push_back(pair<int, int>(interval[0], 1));
            q.push_back(pair<int, int>(interval[1], -1));
        }
        q.push_back(pair<int, int>(newInterval[0], 1));
        q.push_back(pair<int, int>(newInterval[1], -1));

        sort(q.begin(), q.end(), cmp);

        vector<vector<int>> ans;
        int start, end;
        int counter = 0;
        for (auto x: q) {
            counter += x.second;
            if (x.second == 1 && counter == 1) {
                start = x.first;
            }
            else if (x.second == -1 && counter == 0) {
                end = x.first;
                ans.push_back({start, end});
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> intervals({
        {1, 3}, 
        {6, 9}
    });
    vector<int> newInterval({2, 5});
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.insert(intervals, newInterval));
    return 0;
}
