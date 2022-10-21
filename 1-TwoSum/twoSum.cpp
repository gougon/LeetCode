#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void PrintHash(unordered_map<int, int> hash);
void PrintLine(vector<int>& nums);

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> summand;
        unordered_map<int, int>::iterator it;
        for (long unsigned int i = 0; i < nums.size(); i++) {
            it = summand.find(target - nums[i]);
            if (it != summand.end())
                return vector<int> { static_cast<int>(i), it->second };
            summand.insert(make_pair(nums[i], i));
        }
        return {};
    }
};

void PrintLine(vector<int>& nums)
{
    for (long unsigned int  i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
    cout << '\n';
}

int main(int argc, char *argv[])
{
    int target = atoi(argv[1]);
    vector<int> nums;
    for (int i = 2; i < argc; i++)
        nums.push_back(atoi(argv[i]));
    Solution s;
    vector<int> result = s.twoSum(nums, target);
    PrintLine(result);
    return 0;
}
