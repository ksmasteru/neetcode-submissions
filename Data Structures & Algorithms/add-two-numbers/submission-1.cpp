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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // calculate result
        ListNode *dummy = new ListNode(-1);
        ListNode *tmp = dummy;
        int val = 0;
        while (l1 && l2)
        {
            // will act as a remainder
            val += l1->val;
            val += l2->val;
            // if greater that 10 link 2 node first.
            if (val > 9)
            {
                tmp->next = new ListNode(val - 10);
                val = 1;
            }
            // else one node.
            else
            {
                tmp->next = new ListNode(val);
                val = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            tmp = tmp->next;
        }
        while (l1)
        {
            val += l1->val;
            if (val > 9)
            {
                tmp->next = new ListNode(val - 10);
                val = 1;
            }
            else
            {
                tmp->next = new ListNode(val);
                val = 0;
            }
            l1 = l1->next;
            tmp = tmp->next;
        }
        while (l2)
        {
            val += l2->val;
            if (val > 9)
            {
                tmp->next = new ListNode(val - 10);
                val = 1;
            }
            else
            {
                tmp->next = new ListNode(val);
                val = 0;
            }
            l2 = l2->next;
            tmp = tmp->next;
        }
        if (val == 1)
            tmp->next = new ListNode(1);
        return (dummy->next);
    }
};

// :: two pass firt calucate the result : then  make the linked list.