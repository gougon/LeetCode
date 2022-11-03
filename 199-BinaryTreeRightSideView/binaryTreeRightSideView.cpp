#include <iostream>
#include <bits/stdc++.h>
#include "../utils/Utils.cpp"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        /*
        Traversal from right to left
        Record maxDepth
        If curNode's depth > maxDepth, add to ans
        */
       _maxDepth = -1;
       Traversal(root, 0);
       return _rSide;
    }
private:
    vector<int> _rSide;
    int _maxDepth;

    void Traversal(TreeNode* root, int depth) {
        if (!root) return;

        if (depth > _maxDepth) {
            _rSide.push_back(root->val);
            _maxDepth = depth;
        }

        Traversal(root->right, depth + 1);
        Traversal(root->left, depth + 1);
    }
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    Solution sol = Solution();
    Utils<int>::printVector(sol.rightSideView(root));
    return 0;
}
