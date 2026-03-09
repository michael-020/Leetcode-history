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
    int getLen(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;

        int size = getLen(head);
        k = k % size;
        if(k == 0)
            return head;

        int diff = size-k;
        ListNode* tail = head;
        while(tail->next) tail = tail->next;

        ListNode* newTail = head;
        for(int i=1; i<diff; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        tail->next = head;
        
        return newHead;
    }
};