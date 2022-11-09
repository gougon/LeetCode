#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> rets(n, 0);
        stack<int> waits;
        for (int i = 0; i < n; i++) {
            while (!waits.empty() && temperatures[i] > temperatures[waits.top()]) {
                int idx = waits.top();
                rets[idx] = i - idx;
                waits.pop();
            }

            waits.push(i);
        }
        return rets;
    }
};

int main(int argc, char *argv[]) {
    vector<int> temperatures({1, 2, 5, 5, 3, 4, 3, 2, 5, 6, 1});

    Solution sol = Solution();
    Utils<int>::printVector(sol.dailyTemperatures(temperatures));
    return 0;
}
