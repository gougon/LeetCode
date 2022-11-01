#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p->val == root->val || q->val == root->val) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left && right) return right;
        else if (left && !right) return left;
        else if (!left && !right) return NULL;
        else return root;
    }
private:
};

int main() {
    TreeNode* head = new TreeNode(-1);
    head->left = new TreeNode(0);
    head->left->left = new TreeNode(-2);
    head->left->right = new TreeNode(4);
    head->left->left->left = new TreeNode(8);
    head->right = new TreeNode(3);

    Solution sol = Solution();
    cout << sol.lowestCommonAncestor(head, new TreeNode(8), new TreeNode(4))->val << endl;
    return 0;
}
