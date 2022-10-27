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
    bool isValidBST(TreeNode* root) {
        return validateSubtree(root, LONG_MIN, LONG_MAX);
    }
private:
    bool validateSubtree(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true;

        if (node->val <= minVal || node->val >= maxVal) return false;

        return validateSubtree(node->left, minVal, node->val) && 
            validateSubtree(node->right, node->val, maxVal);
    }
};

int main(int argc, char *argv[]) {
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;
    TreeNode* root = new TreeNode(INT_MIN);
    root->right = new TreeNode(INT_MAX);
    Solution sol = Solution();
    cout << sol.isValidBST(root) << endl;
    return 0;
}
