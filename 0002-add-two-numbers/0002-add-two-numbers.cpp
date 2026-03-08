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
        if(!l1 || !l2)
            return 0;

        int sum = 0;
        int carry = 0;
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 || l2 || carry){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            sum = a + b + carry;
            int digit = sum % 10;
            carry = sum / 10; 

            tail->next = new ListNode(digit);
            tail = tail->next;

            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }

        return dummy.next;
    }
};