#include <algorithm>

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

    TreeNode *flattenAndGetDeepestOne(TreeNode *root) {

        if (!root) return NULL;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = NULL;
        root->right = NULL;

        TreeNode *curr = root;

        if (left) {
            curr->right = left;
            curr = flattenAndGetDeepestOne(left);
        }

        if (right) {
            curr->right = right;
            curr = flattenAndGetDeepestOne(right);
        }

        return curr;
    }

public:
    void flatten(TreeNode *root) {
        flattenAndGetDeepestOne(root);
    }
};
