#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>(); 
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (node->neighbors.empty()) return new Node(node->val);

        vector<Node*> newNodes;
        vector<Node*> cur({node}), next;
        unordered_map<int, Node*> visited;
        while (!cur.empty()) {
            for (Node* n: cur) {
                if (visited.find(n->val) != visited.end()) continue;
                Node* nn = new Node(n->val, n->neighbors);
                newNodes.push_back(nn);
                visited.insert({n->val, nn});
                next.insert(next.end(), n->neighbors.begin(), n->neighbors.end());
            }
            cur.swap(next);
            next.clear();
        }
        for (Node* n: newNodes) {
            vector<Node*> neighbors;
            for (Node* neighbor: n->neighbors) 
                neighbors.push_back(visited[neighbor->val]);
            n->neighbors = neighbors;
        }
        return newNodes[0];
    }
};

int main(int argc, char *argv[]) {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};
    Solution sol = Solution();
    Node* nn = sol.cloneGraph(node1);
    return 0;
}
