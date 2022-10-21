#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void result(int n, int complete, int nLeft, string output, vector<string> *ans) {
        if (complete == n) {
            ans->push_back(output);
            return;
        }

        if (nLeft + complete != n) {
            output.push_back('(');
            result(n, complete, nLeft + 1, output, ans);
            output.pop_back();

        }
        if (nLeft != 0) {
            output.push_back(')');
            result(n, complete + 1, nLeft - 1, output, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string output;
        vector<string> ans;
        result(n, 0, 0, output, &ans);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    int n = stoi(argv[1]);
    Solution sol = Solution();
    vector<string> combs = sol.generateParenthesis(n);
    for (string &s: combs) {
        cout << s << endl;
    }
    return 0;
}
