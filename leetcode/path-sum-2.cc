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
    vector<vector<int> > ret;
    vector<int> curr;

    void recursive(TreeNode *root, int parentSum) {

        if (!root) return;

        curr.push_back(root->val);

        int sum = parentSum + root->val;
        bool isleaf = (!root->left && !root->right);

        if (isleaf && sum == target) {
            ret.push_back(curr);
        }

        recursive(root->left, sum);
        recursive(root->right, sum);

        curr.pop_back();
    }

public:

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        this->target = sum;
        this->ret.clear();
        recursive(root, 0);
        return this->ret;
    }
};
