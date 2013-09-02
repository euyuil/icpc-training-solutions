#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
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

    int ans;

    int maxHalfPathSum(TreeNode *root) {

        int ret = 0;

        if (root == NULL)
            return ret;

        int left = maxHalfPathSum(root->left);
        int right = maxHalfPathSum(root->right);

        ans = max(ans, root->val + left + right);
        ret = max(0, max(left, right) + root->val);

        return ret;
    }

public:

    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        maxHalfPathSum(root);
        return ans;
    }
};
