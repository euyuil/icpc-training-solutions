/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {

        if (root == NULL) return;

        queue<pair<int, TreeLinkNode *> > q;
        q.push(make_pair(0, root));

        while (!q.empty()) {

            pair<int, TreeLinkNode *> front = q.front(); q.pop();
            int depth = front.first;
            TreeLinkNode *p = front.second;

            if (p->left) q.push(make_pair(depth + 1, p->left));
            if (p->right) q.push(make_pair(depth + 1, p->right));

            if (!q.empty() && q.front().first == depth)
                p->next = q.front().second;
            else
                p->next = NULL;
        }
    }
};
