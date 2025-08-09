/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

void solve(Node* root, int key, int &ceilValue){
    if(root==NULL) return;
    
    if(root->data==key){
        ceilValue=root->data;
        return;
    }
    else if(root->data > key){
        ceilValue = root->data;
        solve(root->left,key,ceilValue);
    }
    else{
        solve(root->right,key,ceilValue);
    }
}
int findCeil(Node* root, int input) {
    int ceilValue=-1;
    if(!root) return ceilValue;
    
    solve(root,input,ceilValue);
    return ceilValue;
    
}