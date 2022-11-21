#include <iostream>
#include <bits/stdc++.h>

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
    int widthOfBinaryTree(TreeNode* root) {
        root->val = 1;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 1});
        int ret = 1;
        while (!q.empty()) {
            int n = q.size();
            int base = q.front().second;
            int mn, mx;
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, long> node = q.front();
                q.pop();

                if (i == 0)
                    mn = node.second;
                if (i == n - 1)
                    mx = node.second;

                if (node.first->left) {
                    q.push({node.first->left, (node.second - base) * 2 + 1});
                }
                if (node.first->right) {
                    q.push({node.first->right, (node.second - base) * 2 + 2});
                }
            }
            ret = max(ret, mx - mn + 1);
        }
        return ret;
    }
};
