/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy head.
        ListNode* dummy = new ListNode(-1, head);
        ListNode* left = dummy;
        ListNode* right = head;
        // two pointer keeping n distance
        while (right && n-- > 0)
            right = right->next;
        while (right)
        {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};
