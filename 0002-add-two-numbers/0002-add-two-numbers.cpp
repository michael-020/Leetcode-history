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

        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10; 

            tail->next = new ListNode(digit);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            sum = l1->val + carry;
            int digit = sum % 10;
            carry = sum / 10; 

            tail->next = new ListNode(digit);
            tail = tail->next;
            l1 = l1->next;
        }

        while(l2){
            sum = l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10; 
            
            tail->next = new ListNode(digit);
            tail = tail->next;
            l2 = l2->next;
        }

        if(carry){
            tail->next = new ListNode(carry);
            tail = tail->next;
        }

        return dummy.next;
    }
};