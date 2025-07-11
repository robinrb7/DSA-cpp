/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if(!head || !head->next) return head;
        
        Node* curr = head->next;
        Node* previous = head;
        
        while(curr){
            if(curr->data == previous->data){
                Node* delNode = curr;
                
                Node* forward = curr->next;
                
                previous->next = forward;
                if(forward) forward->prev = previous;
                
                delete delNode;
                curr = forward;
            }
            else{
                previous = curr;
                curr = curr->next;
            }
        }
        
        return head;
        
    }
};