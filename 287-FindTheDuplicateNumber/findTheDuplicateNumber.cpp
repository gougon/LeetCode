#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return indexingSort(nums);
    }
private:
    int valueSort(vector<int>& nums) {
        if (nums.size() == 1)
            return -1;

        sort(nums.begin(), nums.end());
        int prev = nums[0], cur;
        for (int i = 1; i < nums.size(); i++) {
            cur = nums[i];
            if (prev == cur)
                return cur;
            prev = cur;
        }

        return -1;
    }

    int indexingSort(vector<int>& nums) {
        if (nums.size() == 1)
            return -1;

        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1])
                    return nums[i];
                swap(&nums[i], &nums[nums[i] - 1]);
                continue;
            }
            i++;
        }

        return -1;
    }

    void swap(int* lhs, int* rhs) {
        int temp = *lhs;
        *lhs = *rhs;
        *rhs = temp;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({1, 3, 4, 2, 2});

    Solution sol = Solution();
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}
