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

        ListNode *ret = NULL, **ptail = &ret, *next, *prev = NULL;

        for (ListNode *p = head; p; p = next) {

            next = p->next;

            if (prev && prev->val == p->val) {
                delete p;
            } else {
                *ptail = p;
                ptail = &p->next;
                prev = p;
            }
        }

        *ptail = NULL;

        return ret;
    }
};
