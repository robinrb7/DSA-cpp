/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int kthLargest(Node *root, int k) {
        if(!root) return -1;

        int node=-1;
        int cnt=0;

        Node* curr=root;
        while(curr){
            if(curr->right==NULL){
                cnt++;
                if(cnt==k){
                    node = curr->data;
                }
                curr=curr->left;
            }
            else{
                Node* temp = curr->right;
                while(temp->left && temp->left!=curr) temp= temp->left;
                if(temp->left==NULL){
                    temp->left=curr;
                    curr=curr->right;
                } 
                else{
                    cnt++;
                    if(cnt==k){
                        node = curr->data;
                    }
                    temp->left = NULL;
                    curr=curr->left;
                } 
            }

        }
        return node;
        
    }
};