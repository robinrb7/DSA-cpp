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
    int maxSum(TreeNode* root,int &maxi){
        if(root==NULL) return 0;

        int left = maxSum(root->left,maxi);
        if(left<0) left=0;
        int right = maxSum(root->right,maxi);
        if(right<0) right=0;

        int sum = root->val+left+right;
        maxi = max(maxi,sum);

        return (root->val) + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;

        int maxi = INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
};