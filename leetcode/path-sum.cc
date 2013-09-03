/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    int target;

    bool recursive(TreeNode *root, int parentSum) {

        if (!root)
            return false;

        int sum = parentSum + root->val;
        bool isleaf = (!root->left && !root->right);

        if (isleaf && sum == target)
            return true;

        if (recursive(root->left, sum)) return true;
        if (recursive(root->right, sum)) return true;

        return false;
    }

public:

    bool hasPathSum(TreeNode *root, int sum) {
        this->target = sum;
        return recursive(root, 0);
    }
};
