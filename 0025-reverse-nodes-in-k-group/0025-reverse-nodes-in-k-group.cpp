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
    ListNode* revLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = 0;

        while(curr){
            ListNode* nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        for(int i=1; i<k; i++){
            if(temp)
                temp = temp->next;
        }
        if(!temp) return 0;

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev = 0;
        ListNode* temp = head;
        while(temp){
            ListNode* kthNode = findKthNode(temp, k);
            if(!kthNode){
                if(prev)
                    prev->next = temp;
                break;
            }
            ListNode* nxt = kthNode->next;
            kthNode->next = nullptr;
            ListNode* newHead = revLL(temp);
            if(temp == head)
                head = kthNode;
            else
                prev->next = kthNode;

            prev = temp;
            temp = nxt;
        }

        return head;
    }
};