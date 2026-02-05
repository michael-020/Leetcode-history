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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return 0;
        if(!head->next)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nxt;
        }
        head->next = nullptr;
        return prev;
    }
};