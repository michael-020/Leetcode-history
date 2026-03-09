/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        Node* temp = head;

        while(temp){
            Node* nxt = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nxt;
            temp = nxt;
        }

        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        temp = head;
        Node* cHead = head->next;
        Node* copy = cHead;
        while(temp){
            temp->next = temp->next->next;

            if(copy->next)
                copy->next = copy->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return cHead;
    }
};