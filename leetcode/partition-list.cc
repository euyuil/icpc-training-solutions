/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {

        ListNode *next, *prev = NULL;
        ListNode **current = &head;

        for (ListNode *p = head; p; p = next) {

            next = p->next;

            if (p->val < x) {
                if (p != *current) {
                    p->next = *current;
                    *current = p;
                    if (prev) prev->next = next;
                    current = &p->next;
                    p = prev;
                } else {
                    current = &p->next;
                }
            }

            prev = p;
        }

        return head;
    }
};
