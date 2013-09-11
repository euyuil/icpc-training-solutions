/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <priority_queue>

using namespace std;

struct ListNodeComparator {
    bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {

public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {

        priority_queue<ListNode *,
                       vector<ListNode *>,
                       ListNodeComparator> q;

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i] != NULL)
                q.push(lists[i]);

        ListNode *ret = NULL, **ptail = &ret;

        while (!q.empty()) {
            ListNode *p = q.top(); q.pop();
            ListNode *next = p->next;
            *ptail = p;
            p->next = NULL;
            ptail = &p->next;
            if (next != NULL) q.push(next);
        }

        return ret;
    }
};
