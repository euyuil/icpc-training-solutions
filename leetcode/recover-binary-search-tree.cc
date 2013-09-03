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

    TreeNode *prev;
    vector<pair<TreeNode *, TreeNode *> > reverses;

    void recursive(TreeNode *root) {

        if (!root) return;

        recursive(root->left);

        if (prev) {
            if (prev->val > root->val) {
                reverses.push_back(make_pair(prev, root));
            }
        }
        prev = root;

        recursive(root->right);
    }

public:

    void recoverTree(TreeNode *root) {

        prev = NULL;
        reverses.clear();
        recursive(root);

        if (reverses.size() == 1) {
            swap(reverses[0].first->val, reverses[0].second->val);
        } else {
            swap(reverses[0].first->val, reverses[1].second->val);
        }
        cout << reverses.size() << endl;
    }
};

int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    Solution().recoverTree(root);
    return 0;
}
