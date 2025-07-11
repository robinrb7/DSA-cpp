/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if(!head ||!head->next) return head;
        // code here
        Node* dummy0 = new Node(-1);
        Node* dummy1 = new Node(-1);
        Node* dummy2 = new Node(-1);
        Node* curr0 = dummy0;
        Node* curr1 = dummy1;
        Node* curr2 = dummy2;
        
        Node* temp = head;
        while(temp){
            if(temp->data == 0){
                curr0->next = temp;
                curr0=curr0->next;
            }
            else if(temp->data == 1){
                curr1->next = temp;
                curr1=curr1->next;
            }
            else{
                curr2->next = temp;
                curr2=curr2->next;
            }
            
            temp = temp->next;
        }
        
        if(curr1 != dummy1) {
            curr0->next = dummy1->next;
            curr1->next = dummy2->next;
        }
        else curr0->next = dummy2->next;
        
        curr2->next = NULL;
        return dummy0->next;
    }
};