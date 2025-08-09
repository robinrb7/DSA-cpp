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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int node=-1;
        int cnt=0;

        TreeNode* curr=root;
        while(curr){
            if(curr->left==NULL){
                cnt++;
                if(cnt==k){
                    node = curr->val;
                }
                curr=curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp->right!=curr) temp= temp->right;
                if(temp->right==NULL){
                    temp->right=curr;
                    curr=curr->left;
                } 
                else{
                    cnt++;
                    if(cnt==k){
                        node = curr->val;
                    }
                    temp->right = NULL;
                    curr=curr->right;
                } 
            }

        }
        return node;
    }
};