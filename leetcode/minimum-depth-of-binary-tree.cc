#include <climits>
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
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ret = INT_MAX;
        if (root->left) ret = min(ret, minDepth(root->left));
        if (root->right) ret = min(ret, minDepth(root->right));
        return ret + 1;
    }
};
