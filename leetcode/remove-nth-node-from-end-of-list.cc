/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

    void removeNode(ListNode **pp) {
        if (pp && *pp) {
            ListNode *curr = *pp;
            ListNode *next = curr->next;
            *pp = next;
            delete curr;
        }
    }

public:

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode *> vlnp;
        for (ListNode *p = head; p; p = p->next)
            vlnp.push_back(p);
        if (vlnp.size() == n)
            removeNode(&head);
        else
            removeNode(&vlnp[vlnp.size() - n - 1]->next);
        return head;
    }
};
