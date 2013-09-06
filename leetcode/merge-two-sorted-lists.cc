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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        ListNode *ret = NULL;
        ListNode **ppnext = &ret;

        ListNode *p1 = l1, *p2 = l2;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val < p2->val) {
                *ppnext = p1;
                ppnext = &p1->next;
                p1 = p1->next;
            } else {
                *ppnext = p2;
                ppnext = &p2->next;
                p2 = p2->next;
            }
        }

        while (p1 != NULL) {
            *ppnext = p1;
            ppnext = &p1->next;
            p1 = p1->next;
        }

        while (p2 != NULL) {
            *ppnext = p2;
            ppnext = &p2->next;
            p2 = p2->next;
        }

        *ppnext = NULL;

        return ret;
    }
};
