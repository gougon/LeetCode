#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string prefix = "([{";
        string postfix = ")]}";
        unordered_map<char, char> hashMap = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        stack<char> myStack;
        for (char &c: s) {
            if (prefix.find(c) != string::npos) {
                // c is in prefix
                myStack.push(c);
            }
            else {
                // c is in postfix
                if (myStack.empty())
                    return false;
                else if (hashMap[myStack.top()] == c)
                    myStack.pop();
                else
                    return false;
            }
        }

        return myStack.empty();
    }
};

int main(int argc, char *argv[]) {
    string s = "([{}])";
    Solution sol = Solution();
    cout << sol.isValid(s) << endl;
    return 0;
}
