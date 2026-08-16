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
    bool hasCycle(ListNode* head) {
        ListNode *curr = head;
        // by manipulating the values of the list. 1000 + index;
        //int i = -1;
        while (curr)
        {
            if (curr->val > 1000)
                return (true);
            else
                curr->val += 1000;
            curr = curr->next;
        }
        return false;
    }
};
