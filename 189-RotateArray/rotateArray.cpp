#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0 || k % n == 0 || n == 1)
            return;
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        int* p1 = &nums[start];
        int* p2 = &nums[end];
        while (p1 < p2) 
            swap(*p1++, *p2--);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 2, 3, 4, 5, 6});
    int k = 4;

    Solution sol = Solution();
    sol.rotate(nums, k);
    Utils<int>::printVector(nums);
    return 0;
}
