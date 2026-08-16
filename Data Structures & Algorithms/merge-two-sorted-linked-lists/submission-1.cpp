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
 

 // you need a dummy for this
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);//it is recommended to use a dummy head for these problems.
        ListNode *head = &dummy;
        if (!list1)
            return list2;
        else if (!list2)
            return (list1);
        // you simly didnt update which list you took .
        ListNode *tmp = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next; // 
        }
        if (list2)
            tmp->next =  list2;
        else if (list1)
            tmp->next = list1;
        // tmp->next = nullptr; this was a big mistake!!! you linked a list then set it up for null ??
        return (head->next);
    }
};