#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob = nums[0], norob = 0;

        for (int i = 1; i < nums.size(); i++) {
            int norobTemp = norob, robTemp = rob;
            norob = max(norobTemp, robTemp);
            rob = norobTemp + nums[i];
        }

        return max(rob, norob);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({0});

    Solution sol = Solution();
    cout << sol.rob(nums) << endl;
    return 0;
}
