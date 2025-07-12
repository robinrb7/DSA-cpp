/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
    private:
    Node* sortTwoList(Node* l1, Node* l2){
        if(!l1 && !l2) return NULL;
        if(l1 && !l2) return l1;
        if(!l1 && l2) return l2;
        
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(l1 && l2){
            if(l1->data < l2->data){
                temp->bottom = l1;
                temp=l1;
                l1=l1->bottom;
                
            }
            else{
                temp->bottom = l2;
                temp=l2;
                l2=l2->bottom;
            }
        }
         
        if(l1) temp->bottom = l1;
        if(l2) temp->bottom = l2;
              
        return dummy->bottom;
    }
    Node* solve(Node* root){
        Node* prev = root;
        if(!root->next) return root;
        Node* temp = solve(root->next);
        return sortTwoList(prev,temp);
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        return solve(root);
        
        
        
        
        
    }
};