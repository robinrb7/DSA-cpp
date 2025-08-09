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
    TreeNode* buildTree(vector<int>& inorder, int start, int end){
        if(start > end) return NULL;

        int mid = start +(end-start)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(inorder,start,mid-1);
        root->right = buildTree(inorder,mid+1,end);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return NULL;

        return buildTree(nums,0,n-1);
    }
};