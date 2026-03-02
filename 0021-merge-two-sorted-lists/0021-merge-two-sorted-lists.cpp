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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && list2)
            return list2;
        if(list1 && !list2)
            return list1;
        if(!list1 && !list2)
            return 0;

        ListNode* mainHead = list1->val <= list2->val ? new ListNode(list1->val) : new ListNode(list2->val);
        if(list1->val <= list2->val){
            list1 = list1->next;
        }
        else{
            list2 = list2->next;
        }
        ListNode* tail = mainHead;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = new ListNode(list1->val);
                tail = tail->next;
                list1 = list1->next;
            }
            else{
                tail->next = new ListNode(list2->val);
                tail = tail->next;
                list2 = list2->next;
            }
        }

        if(list1){
            tail->next = list1;
        }

        if(list2){
            tail->next = list2;
        }

        return mainHead;
    }
};