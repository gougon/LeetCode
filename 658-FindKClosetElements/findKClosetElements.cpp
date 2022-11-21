#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return binarySearch(arr, k, x);
    }
private:
    vector<int> iteration(vector<int>& arr, int k, int x) {
        queue<pair<unsigned int, int>> diffs;
        for (int i = 0; i < k; i++) 
            diffs.push({abs(arr[i] - x), arr[i]});
        for (int i = k; i < arr.size(); i++) {
            unsigned int diff = abs(arr[i] - x);
            if (diff > diffs.front().first) 
                break;
            else if (diff == diffs.front().first)
                continue;
            diffs.pop();
            diffs.push({diff, arr[i]});
        }

        vector<int> rets;
        while (!diffs.empty()) {
            rets.push_back(diffs.front().second);
            diffs.pop();
        }
        return rets;
    }

    vector<int> binarySearch(vector<int>& arr, int k, int x) {
        int r = lowerBound(arr, x);
        int l = r - 1;
        while (k--) {
            if (r >= arr.size() || l >= 0 && x - arr[l] <= arr[r] - x)
                l--;
            else
                r++;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
private:
    int lowerBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (target > arr[m])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

int main(int argc, char *argv[]) {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = -1;

    Solution sol = Solution();
    Utils<int>::printVector(sol.findClosestElements(arr, k, x));
    return 0;
}
