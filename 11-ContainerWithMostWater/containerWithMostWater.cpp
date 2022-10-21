#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (right > left) {
            int w = right - left;
            int h = min(height[right], height[left]);
            int area = w * h;
            maxArea = max(area, maxArea);
            if (height[right] > height[left]) left++;
            else if (height[right] < height[left]) right--;
            else {
                left++;
                right--;
            }
        }
        return maxArea;
    }
};

int main()
{
    // 1, 8, 6, 2, 5, 4, 8, 3, 7
    // 1, 0, 0, 0, 0, 0, 0, 2, 2
    // 2, 3, 10, 5, 7, 8, 9
    // 2, 3, 4, 5, 18, 17, 6
    // 1, 8, 100, 2, 100, 4, 8, 3, 7
    vector<int> height({1, 8, 6, 2, 5, 4, 8, 3, 7});
    Solution s = Solution();
    cout << s.maxArea(height) << endl;
    return 0;
}
