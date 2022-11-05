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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        initBuildInformation(inorder);

        int curIdx = 0;
        TreeNode* root = buildChildren(preorder, curIdx);
        return root;
    }
private:
    unordered_map<int, int> _inorderIdx;
    vector<bool> _visited;

    TreeNode* buildChildren(vector<int>& preorder, int& curIdx) {
        int value = preorder[curIdx];

        TreeNode* newNode = new TreeNode(value);
        int inIdx = _inorderIdx[value];
        _visited[inIdx] = true;
        if (inIdx > 0 && !_visited[inIdx - 1])
            newNode->left = buildChildren(preorder, ++curIdx);
        if (inIdx < preorder.size() - 1 && !_visited[inIdx + 1])
            newNode->right = buildChildren(preorder, ++curIdx);
        return newNode;
    }

    void initBuildInformation(vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            int value = inorder[i];
            _inorderIdx[value] = i;
        }

        _visited = vector<bool>(inorder.size(), false);
    }
};

int main(int argc, char *argv[]) {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol = Solution();
    TreeNode* root = sol.buildTree(preorder, inorder);
    return 0;
}
