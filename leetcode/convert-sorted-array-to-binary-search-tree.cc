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

    template <typename T>
    TreeNode *recursive(T begin, T end) {

        if (begin >= end) return NULL;
        if (begin + 1 == end) return new TreeNode(*begin);

        T medium = begin + (end - begin) / 2;

        TreeNode *root = new TreeNode(*medium);
        root->left = recursive(begin, medium);
        root->right = recursive(medium + 1, end);

        return root;
    }

public:

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return recursive(num.begin(), num.end());
    }
};
