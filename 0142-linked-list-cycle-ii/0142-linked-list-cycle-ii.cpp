/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast){
            fast = fast->next;

            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow)
                break;
        }

        if(!fast){
            return 0;
        }

        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};