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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(root, ans, 0);
        return ans;
    }
private:
    vector<vector<int>> BFS(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        vector<TreeNode*> curr({root}), next;
        while (!curr.empty()) {
            vector<int> level;
            for (TreeNode* n: curr) {
                if (n->left) next.push_back(n->left);
                if (n->right) next.push_back(n->right);
                level.push_back(n->val);
            }
            ans.push_back(level);
            curr.swap(next);
            next.clear();
        }
        return ans;
    }

    void DFS(TreeNode* root, vector<vector<int>>& ans, int depth) {
        if (!root)
            return;

        while (ans.size() <= depth)
            ans.push_back({});
        DFS(root->left, ans, depth + 1);
        DFS(root->right, ans, depth + 1);
        ans[depth].push_back(root->val);
        return;
    }
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.levelOrder(root));
    return 0;
}
