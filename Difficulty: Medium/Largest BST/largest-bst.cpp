/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    private:
    pair<int,pair<int,int>> solve(Node* root){
        if(root==NULL) return {0,{INT_MAX,INT_MIN}};
        
        pair<int,pair<int,int>> left = solve(root->left);
        pair<int,pair<int,int>> right = solve(root->right);
        
        if(root->data > left.second.second && root->data < right.second.first){
            return {(1+left.first+right.first), {min(root->data,left.second.first),max(root->data,right.second.second)} };
        }
        
        return {max(left.first,right.first), {INT_MIN,INT_MAX}};
    }
    
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        if(!root) return 0;
        
        return (solve(root)).first;
    }
};