#include <iostream>
#include <bits/stdc++.h>

using namespace std;

# define ll long long

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> optr{"+", "-", "*", "/"};
        stack<ll> s;
        for (string& token: tokens) {
            bool isOptr = optr.count(token);
            if (!isOptr) {
                s.push(atoi(token.c_str()));
            }
            else {
                ll right = s.top();
                s.pop();
                ll left = s.top();
                s.pop();
                if (token == "+")
                    s.push(left + right);
                else if (token == "-")
                    s.push(left - right);
                else if (token == "*")
                    s.push(left * right);
                else if (token == "/")
                    s.push(left / right);
            }
        }
        return s.top();
    }
};

int main(int argc, char *argv[]) {
    vector<string> tokens({"4","13","5","/","+"});
    Solution sol = Solution();
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}
