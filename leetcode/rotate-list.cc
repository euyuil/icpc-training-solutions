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
    ListNode *rotateRight(ListNode *head, int k) {

        if (head == NULL)
            return head;

        int n = 1;

        ListNode *tail = head;

        while (tail->next != NULL)
            tail = tail->next, ++n;

        k = k % n;
        if (k < 0)
            k += n;

        if (k == 0)
            return head;

        int t = n - k;

        ListNode *pt = head;
        for (int i = 1; i < t; ++i)
            pt = pt->next;

        ListNode *ret = pt->next;
        pt->next = NULL;
        tail->next = head;

        return ret;
    }
};
