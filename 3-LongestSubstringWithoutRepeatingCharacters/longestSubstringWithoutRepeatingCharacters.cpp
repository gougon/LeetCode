#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> uniques;
        int start = 0, counter = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (uniques.find(c) == uniques.end() || uniques[c] < start) {
                counter++;
            }
            else {
                maxLen = max(counter, maxLen);
                counter = i - uniques[c];
                start = uniques[c] + 1;
            }
            uniques[c] = i;
        }
        maxLen = max(counter, maxLen);
        return maxLen;
    }
};

int main(int argc, char *argv[]) {
    string s = "dvdc";
    Solution sol = Solution();
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
