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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* prev = nullptr;
        while (head)
        {
            tmp = head->next;
            if (prev)
                head->next = prev;
            else
                head->next = nullptr;
            prev = head;
            head = tmp;
        }
        return (prev);
    }
};
