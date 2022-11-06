#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> candidates;
        for (auto& c: p)
            candidates[c] += 1;

        int start = 0;
        unordered_map<char, int> anagram;
        vector<int> ret;
        for (int i = 0; i < s.size(); i++) {
            char cur = s[i];

            anagram[cur] += 1;
            if (i >= p.size()) {
                char head = s[i - p.size()];
                anagram[head] -= 1;
                if (anagram[head] == 0)
                    anagram.erase(head);
            }

            if (anagram == candidates) 
                ret.push_back(i - (p.size() - 1));
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    string s = "aeebacbabc";
    string p = "abc";
    Solution sol = Solution();
    Utils<int>::printVector(sol.findAnagrams(s, p));
    return 0;
}
