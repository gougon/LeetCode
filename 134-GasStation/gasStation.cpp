#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int start = 0;
        int cur = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            cur += (gas[i] - cost[i]);

            if (cur < 0) {
                start = i + 1;
                cur = 0;
            }

            total += (gas[i] - cost[i]);
        }

        return total < 0 ? -1 : start;
    }
};

int main(int argc, char *argv[]) {
    vector<int> gas({1, 2, 3, 4,5});
    vector<int> cost({3, 4, 5, 1, 2});

    Solution sol = Solution();
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
