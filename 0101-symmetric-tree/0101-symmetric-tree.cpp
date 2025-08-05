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
    bool identical(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if((root1==NULL && root2!=NULL)|| (root1!=NULL && root2==NULL) )return false;
        
        bool left = identical(root1->left,root2->right);
        bool right = identical(root1->right,root2->left);

        if(left && right && (root1->val==root2->val)) return true;
        return false;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if((root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL) )return false;

        return identical(root->left,root->right);
    }
};