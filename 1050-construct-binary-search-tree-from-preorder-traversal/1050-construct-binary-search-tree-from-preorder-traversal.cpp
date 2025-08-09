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
    TreeNode* solve(vector<int>& preorder, int &index, int maxVal, int n){
        if(index==n || preorder[index]>maxVal) return NULL;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder,index,root->val,n);
        root->right = solve(preorder,index,maxVal,n);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n =preorder.size();
        if(n==0) return NULL;
        
        int index=0;
        return solve(preorder,index,INT_MAX,n);
    }
};