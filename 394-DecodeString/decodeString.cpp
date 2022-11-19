#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        /*
        Use a stack to store all the element, 
        if i meet ']', pop until we met '[', and store these characters as a string
        */
        stack<char> encodeString;
        for (auto& c: s) {
            if (c != ']')
                encodeString.push(c);
            else {
                vector<char> temp;
                while (encodeString.top() != '[') {
                    temp.push_back(encodeString.top());
                    encodeString.pop();
                }
                encodeString.pop();

                int times = 0, multiply = 1;
                while (!encodeString.empty() && encodeString.top() >= '0' && encodeString.top() <= '9') {
                    times += (encodeString.top() - '0') * multiply;
                    multiply *= 10;
                    encodeString.pop();
                }

                for (int i = 0; i < times; i++) {
                    for (int j = temp.size() - 1; j >= 0; j--)
                        encodeString.push(temp[j]);
                }
            }
        }

        string ret;
        while (!encodeString.empty()) {
            ret.push_back(encodeString.top());
            encodeString.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, char *argv[]) {
    string s = "a1[10[b]]";
    Solution sol = Solution();
    cout << sol.decodeString(s) << endl;
    return 0;
}
