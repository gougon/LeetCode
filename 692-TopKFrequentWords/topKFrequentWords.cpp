#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Compare {
public:
    bool operator()(pair<string, int>& lhs, pair<string, int>& rhs) {
        if (lhs.second == rhs.second) 
            return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        /*
        I can use a hashmap to store these words, then i can get m pairs (word, times).
        if i use a array with size k to consquently store max k pairs, 
        i need to maintain a priority queue with size k
        */
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> kFrequent;
        unordered_map<string, int> wordTimes;

        for (auto& word: words) 
            wordTimes[word] += 1;

        for (auto& wordTime: wordTimes) {
            kFrequent.push(wordTime);
            if (kFrequent.size() > k)
                kFrequent.pop();
        }

        vector<string> rets;
        while (!kFrequent.empty()) {
            rets.push_back(kFrequent.top().first);
            kFrequent.pop();
        }
        reverse(rets.begin(), rets.end());
        return rets;
    }
};

int main(int argc, char *argv[]) {
    vector<string> words({"a", "a", "i","love","leetcode","i","love","coding"});
    int k =2;

    Solution sol = Solution();
    Utils<string>::printVector(sol.topKFrequent(words, k));
    return 0;
}
