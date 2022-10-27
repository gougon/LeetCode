#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        int counter = 0;

        vector<pair<int, int>> dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1') {
                    counter++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '2';

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int m = x + dir[k].first;
                            int n = y + dir[k].second;

                            if (m >= M || m < 0 || n >= N || n < 0) continue;

                            if (grid[m][n] == '1') {
                                q.push({m, n});
                                grid[m][n] = '2';
                            }
                        }
                    }
                }
            }
        }

        return counter;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> grid = {
        {'1','1','0','0','1'},
        {'1','1','1','1','1'},
        {'0','0','0','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol = Solution();
    cout << sol.numIslands(grid) << endl;
    return 0;
}
