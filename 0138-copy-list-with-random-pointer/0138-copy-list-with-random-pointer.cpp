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
    private:
    Node* makeList(Node* head){
        Node* temp = head;
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        while(temp){
            Node* newNode = new Node(temp->val);
            if(temp==head){
                copyHead = newNode;
                copyTail = newNode;
            }
            else{
                copyTail->next = newNode;
                copyTail=newNode;
            }

            temp=temp->next;
        }

        return copyHead;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node* copyHead = NULL; 
        copyHead = makeList(head);
        
        Node* temp1 = head;
        Node* temp2 = copyHead;
        Node* front1 = NULL;
        Node* front2 = NULL;

        while(temp1 && temp2){
            front1 = temp1->next;
            front2 = temp2->next;

            temp1->next = temp2;
            temp2->next = front1;

            temp1=front1;
            temp2=front2;
        }

        temp1 = head;
        temp2 = copyHead;
        while(temp1 && temp2){
            temp2->random = (temp1->random)? temp1->random->next : NULL;

            temp1 = temp2->next;;
            temp2 = (temp1)?temp1->next:NULL;
        }

        temp1 = head;
        temp2 = copyHead;
        while(temp1 && temp2){

            temp1->next = temp2->next;
            temp2->next = (temp1->next)?temp1->next->next:NULL;

            temp1=temp1->next;
            temp2=temp2->next;
        }

        return copyHead;

    }
};