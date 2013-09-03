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
    TreeNode *buildSubTree(T preb, T pree, T inb, T ine) {

        if (preb >= pree) return NULL;
        if (preb + 1 == pree) return new TreeNode(*preb);

        T premedium = preb;
        T inmedium = inb;
        for ( ; *inmedium != *premedium; ++inmedium);

        TreeNode *root = new TreeNode(*premedium);
        root->left = buildSubTree(preb + 1, preb + 1 + (inmedium - inb),
                                  inb, inmedium);
        root->right = buildSubTree(preb + 1 + (inmedium - inb), pree,
                                   inmedium + 1, ine);

        return root;
    }

public:

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildSubTree(preorder.begin(), preorder.end(),
                            inorder.begin(), inorder.end());
    }
};
