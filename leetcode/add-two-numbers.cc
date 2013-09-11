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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *ret = NULL, **ptail = &ret;

        int carrier = 0;
        while (l1 != NULL || l2 != NULL) {

            int a = l1 == NULL ? 0 : l1->val;
            int b = l2 == NULL ? 0 : l2->val;
            int sum = a + b + carrier;

            carrier = sum / 10;
            sum %= 10;

            *ptail = new ListNode(sum);
            ptail = &(**ptail).next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        if (carrier > 0) {
            *ptail = new ListNode(carrier);
        }

        return ret;
    }
};
