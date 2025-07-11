// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        if(head_ref==NULL) return;
        
        Node* curr = *head_ref;
        Node* previous =NULL;
        Node* forward = NULL;
        
        while(curr){
            forward = curr->next;
            
            if(curr->data == x){
                Node* delNode = curr;
                if(previous==NULL){
                    if(forward) forward->prev = previous;
                    curr->next = NULL;
                    *head_ref = forward;
                }
                else if(forward==NULL){
                    previous->next = forward;
                    curr->prev = NULL;
                }
                else{
                    previous->next = forward;
                    forward->prev = previous;
                    curr->next = NULL;
                    curr->prev = NULL;
                }
                
                delete delNode;
                curr=forward;
            }
            else{
                previous = curr;
                curr = forward;
            }
            
        }
        
        return;
        
    }
};