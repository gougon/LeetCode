#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Node {
public:
    Node(char val) {
        val = val;
    }

    ~Node() {
        for (auto& node: _children)
            delete node.second;
    }

    bool hasChild(char& c) {
        return _children.find(c) != _children.end();
    }

    Node* getChild(char& c) {
        if (!hasChild(c))
            throw invalid_argument("No such child");
        return _children[c];
    }

    void addChild(char& c) {
        _children[c] = new Node(c);
    }

    bool isEnd() {
        return _isEnd;
    }
    
    void setEnd() {
        _isEnd = true;
    }
private:
    char _val;
    unordered_map<char, Node*> _children;
    bool _isEnd = false;
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Divide each string to a hashmap
        So i will have a set of hashmap, each represent a string
        If i have N strs, i need to compare N times for each string, its TC = O(n^2)

        Another approach is sorting each string, it will takes TC = O(nmlogm + n^2)

        If i sort each string, then use prefix-tree, it will take TC = O(nlogm + 26^m) -> use vector to store children
        But if i use hashmap to store children, it will take TC = O(nmlogm + nm)

        Accordin to sort each string, if i use hashmap to store sort-string, then compare each str, 
        it will take TC = O(nmlogm + n)
        */

        return way2(strs);
    }

    vector<vector<string>> way1(vector<string>& strs) {
        /*
        psuedo code:
        class Node 
            char val
            hashmap children
            bool isEnd

        originStrs : copy(strs)
        sort(strs)
        Node : root
        hashmap : container
        for each s in strs:
            if traversal(root, s):
                insert originStrs[i] into hashmap[s]
            else:
                init hashmap[s] with originStrs[i]

        traversal(Node node, string s) 
            Node cur : node
            int sIdx : 0
            while sIdx < len(s):
                if !cur.hasChild(s[sIdx]):
                    cur.addChild(s[sIdx])
                cur = cur.getChild(s[sIdx]);
            if cur.isEnd():
                return true
            cur.setEnd()
            return false
        */
        vector<string> originStrs;
        for (int i = 0; i < strs.size(); i++) {
            originStrs.push_back(strs[i]);
            sort(strs[i].begin(), strs[i].end());
        }
        Node* root = new Node(' ');
        unordered_map<string, vector<string>> container;

        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "") {
                container[""].push_back("");
                continue;
            }

            if (traversal(root, strs[i]))
                container[strs[i]].push_back(originStrs[i]);
            else
                container[strs[i]] = vector<string>({originStrs[i]});
        }

        vector<vector<string>> rets;
        for (auto& candidate: container) 
            rets.push_back(candidate.second);
        return rets;
    }
    
    vector<vector<string>> way2(vector<string>& strs) {
        vector<string> originStrs;
        for (int i = 0; i < strs.size(); i++) {
            originStrs.push_back(strs[i]);
            sort(strs[i].begin(), strs[i].end());
        }
        unordered_map<string, vector<string>> container;

        for (int i = 0; i < strs.size(); i++) {
            if (container.find(strs[i]) == container.end())
                container[strs[i]] = vector<string>({originStrs[i]});
            else
                container[strs[i]].push_back(originStrs[i]);
        }

        vector<vector<string>> rets;
        for (auto& candidate: container)
            rets.push_back(candidate.second);
        return rets;
    }
private:
    bool traversal(Node* node, string& s) {
        Node* cur = node;
        int sIdx = 0;
        while (sIdx < s.size()) {
            if (!cur->hasChild(s[sIdx]))
                cur->addChild(s[sIdx]);
            cur = cur->getChild(s[sIdx]);
            sIdx++;
        }
        if (cur->isEnd())
            return true;
        cur->setEnd();
        return false;
    } 
};

int main(int argc, char *argv[]) {
    vector<string> strs({""});

    Solution sol = Solution();
    Utils<string>::printNestedVector(sol.groupAnagrams(strs));
    return 0;
}
