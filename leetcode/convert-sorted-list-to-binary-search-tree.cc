#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {

        if (!head) return NULL;
        if (tail && tail->next == head) return NULL;
        if (!head->next || head == tail) return new TreeNode(head->val);

        // assume head != tail

        ListNode *medium = head, *dummy = head, *mediumPrev = head;
        while (dummy != tail && dummy != NULL) {
            mediumPrev = medium;
            medium = medium->next;
            dummy = dummy->next;
            if (dummy == tail || dummy == NULL) break;
            dummy = dummy->next;
        }
        cout << head->val << ' ' << medium->val << ' ' << tail->val << endl;

        TreeNode *root = new TreeNode(medium->val);
        root->left = sortedListToBST(head, mediumPrev);
        root->right = sortedListToBST(medium->next, tail);

        return root;
    }

public:

    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        ListNode *tail = head;
        while (tail->next) tail = tail->next;
        return sortedListToBST(head, tail);
    }
};

int main() {

    ListNode *head = new ListNode(0);
    ListNode *tail = head;

    for (int i = 1; i < 5; ++i) {
        tail->next = new ListNode(i);
        tail = tail->next;
    }

    TreeNode *p = Solution().sortedListToBST(head);

    return 0;
}
