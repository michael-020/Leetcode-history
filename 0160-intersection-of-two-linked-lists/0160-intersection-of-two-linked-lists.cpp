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
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        int n = getLength(headA);
        int m = getLength(headB);
        int diff = abs(n-m);
        if(n > m){
            while(diff--){
                a = a->next;
            }
        }
        else if(n < m){
            while(diff--){
                b = b->next;
            }
        }
        else{
            a = headA;
            b = headB;
        }

        while(a->next && b->next){
            if(a == b)
                return a;
            a = a->next;
            b = b->next;
        }

        if(a == b)
            return a;

        if(a->next == 0 && b->next == 0 && a != b)
            return 0;

        return 0;
    }
};