#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> fatherMap;
        unordered_map<string, string> email2Person;
        unordered_map<string, set<string>> emailTree;
        for (auto account: accounts) {
            string name = account[0];
            string root = account[1];
            
            email2Person[root] = name;

            if (fatherMap.find(root) == fatherMap.end())
                fatherMap[root] = root;

            for (int i = 2; i < account.size(); i++) {
                string email = account[i];
                if (fatherMap.find(email) == fatherMap.end())
                    fatherMap[email] = root;

                if (FindRoot(fatherMap, email) != FindRoot(fatherMap, root)) 
                    Union(fatherMap, email, root);
            }       
        }

        for (auto x: fatherMap) {
            string email = x.first;
            string root = FindRoot(fatherMap, email);
            emailTree[root].insert(email);
        }

        vector<vector<string>> rets;
        for (auto tree: emailTree) {
            string root = tree.first;
            set<string> children = tree.second;
            string name = email2Person[root];
            vector<string> ret({name});
            for (auto child: children)
                ret.push_back(child);
            rets.push_back(ret);
        }
        return rets;
    }
private:
    string FindRoot(unordered_map<string, string>& fatherMap, string child) {
        if (fatherMap[child] == child) return child;

        string root = FindRoot(fatherMap, fatherMap[child]);
        fatherMap[child] = root;
        return root;
    }

    void Union(unordered_map<string, string>& fatherMap, string lhs, string rhs) {
        lhs = fatherMap[lhs];
        rhs = fatherMap[rhs];
        if (lhs < rhs)
            fatherMap[rhs] = lhs;
        else
            fatherMap[lhs] = rhs;
    }
};

int main() {
    vector<vector<string>> accounts({
        {"David","David0@m.co","David4@m.co","David3@m.co"}, 
        {"David","David5@m.co","David5@m.co","David0@m.co"}, 
        {"David","David1@m.co","David4@m.co","David0@m.co"}, 
        {"David","David0@m.co","David1@m.co","David3@m.co"}, 
        {"David","David4@m.co","David1@m.co","David3@m.co"}
    });

    Solution sol = Solution();
    Utils<string>::printNestedVector(sol.accountsMerge(accounts));
    return 0;
}
