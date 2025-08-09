/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode* solve(TreeNode* root){
        if(root->left ==NULL) return root->right;
        if(root->right==NULL) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = root->left;
        while(lastRight->right) lastRight = lastRight->right;
        lastRight->right = rightChild;

        root->right = NULL;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        TreeNode* curr=root;
        if(key==curr->val){
            return solve(curr);
        }
        while(curr){
            if(key < curr->val){
                if(curr->left && curr->left->val==key){
                    curr->left = solve(curr->left);
                    break;
                }
                else curr = curr->left;
            }
            else{
                if(curr->right && curr->right->val==key){
                    curr->right = solve(curr->right);
                    break;
                }
                else curr=curr->right;
            }
        }
        return root;
    }
};