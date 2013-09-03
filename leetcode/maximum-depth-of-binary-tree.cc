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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ret = INT_MIN;
        if (root->left) ret = max(ret, maxDepth(root->left));
        if (root->right) ret = max(ret, maxDepth(root->right));
        return ret + 1;
    }
};
