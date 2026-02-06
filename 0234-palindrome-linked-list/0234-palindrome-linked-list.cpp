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
    void copyLL(ListNode* &head, ListNode* &cHead){
        ListNode* temp = head->next;
        ListNode* cTemp = cHead;

        while(temp){
            ListNode* newNode = new ListNode(temp->val);
            cTemp->next = newNode;
            temp = temp->next;
            cTemp = cTemp->next;
        }
    }

    ListNode* revLL(ListNode* &head){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev = dummy;
        dummy->next = head;

        while(curr){
            ListNode* nxt = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return head;

        ListNode* cHead = new ListNode(head->val);
        copyLL(head, cHead);
        ListNode* newHead = revLL(cHead);
        ListNode* temp1 = head;
        ListNode* temp2 = newHead;
        while(temp1){
            if(temp1->val != temp2->val)
                return false;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};