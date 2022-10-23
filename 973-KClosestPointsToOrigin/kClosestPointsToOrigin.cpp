#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int, int>> dists;
        for (int i = 0; i < n; i++) {
            dists.push_back({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
        }

        vector<vector<int>> ret;
        int kthval = quickSelect(dists, 0, n - 1, k);
        for (auto &dist: dists) {
            if (dist.first <= kthval) 
                ret.push_back(points[dist.second]);
        }
        return ret;
    }

    int quickSelect(vector<pair<int, int>>& dists, int start, int end, int k) {
        int pivot = dists[(start + end) / 2].first;
        int i = start, t = start, j = end;
        while (t <= j) {
            if (dists[t].first < pivot) {
                swap(dists[i], dists[t]);
                i++;
                t++;
            }
            else if (dists[t].first > pivot) {
                swap(dists[t], dists[j]);
                j--;
            }
            else {
                t++;
            }
        }

        if (i - start >= k) return quickSelect(dists, start, i - 1, k);
        else if (t - start >= k) return pivot;
        else return quickSelect(dists, j + 1, end, k - (j - start + 1));
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> mat({
        {3, 3}, 
        {5, -1}, 
        {-2, 4}
    });
    int k = 2;
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.kClosest(mat, k));
    return 0;
}
