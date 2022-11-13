#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
    TrieNode(char val) : _val(val), _isEnd(false), _children(vector<TrieNode*>(26, nullptr)) {}

    ~TrieNode() {
        for (auto& child: _children)
            delete child;
    }

    bool isEnd() {
        return _isEnd;
    }

    void setEnd() {
        _isEnd = true;
    }

    bool hasChild(char c) {
        int idx = c - 'a';
        return _children[idx] != nullptr;
    }

    void addChild(char c) {
        if (hasChild(c))
            return;
        int idx = c - 'a';
        _children[idx] = new TrieNode(c);
    }

    TrieNode* getChild(char c) {
        return _children[c - 'a'];
    }
private:
    char _val;
    bool _isEnd;
    vector<TrieNode*> _children;
};

class WordDictionary {
public:
    WordDictionary() {
        _root = new TrieNode(' ');
    }
    
    void addWord(string word) {
        TrieNode* cur = _root;
        for (auto& c: word) {
            if (!cur->hasChild(c)) 
                cur->addChild(c);
            cur = cur->getChild(c);
        }
        cur->setEnd();
    }
    
    bool search(string word) {
        return _find(word, 0, _root);
    }
private:
    TrieNode* _root;

    bool _find(string word, int length, TrieNode* node) {
        if (node == nullptr) 
            return false;
        if (word.size() == length)
            return node->isEnd();
        
        bool isFind = false;
        char c = word[length];
        if (c == '.') {
            for (int i = 0; i < 26 && !isFind; i++) {
                isFind = _find(word, length + 1, node->getChild('a' + i));
            }
        }
        else {
            isFind = _find(word, length + 1, node->getChild(c));
        }
        return isFind;
    }
};

int main(int argc, char *argv[]) {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl;
    cout << obj->search("bad") << endl;
    cout << obj->search(".ad") << endl;
    cout << obj->search("b..") << endl;
    return 0;
}
