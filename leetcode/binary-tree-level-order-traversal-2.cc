#include <vector>
#include <utility>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {

        vector<vector<int> > ret;

        if (!root) return ret;

        ret.reserve(1000);

        queue<pair<int, TreeNode *> > q;
        q.push(make_pair(0, root));

        while (!q.empty()) {

            pair<int, TreeNode *> pr = q.front(); q.pop();

            int depth = pr.first;
            TreeNode *node = pr.second;
            int value = node->val;

            if (ret.size() <= depth)
                ret.resize(depth + 1);

            ret[depth].push_back(value);

            if (node->left)
                q.push(make_pair(depth + 1, node->left));
            if (node->right)
                q.push(make_pair(depth + 1, node->right));
        }

        reverse(ret.begin(), ret.end());

        return ret;
    }
};
