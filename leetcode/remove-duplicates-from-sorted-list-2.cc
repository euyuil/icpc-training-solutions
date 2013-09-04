/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

    void remove(ListNode **pp) {
        // -> tobedel -> next
        ListNode *p = *pp;
        *pp = p->next;
        delete p;
    }

public:

    ListNode *deleteDuplicates(ListNode *head) {

        ListNode **pp = &head;
        ListNode *next, *prev = NULL;

        // Not necessary to do it in-place...
        for (ListNode *p = head; p; p = next) {

            next = p->next;

            if (p->next && p->val == p->next->val) {

                int val = p->val;
                // -> p -> ... -> p -> next
                while (p && p->val == val) {
                    remove(pp);
                    p = *pp;
                }
                next = p;

            } else {
                pp = &p->next;
            }
        }

        return head;
    }
};
