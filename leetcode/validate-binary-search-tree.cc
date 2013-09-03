#include <cstdlib>

using namespace std;

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

    TreeNode *prev;

    bool recursive(TreeNode *root) {
        if (!root) return true;
        if (!recursive(root->left)) return false;
        if (prev && prev->val >= root->val) return false; prev = root;
        if (!recursive(root->right)) return false;
        return true;
    }

public:
    bool isValidBST(TreeNode *root) {
        prev = NULL;
        return recursive(root);
    }
};
