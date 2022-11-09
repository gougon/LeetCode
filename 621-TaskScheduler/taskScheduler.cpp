#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;

        unordered_map<char, int> tasksCount;
        for (auto& task: tasks) 
            tasksCount[task]++;

        priority_queue<int> orderTasks;
        for (auto& task: tasksCount)
            orderTasks.push(task.second);

        int interval = 0;
        vector<int> temp;
        while (!orderTasks.empty()) {
            int k = min(n, int(orderTasks.size()));
            for (int i = 0; i < k; i++) {
                int freq = orderTasks.top();
                if (--freq > 0) 
                    temp.push_back(freq);
                orderTasks.pop();
            }

            interval += (temp.size() == 0) ? k : n;

            for (auto& t: temp) 
                orderTasks.push(t);
            temp.clear();
        }
        return interval;
    }
};

int main(int argc, char *argv[]) {
    vector<char> tasks({
        'A',
        'A',
        'A',
        'B',
        'B',
        'B',
        'C',
        'C',
        'C',
        'D',
        'D',
        'E'
    });
    int n = 2;
    Solution sol = Solution();
    cout << sol.leastInterval(tasks, n) << endl;
    return 0;
}