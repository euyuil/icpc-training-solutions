#include <cstdlib>
#include <cstring>

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

private:

    int sumNumbers(TreeNode *root, int sum) {

        if (root == NULL)
            return 0;

        int x = sum + root->val;
        if (root->left == NULL && root->right == NULL)
            return x;

        int x10 = x * 10;

        int leftSum = sumNumbers(root->left, x10);
        int rightSum = sumNumbers(root->right, x10);

        return leftSum + rightSum;
    }

public:

    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }
};
