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
        if(!head) return head;

        Node* copyHead = NULL;
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            if(!copyHead) copyHead=newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while(temp){
            temp->next->random = (temp->random)? temp->random->next : NULL;

            temp = (temp->next)?temp->next->next : NULL;
        }

        temp = head;
        Node* copy = copyHead;
        while(temp){
            temp->next = copy->next;
            copy->next = (copy->next)?copy->next->next : NULL;

            temp=temp->next;
            copy=copy->next;
        }

        return copyHead;

    }
};