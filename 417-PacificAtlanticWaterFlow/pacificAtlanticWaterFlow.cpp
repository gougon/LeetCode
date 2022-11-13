#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
        Transform question: If a grid cell can spread to left/top or right/bottom, then mark it.
        For each cell, do BFS, it will take O(n^2)

        Who both dominate left/top and right/bottom?
        from LT / RB do reverse BFS, then find UNION

        edge case : right top & left bottom

        pseudo code:
        array: LT
        array: RB
        for each gridCell in left / top:
            BFS();
        for each gridCell in right / bottom:
            BFS();
        findUnion(LT, RB)
        */
        const int H = heights.size();
        const int W = heights[0].size();
        vector<pair<int, int>> LTIdx, RBIdx;
        _buildBoundaries(LTIdx, RBIdx, H, W);

        vector<vector<bool>> LT(H, vector<bool>(W, false)), RB(H, vector<bool>(W, false));
        _BFS(heights, H, W, LT, LTIdx);
        _BFS(heights, H, W, RB, RBIdx);
        vector<vector<int>> rets = _intersect(LT, RB);
        return rets;
    }
private:
    void _buildBoundaries(vector<pair<int, int>>& LTIdx, vector<pair<int, int>>& RBIdx, int H, int W) {
        for (int h = 0; h < H; h++) {
            LTIdx.push_back({h, 0});
            RBIdx.push_back({h, W - 1});
        }
        for (int w = 1; w < W; w++) {
            LTIdx.push_back({0, w});
            RBIdx.push_back({H - 1, (W - 1) - w});
        }
    }

    void _BFS(vector<vector<int>> heights, const int H, const int W, vector<vector<bool>>& spread, vector<pair<int, int>>& boundaryIdx) {
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (auto& bIdx: boundaryIdx) {
            q.push(bIdx);
            while (!q.empty()) {
                int h = q.front().first;
                int w = q.front().second;
                q.pop();
                if (spread[h][w])
                    continue;
                spread[h][w] = true;
                for (auto dir: dirs) {
                    int hNew = h + dir.first;
                    int wNew = w + dir.second;
                    if (hNew >= H || hNew < 0 || wNew >= W || wNew < 0)
                        continue;
                    if (heights[hNew][wNew] < heights[h][w]) 
                        continue;
                    q.push({hNew, wNew});
                }
            }
        }
    }

    vector<vector<int>> _intersect(vector<vector<bool>>& LT, vector<vector<bool>>& RB) {
        vector<vector<int>> intersects;
        for (int i = 0; i < LT.size(); i++) {
            for (int j = 0; j < LT[0].size(); j++) {
                if (LT[i][j] && RB[i][j])
                    intersects.push_back({i, j});
            }
        }
        return intersects;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> heights({
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    });

    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.pacificAtlantic(heights));
    return 0;
}
