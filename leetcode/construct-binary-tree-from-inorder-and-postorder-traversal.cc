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
    TreeNode *buildSubTree(T inb, T ine, T postb, T poste) {

        if (inb >= ine || postb >= poste)
            return NULL;

        if (inb + 1 == ine && postb + 1 == poste && *inb == *postb)
            return new TreeNode(*inb);

        T postmedium = poste - 1;
        T inmedium = inb;
        for ( ; inmedium != ine; ++inmedium)
            if (*inmedium == *postmedium)
                break;

        TreeNode *root = new TreeNode(*postmedium);
        root->left = buildSubTree(inb, inmedium,
                                  postb, postb + (inmedium - inb));
        root->right = buildSubTree(inmedium + 1, ine,
                                   postb + (inmedium - inb), postmedium);

        return root;
    }

public:

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildSubTree(inorder.begin(), inorder.end(),
                            postorder.begin(), postorder.end());
    }
};
