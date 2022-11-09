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
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return -1;

        kthSmallest(root->left, k);
        if (_val.size() == k)
            return _val.top();
        _val.push(root->val);
        kthSmallest(root->right, k);

        return _val.top();
    }
private:
    stack<int> _val;
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(6);

    int k = 3;

    Solution sol = Solution();
    cout << sol.kthSmallest(root, k) << endl;
    return 0;
}
