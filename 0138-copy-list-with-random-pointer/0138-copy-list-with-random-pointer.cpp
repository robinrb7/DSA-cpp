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
        if(head==NULL) return head;

        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while(temp){
            Node* node = new Node(temp->val);
            tail->next = node;
            tail=node;
            temp=temp->next;
        }
        temp=head;
        tail=dummy->next;
        Node* front1 = NULL;
        Node* front2 = NULL;
        while(temp){
            front1 = temp->next;
            front2= tail->next;

            temp->next=tail;
            tail->next= front1;

            temp=front1;
            tail=front2;
        }

        temp=head;
        while(temp){
            if(temp->next)
                temp->next->random = (temp->random==NULL)? NULL : temp->random->next;
            temp=temp->next->next;
        }

        temp = head;
        tail = dummy->next;
        while(temp){
            front1 = temp->next->next;
            if(front1) front2 = front1->next;
            else front2 = front1;

            temp->next= front1;
            tail->next= front2;

            temp=front1;
            tail=front2;
        }

        return dummy->next;
        
    }
};