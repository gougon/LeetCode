#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) { // 0, 1, 2
        int n = nums.size(); // 1 ~ 300
        /*
        from left to right, 
        use 1 variable to store 0 position, called zeroPos
        ex. 001200011120221
              v
        use 1 variable to store 1 position, called onePos
        ex. 001111200011120221
                  v
        
        if meet 0 : swap zeroPos with 0
                    zeroPos++
                    if zeroPos > onePos : onePos++;
        if meet 1 : swap onePos with 1
                    onePos++

        012012012
        000111222
        222111000
        210210210
        001110000221
        0011100002

        0 1 2 0 1 2 0 1 2
        zo
        '0' 1 2 0 1 2 0 1 2
            zo
        0 '1' 2 0 1 2 0 1 2
          z   o
        0 1 '2' 0 1 2 0 1 2
          z o
        0 0 2 '1' 1 2 0 1 2
            zo
        0 0 1 '2' 1 2 0 1 2
            z o
        0 0 1 '2' 1 2 0 1 2
            z o
        0 0 1 1 '2' 2 0 1 2
            z   o
        0 0 1 1 '2' 2 0 1 2
            z   o
        0 0 1 1 2 '2' 0 1 2
            z   o
        0 0 0 1 2 2 '1' 1 2
              z o
        0 0 0 1 1 2 '2' 1 2
              z   o
        0 0 0 1 1 2 '2' 1 2
              z   o
        0 0 0 1 1 1 2 '2' 2
              z     o
        0 0 0 1 1 1 2 '2' 2
              z     o
        0 0 0 1 1 1 2 2 '2'
              z     o
        */
        int* zeroPos = &nums[0];
        int* onePos = &nums[0];

        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                if (zeroPos != &nums[i])
                    swap(zeroPos, &nums[i]);
                else
                    i++;
                if (++zeroPos > onePos)
                    onePos++;
            }
            else if (nums[i] == 1) {
                if (onePos != &nums[i])
                    swap(onePos, &nums[i]);
                else
                    i++;
                onePos++;
            }
            else {
                i++;
            }
        }
    }
private:
    void swap(int* a, int* b) {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
};

int main() {
    vector<int> nums({1, 2});
    Solution sol = Solution();
    sol.sortColors(nums);
    Utils<int>::printVector(nums);
    return 0;
}
