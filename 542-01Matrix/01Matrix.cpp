#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nr = mat.size(), nc = mat[0].size();
        vector<vector<int>> dist(nr, vector<int>(nc, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int counter = 0;
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            counter++;
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newr = r + dirs[i][0];
                int newc = c + dirs[i][1];
                if (newr >= 0 && newr < nr && newc >= 0 && newc < nc) {
                    if (dist[newr][newc] > dist[r][c] + 1) {
                        dist[newr][newc] = dist[r][c] + 1;
                        q.push({newr, newc});
                    }
                }
            }
        }

        return dist;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> mat({
        {0, 0, 0}, 
        {0, 1, 0}, 
        {1, 1, 1}
    });
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.updateMatrix(mat));
    return 0;
}
