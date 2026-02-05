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
    int findLen(ListNode* &head) {
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return head;

        int len = findLen(head);
        ListNode* temp = head;
        int mid = len/2;
        cout << len;
        cout << mid;
        while(mid--){
            temp = temp->next;
        }
        return temp;
    }
};