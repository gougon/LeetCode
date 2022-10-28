#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& left, vector<int>& right) {
        if (left[0] == right[0])
            return left[1] < right[1];
        return left[0] < right[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end(), cmp);
        Utils<int>::printNestedVector(intervals);
        vector<vector<int>> rets({intervals[0]});
        for (int i = 1; i < intervals.size(); i++) {
            if (rets.back()[1] >= intervals[i][0]) {
                int front = rets.back()[0];
                int end = (rets.back()[1] > intervals[i][1]) ? rets.back()[1] : intervals[i][1];
                vector<int> newInterval = {front, end};
                rets.pop_back();
                rets.push_back(newInterval);
            }
            else {
                rets.push_back(intervals[i]);
            }
        }
        return rets;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> intervals({
        {1, 4}, 
        {1, 5}
    });
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.merge(intervals));
    return 0;
}
