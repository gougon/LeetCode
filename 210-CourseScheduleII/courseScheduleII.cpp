#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p: prerequisites) 
            graph[p[1]].push_back(p[0]);

        vector<int> status(numCourses, 0);
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (!DFS(i, graph, status, ans))
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool DFS(int cur, vector<vector<int>>& graph, vector<int>& status, vector<int>& ans) {
        if (status[cur] == 1) 
            return false;
        if (status[cur] == 2)
            return true;

        status[cur] = 1;

        vector<int> course = graph[cur];
        for (int i = 0; i < course.size(); i++) {
            if (!DFS(course[i], graph, status, ans))
                return false;
        }

        status[cur] = 2;
        ans.push_back(cur);
        return true;
    }
};

int main(int argc, char *argv[]) {
    int numCourses = 4;
    vector<vector<int>> prerequisites({
        {1, 0}, 
        {2, 0}, 
        {3, 1}, 
        {3, 2}
    });

    Solution sol = Solution();
    Utils<int>::printVector(sol.findOrder(numCourses, prerequisites));
    return 0;
}
