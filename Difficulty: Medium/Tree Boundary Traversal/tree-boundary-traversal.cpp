/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private:
    void addLeftNodes(Node* root,vector<int>&res){
        while(root){
            if(root->left || root->right) res.push_back(root->data);
            
            if(root->left) root=root->left;
            else root = root->right;
        }
        
    }
    
    void addLeafNodes(Node* root,vector<int>&res){
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->data);
            return;
        }
        
        
        if(root->left) addLeafNodes(root->left,res);
        if(root->right) addLeafNodes(root->right,res);
    }
    
    void addRightNodes(Node* root, vector<int>&res){
        stack<int> st;
        
        while(root){
            if(root->left || root->right) st.push(root->data);
            
            if(root->right) root=root->right;
            else root = root->left;
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(root==NULL) return res;
        
        if(root->left || root->right) res.push_back(root->data);
        addLeftNodes(root->left,res);
        addLeafNodes(root,res);
        addRightNodes(root->right,res);
        
        return res;
        
        
        
    }
};