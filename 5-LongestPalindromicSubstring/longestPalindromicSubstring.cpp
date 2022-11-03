#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (auto& c: s) {
            t.push_back(c);
            t.push_back('#');
        }

        int n = t.size();
        int maxRight = -1;
        int maxCenter = -1;
        vector<int> p(n);

        for (int i = 0; i < n; i++) {
            int r;
            if (i <= maxRight) {
                int j = maxCenter * 2 - i;
                r = min(p[j], maxRight - i);
                while (i + r < n && i - r >= 0 && t[i + r] == t[i - r]) 
                    r++;
            }
            else {
                r = 0;
                while (i + r < n && i - r >= 0 && t[i + r] == t[i - r])
                    r++;
            }
            p[i] = r - 1;
            if (i + p[i] > maxRight) {
                maxRight = i + p[i];
                maxCenter = i;
            }
        }

        int maxLen = -1;
        int center = -1;
        for (int i = 0; i < n; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        return s.substr(center / 2 - maxLen / 2, maxLen);
    }
};

int main(int argc, char *argv[]) {
    string s = "babad";
    Solution sol = Solution();
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}
