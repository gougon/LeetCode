#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                pivot = i;
        }

        if (pivot == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        int j = -1;
        for (int i = pivot + 1; i < n; i++) {
            if (nums[pivot] < nums[i])
                j = i;
        }
        swap(nums, pivot, j);
        reverse(nums, pivot + 1, n - 1);
    }

    void swap (vector<int>& nums, int s, int e) {
        int temp = nums[s];
        nums[s] = nums[e];
        nums[e] = temp;
    }

    void reverse(vector<int>& nums, int s, int e) {
        while (s < e) {
            swap(nums, s, e);
            s++;
            e--;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({3, 2, 1});
    Solution sol = Solution();
    sol.nextPermutation(nums);
    for (auto &n: nums) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
