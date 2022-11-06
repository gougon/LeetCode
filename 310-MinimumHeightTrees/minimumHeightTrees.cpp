#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};

        // Find neighbors & leaves
        vector<vector<int>> neighbors(n);
        vector<int> nodesCounter(n, 0);
        for (auto& edge: edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);

            nodesCounter[edge[0]]++;
            nodesCounter[edge[1]]++;
        }

        // From leaves, BFS to find middle
        // middle is root
        queue<int> nodes;
        for (int i = 0; i < n; i++) {
            if (nodesCounter[i] == 1) 
                nodes.push(i);
        }

        int count = 0;
        vector<int> visited(n, 0);
        while (!nodes.empty()) {
            int len = nodes.size();
            while (len--) {
                int node = nodes.front();
                nodes.pop();
                count++;
                visited[node] = 1;
                for (auto neighbor: neighbors[node]) {
                    nodesCounter[neighbor]--;
                    if (nodesCounter[neighbor] == 1)
                        nodes.push(neighbor);
                }
            }

            if (count == n - 1 || count == n - 2)
                break;
        }

        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                ret.push_back(i);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    int n = 7;
    vector<vector<int>> edges({
        {0,1},
        {1,2},
        {1,3},
        {2,4},
        {3,5},
        {4,6}
    });
    Solution sol = Solution();
    Utils<int>::printVector(sol.findMinHeightTrees(n, edges));
    return 0;
}
