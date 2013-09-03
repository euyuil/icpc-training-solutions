#include <cmath>
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

    bool isBalancedWithDepth(TreeNode *root, int &depth) {

        if (!root) {
            depth = 0;
            return true;
        }

        int leftDepth, rightDepth;
        bool leftBalanced, rightBalanced;

        leftBalanced = isBalancedWithDepth(root->left, leftDepth);
        rightBalanced = isBalancedWithDepth(root->right, rightDepth);

        depth = max(leftDepth, rightDepth) + 1;

        return leftBalanced &&
               rightBalanced &&
               abs(leftDepth - rightDepth) <= 1;
    }

public:

    bool isBalanced(TreeNode *root) {
        int depth;
        return isBalancedWithDepth(root, depth);
    }
};
