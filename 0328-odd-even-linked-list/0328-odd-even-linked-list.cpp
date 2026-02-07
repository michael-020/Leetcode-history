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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return head;
        
        ListNode* evenHead = head->next;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = temp2->next;

        while(temp3){
            temp1->next = temp3;
            temp2->next = temp3->next;
            temp1 = temp3;
            temp2 = temp1->next;
            if(!temp2)
                break;
            temp3 = temp2->next;
        }
        temp1->next = evenHead;
        return head;
    }
};