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
    int findLength(ListNode* &head){
        ListNode* temp = head;

        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return 0;

        int len = findLength(head);
        int k = (len-n)-1;
        if(n == len)
            return head->next;

        ListNode* prev = head;
        while(k--){
            prev = prev->next;
        }
        
        
        ListNode* nxt = prev->next->next;
        prev->next = nxt;
        return head;
    }
};