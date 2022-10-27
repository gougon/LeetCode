#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
        int counter = -1;
        bool hasOrange = false;
        
        queue<pair<int, int>> prev, cur;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 2) prev.push({i, j});
                if (grid[i][j] == 1) hasOrange = true;
            }
        }

        if (hasOrange && prev.empty()) return -1;
        if (prev.empty()) return 0;

        while (!prev.empty()) {
            while (!prev.empty()) {
                int x = prev.front().first;
                int y = prev.front().second;
                prev.pop();

                for (int i = 0; i < 4; i++) {
                    int m = x + dir[i].first;
                    int n = y + dir[i].second;

                    if (m >= M || m < 0 || n >= N || n < 0) continue;
                    if (grid[m][n] == 1) {
                        grid[m][n] = 2;
                        cur.push({m, n});
                    }
                }
            }
            prev.swap(cur);
            counter++;
            while (!cur.empty()) cur.pop();
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return counter;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    Solution sol = Solution();
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}
