#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if (!head) return NULL;

        /**
         * h mn m         n nn t
         * 1 -> 2 -> 3 -> 4 -> 5
         */

        int pos = 0;
        ListNode *prev = NULL, *mp, *np, *next;
        ListNode **mnext, **nnext, **pnext = &head;

        for (ListNode *p = head; p; p = next) {

            ++pos;
            next = p->next;

            if (pos == m) {
                mp = p;
                mnext = pnext;
            }

            if (m < pos && pos <= n) {
                p->next = prev;
            }

            if (pos == n) {
                np = p;
                // nnext = &p->next;

                *mnext = np;
                mp->next = next;
            }

            prev = p;
            pnext = &p->next;
        }

        return head;
    }
};

int main() {
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(-3);
    head = Solution().reverseBetween(head, 1, 2);
    cout << "outing" << endl;
    cout << head->val << ' ' << endl;
    return 0;
}
