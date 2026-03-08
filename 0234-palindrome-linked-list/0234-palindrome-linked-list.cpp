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
    ListNode* revLL(ListNode* &head){
        ListNode* prev = 0;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head)
            false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            fast = fast->next;

            if(fast && fast->next){
                fast = fast->next;
                slow = slow->next;
            }

            if(fast == slow)
                break;
        }

        ListNode* newHead = revLL(slow->next);
        ListNode* l1 = head;
        ListNode* l2 = newHead;

        while(l1 && l2){
            if(l1->val != l2->val)
                return false;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        return true;
    }
};