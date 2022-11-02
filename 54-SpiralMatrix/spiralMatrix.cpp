#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cycle = 0;
        bool flag = true;

        vector<int> ret;
        int dir = 1;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        while(ret.size() < n * m) {
            switch(dir) {
            case 1:
                for (int i  = left; i <= right; i++) 
                    ret.push_back(matrix[top][i]);
                top++;
                dir = 2;
                break;
            case 2:
                for (int i = top; i <= bottom; i++) 
                    ret.push_back(matrix[i][right]);
                right--;
                dir = 3;
                break;
            case 3:
                for (int i = right; i >= left; i--)
                    ret.push_back(matrix[bottom][i]);
                bottom--;
                dir = 4;
                break;
            case 4:
                for (int i = bottom; i >= top; i--)
                    ret.push_back(matrix[i][left]);
                left++;
                dir = 1;
                break;
            default:
                break;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix1 = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };
    vector<vector<int>> matrix2 = {
        {1, 2, 3}, 
        {4, 5, 6}
    };
    vector<vector<int>> matrix3 = {
        {1, 2}, 
        {4, 5}, 
        {7, 8}
    };
    vector<vector<int>> matrix4 = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}, 
        {10, 11, 12}
    };
    vector<vector<int>> matrix5 = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };
    Solution solution = Solution();
    Utils<int>::printVector(solution.spiralOrder(matrix5));
    return 0;
}
