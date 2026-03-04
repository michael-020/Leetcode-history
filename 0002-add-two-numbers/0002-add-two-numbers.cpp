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
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int sum = 0;
        int carry = 0;

        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;

            if(carry == 0){
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = tail->next;
            }
            else {
                ListNode* newNode = new ListNode(digit);
                tail->next = newNode;
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1){
            while(l1){
                sum = l1->val + carry;
                int digit = sum % 10;
                carry = sum / 10;

                if(carry == 0){
                    ListNode* newNode = new ListNode(sum);
                    tail->next = newNode;
                    tail = tail->next;
                }
                else {
                    ListNode* newNode = new ListNode(digit);
                    tail->next = newNode;
                    tail = tail->next;
                }
                l1 = l1->next;
            }
        }
        else {
            while(l2){
                sum = l2->val + carry;
                int digit = sum % 10;
                carry = sum / 10;

                if(carry == 0){
                    ListNode* newNode = new ListNode(sum);
                    tail->next = newNode;
                    tail = tail->next;
                }
                else {
                    ListNode* newNode = new ListNode(digit);
                    tail->next = newNode;
                    tail = tail->next;
                }
                l2 = l2->next;
            }
        }

        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;
        }

        return dummy->next;
    }
};