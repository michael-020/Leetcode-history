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
    Node* findRandomNode(Node* copyHead, Node* originalHead, Node* temp){
        if(!temp)
            return nullptr;

        Node* target = temp->random;

        Node* t1 = originalHead;
        Node* t2 = copyHead;

        while(t1 && t2){
            if(t1 == target)
                return t2;

            t1 = t1->next;
            t2 = t2->next;
        }
        return 0;
    }

    Node* copyRandomList(Node* head) {
        if(!head)
            return head;

        Node dummy(-1);
        Node* tail = &dummy;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            tail->next = newNode;
            tail = tail->next;
            temp = temp->next;
        }
        Node* it = dummy.next;
        temp = head;
        while(temp){
            Node* randomNode = findRandomNode(dummy.next, head, temp);
            it->random = randomNode;
            it = it->next;
            temp = temp->next;
        }

        return dummy.next;
    }
};