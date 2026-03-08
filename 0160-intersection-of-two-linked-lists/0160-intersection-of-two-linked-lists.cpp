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
    int getLen(ListNode* &head){
        ListNode* temp = head;
        int len = 0;

        while(temp){
            temp = temp->next;
            len++;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;

        int lenA = getLen(headA);
        int lenB = getLen(headB);
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while(l1 != l2 ){

            if(!l1) 
                l1 = headB;
            else
                l1 = l1->next;

            if(!l2)     
                l2 = headA;
            else
                l2 = l2->next;
        }

        return l1;

    }
};