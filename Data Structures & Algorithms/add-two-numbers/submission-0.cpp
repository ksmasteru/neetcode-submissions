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
        // get string then reverse it add it to the other string.
        string buffer1;
        string buffer2;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        int n1 = 0;
        int n2 = 0;
        while (tmp1)
        {
            buffer1 += tmp1->val + 48;
            tmp1 = tmp1->next;
        }
        while(tmp2)
        {
            buffer2 += tmp2->val + 48;
            tmp2 = tmp2->next;
        }
        reverse(buffer1.begin(), buffer1.end());
        reverse(buffer2.begin(), buffer2.end());
        if (l1)
            n1 =  std::stoi(buffer1);
        if (l2)
            n2 = std::stoi(buffer2);
        //std::cout << "added number ist " << n1 + n2 << std::endl;
        int sum = n1 + n2;
        string result = to_string(sum);
        reverse(result.begin(), result.end());
        ListNode* head = new ListNode(result[0] - 48);
        ListNode* prev = head;
        for (int i = 1 ; i < result.size(); i++)
        {
            prev->next = new ListNode(result[i] - 48);
            prev = prev->next;
        }
        return (head);
    }
};

// :: two pass firt calucate the result : then  make the linked list.