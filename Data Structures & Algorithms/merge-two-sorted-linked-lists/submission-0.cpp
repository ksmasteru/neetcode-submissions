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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return (list1);
        ListNode* head = (list1->val < list2->val ? list1 : list2);
        ListNode* ret = head;
        ListNode* tmp;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tmp = list1->next;
                head->next = list1;
                list1 = tmp;
            }
            else
            {
                tmp = list2->next;
                head->next = list2;
                list2 = tmp;
            }
            head = head->next;
        }
        while (list2)
        {
            tmp = list2->next;
            head->next = list2;
            list2 = tmp;
            head = head->next;
        }
        while (list1)
        {
            tmp = list1->next;
            head->next = list1;
            list1 = tmp;
            head = head->next;
        }
        head->next = nullptr;
        return (ret);
    }
};