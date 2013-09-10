/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

    // reverse nodes in range [begin, end).

    ListNode *reverse(ListNode *begin, ListNode *end) {
        ListNode *a = begin, *b = begin->next;
        begin->next = NULL;
        while (b != end) {
            ListNode *newb = b->next;
            b->next = a;
            a = b;
            b = newb;
        }
        return a;
    }

    ListNode *lastNode(ListNode *here) {
        while (here && here->next)
            here = here->next;
        return here;
    }

    ListNode *nextNode(ListNode *here, int n) {
        for (int i = 0; i < n; ++i)
            if (here) here = here->next;
        return here;
    }

public:

    ListNode *reverseKGroup(ListNode *head, int k) {

        ListNode *ret = NULL, **ptail = &ret;

        ListNode *begin = head;
        while (begin != NULL) {

            ListNode *last = nextNode(begin, k - 1);
            ListNode *end = nextNode(last, 1);
            if (last != NULL) {
                ListNode *reversed_begin = reverse(begin, end);
                ListNode *reversed_last = lastNode(reversed_begin);
                *ptail = reversed_begin;
                ptail = &reversed_last->next;
            } else {
                *ptail = begin;
            }

            begin = end;
        }

        return ret;
    }
};
