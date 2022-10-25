#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        _graph = vector<vector<int>>(numCourses);
        for (vector<int>& p: prerequisites) {
            _graph[p[0]].push_back(p[1]);
        }

        vector<status> nodeStatus(numCourses, unknown);
        for (int i = 0; i < numCourses; i++) {
            if (!DFS(i, nodeStatus)) return false;
        }

        return true;
    }
private:
    enum status {
        unknown, 
        visiting, 
        visited
    };
    vector<vector<int>> _graph;

    bool DFS(int course, vector<status>& nodeStatus) {
        if (nodeStatus[course] == visiting) return false;
        if (nodeStatus[course] == visited) return true;

        nodeStatus[course] = visiting;
        for (int& neighbor: _graph[course]) {
            if (!DFS(neighbor, nodeStatus)) return false;
        }
        nodeStatus[course] = visited;

        return true;
    }
};

int main(int argc, char *argv[]) {
    int numCourses = 4;
    vector<vector<int>> prerequisites({
        {0, 1}, 
        {2, 3}, 
        {1, 2}
    });
    Solution sol = Solution();
    cout << sol.canFinish(numCourses, prerequisites) << endl;
    return 0;
}
