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
    void revLL(ListNode* &prev, ListNode* &curr){
        if(!curr)
            return;

        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;

        revLL(prev, curr);
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;

        ListNode* curr = head;
        ListNode* prev = 0;
        revLL(prev, curr);

        return prev;
    }
};