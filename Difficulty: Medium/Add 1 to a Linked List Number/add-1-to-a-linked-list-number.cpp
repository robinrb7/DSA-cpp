/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
    Node* rev(Node* head){
        if(!head || !head->next) return head;
        
        Node* newHead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    
  public:
    Node* addOne(Node* head) {
        head = rev(head);
        
        Node* temp = head;
        int carry=1;
        while(temp){
            int  num = temp->data + carry;
            temp->data = num%10;
            carry = num/10;
            if(carry==0) break;
            temp=temp->next;
        }
        
        head = rev(head);
        if(carry){
            Node* newNode = new Node(carry);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};