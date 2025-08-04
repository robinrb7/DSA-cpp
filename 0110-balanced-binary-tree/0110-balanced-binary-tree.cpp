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
    int heightBalanced(TreeNode* root){
        if(root==NULL) return 0;

        int left=heightBalanced(root->left);
        int right = heightBalanced(root->right);

        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return (1+max(left,right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        if(heightBalanced(root)==-1) return false;
        return true;
    }
};