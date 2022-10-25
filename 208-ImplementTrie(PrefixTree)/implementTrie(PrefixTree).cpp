#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        Node* cur = root;
        for (char& c: word) {
            Node* child = cur->getChild(c);
            if (!child) {
                Node* newNode = new Node(c);
                cur->addChild(newNode);
                child = newNode;
            }
            cur = child;
        }
        cur->isEnd(true);
    }
    
    bool search(string word) {
        Node* cur = root;
        for (char& c: word) {
            Node* child = cur->getChild(c);
            if (!child) return false;
            cur = child;
        }
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char& c: prefix) {
            Node* child = cur->getChild(c);
            if (!child) return false;
            cur = child;
        }
        return true;
    }
private:
    class Node {
    public:
        Node() : _c(' '), _isEnd(false) {}

        Node(char c) : _c(c), _isEnd(false) {}

        ~Node() {
            for (Node* child: _children) 
                delete child;
        }

        char& c() {
            return _c;
        }

        bool& isEnd() {
            return _isEnd;
        }

        void isEnd(bool b) {
            _isEnd = b;
        }

        void addChild(Node* child) {
            _children.push_back(child);
        }

        Node* getChild(char c) {
            for (Node* n: _children) 
                if (n->c() == c) return n;
            return nullptr;
        }
    private:
        char _c;
        bool _isEnd;
        vector<Node*> _children;
    };

    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char *argv[]) {
    return 0;
}
