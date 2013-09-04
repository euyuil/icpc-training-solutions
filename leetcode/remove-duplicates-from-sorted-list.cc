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
    ListNode *deleteDuplicates(ListNode *head) {

        ListNode *ret = NULL, **ptail = &ret, *next;

        for (ListNode *p = head; p; p = next) {

            next = p->next;

            if (!*ptail || ptail->val != p->val) {
                *ptail = p;
                ptail = &p->next;
            } else {
                delete p;
            }
        }

        *ptail = NULL;

        return ret;
    }
};
