/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    private:
    pair<bool,int> solve(Node* root){
        if(root==NULL) return {true,0};
        
        pair<bool,int>left = solve(root->left);
        pair<bool,int>right = solve(root->right);
        
        int sum = left.second+right.second;
        bool checkSum = (root->data == sum) || (root->left==NULL && root->right==NULL);
        if((left.first && right.first) && checkSum){
            return {true,root->data};
        }
        
        return {false,root->data};
    }
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
       if(!root) return 1;
       
       return solve(root).first;
    }
};