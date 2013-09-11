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
    ListNode *swapPairs(ListNode *head) {

        ListNode *one = head, *two, *ret = NULL, **ptail = &ret;

        while (one != NULL && (two = one->next) != NULL) {

            ListNode *newone = two->next;

            *ptail = two;
            two->next = one;
            one->next = NULL;
            ptail = &one->next;

            one = newone;
        }

        if (one != NULL) {
            *ptail = one;
            one->next = NULL;
        }

        return ret;
    }
};
