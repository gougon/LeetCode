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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> candidate;
        DFS(root, ans, candidate, targetSum, 0);
        return ans;
    }
private:
    void DFS(TreeNode* node, vector<vector<int>>& ans, vector<int>& candidate, int targetSum, int curSum) {
        if (!node)
            return;
        
        curSum += node->val;

        candidate.push_back(node->val);
        DFS(node->left, ans, candidate, targetSum, curSum);
        DFS(node->right, ans, candidate, targetSum, curSum);
        if (curSum == targetSum && !node->left && !node->right)
            ans.push_back(candidate);
        candidate.pop_back();
    }
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    int targetSum = 22;

    Solution sol = Solution();
    Utils<int>::printNestedVector(sol.pathSum(root, targetSum));
    return 0;
}
