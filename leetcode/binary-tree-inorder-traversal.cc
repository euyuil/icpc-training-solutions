#include <utility>

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
    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> ret;
        vector<pair<TreeNode *, bool> > st;

        if (root) {

            st.push_back(make_pair(root, true));

            while (!st.empty()) {

                pair<TreeNode *, bool> pr = st.back(); st.pop_back();

                TreeNode *p = pr.first;
                bool shouldPushLeft = pr.second;

                if (p->left && shouldPushLeft) {
                    st.push_back(make_pair(p, false));
                    st.push_back(make_pair(p->left, true));
                } else {
                    ret.push_back(p->val);
                    if (p->right)
                        st.push_back(make_pair(p->right, true));
                }
            }
        }

        return ret;
    }
};
