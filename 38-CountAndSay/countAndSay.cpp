#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string s = countAndSay(n - 1);
        string ans = "";
        int counter = 0;
        char target = s[0];
        for (char &c: s) {
            if (c == target) {
                counter++;
                continue;
            }
            ans += to_string(counter) + target;
            target = c;
            counter = 1;
        }
        ans += to_string(counter) + target;
        return ans;
    }
};

int main(int argc, char *argv[]) {
    int n = 6;
    Solution sol = Solution();
    cout << sol.countAndSay(n) << endl;
    return 0;
}
