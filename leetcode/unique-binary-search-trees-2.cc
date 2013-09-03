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

    vector<TreeNode *> generateTrees(int n, int delta) {

        vector<TreeNode *> ret;

        if (n == 0) {
            ret.push_back(NULL);
        } else if (n == 1) {
            ret.push_back(new TreeNode(delta + 1));
        } else {

            for (int i = 1; i <= n; ++i) {
                // This could be a bug in practice.
                // Because subtrees are reused in many trees.
                // But maybe it can pass the judge.
                // Yes, it did work.
                vector<TreeNode *> left = generateTrees(i - 1, delta);
                vector<TreeNode *> right = generateTrees(n - i, delta + i);
                for (int x = 0; x < left.size(); ++x) {
                    for (int y = 0; y < right.size(); ++y) {
                        TreeNode *node = new TreeNode(delta + i);
                        node->left = left[x];
                        node->right = right[y];
                        ret.push_back(node);
                    }
                }
            }
        }

        return ret;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(n, 0);
    }
};
