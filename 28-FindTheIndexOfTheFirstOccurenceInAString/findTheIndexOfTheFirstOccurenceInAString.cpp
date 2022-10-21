#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;

        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int j = 0;
            for (; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == needle.length())
                return i;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    string haystack = argv[1];
    string needle = argv[2];
    Solution sol = Solution();
    cout << haystack << ", " << needle << endl;
    cout << sol.strStr(haystack, needle) << endl;
    return 0;
}
