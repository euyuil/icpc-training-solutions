#include <vector>
#include <cstdlib>
#include <utility>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    TreeNode **ptrprev;
    vector<pair<TreeNode **, TreeNode **> > reverses;

    void recursive(TreeNode **ptrroot) {

        TreeNode *root = *ptrroot;
        if (!root) return;

        cout << ptrroot << ' ' << *ptrroot << endl;

        recursive(&root->left);

        if (ptrprev && *ptrprev) {
            TreeNode *prev = *ptrprev;
            if (prev->val > root->val) {
                reverses.push_back(make_pair(ptrprev, ptrroot));
            }
        }
        ptrprev = ptrroot;

        recursive(&root->right);
    }

public:

    void recoverTree(TreeNode *root) {
        ptrprev = NULL;
        reverses.clear();
        recursive(&root);
        // assume reverses == 1 or == 2
        if (reverses.size() == 1) {
            swap((*reverses[0].first)->val, (*reverses[0].second)->val);
        } else {
            TreeNode **smallest = reverses[0].second;
            TreeNode **largest = reverses[1].first;
            swap((*smallest)->val, (*largest)->val);
        }
        cout << reverses.size() << endl;
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    Solution().recoverTree(root);
    return 0;
}
