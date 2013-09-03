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

    vector<int> inorder;

    void calcInorder(TreeNode *root) {
        if (!root) return;
        calcInorder(root->left);
        inorder.push_back(root->val);
        calcInorder(root->right);
    }

public:

    bool isSymmetric(TreeNode *root) {
        inorder.clear();
        calcInorder(root);
        int i = 0, j = inorder.size() - 1;
        while (i < j)
            if (inorder[i++] != inorder[j--])
                return false;
        return true;
    }
};
