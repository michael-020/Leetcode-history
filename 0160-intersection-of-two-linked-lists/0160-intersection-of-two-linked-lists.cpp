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
        int lenA = getLen(headA);
        int lenB = getLen(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int diff = lenA > lenB ? lenA - lenB : lenB - lenA;
        if(lenA > lenB){
            for(int i=0; i<diff; i++){
                tempA = tempA->next;
            }
        }
        else if(lenA < lenB){
            for(int i=0; i<diff; i++){
                tempB = tempB->next;
            }
        }

        while(tempA || tempB){
            if(tempA == tempB)
                return tempA;

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return 0;
    }
};