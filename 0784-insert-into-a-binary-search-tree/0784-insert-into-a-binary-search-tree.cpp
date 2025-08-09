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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
       if(!root){
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
       }

       TreeNode* curr =root;
       while(true){
            if(curr->val> val){
                if(curr->left) curr=curr->left;
                else{
                    TreeNode* newNode = new TreeNode(val);
                    curr->left = newNode;
                    break;
                }
            }
            else{
                if(curr->right) curr=curr->right;
                else{
                    TreeNode* newNode = new TreeNode(val);
                    curr->right = newNode;
                    break;
                }
            }
       }

       return root;
    }
};