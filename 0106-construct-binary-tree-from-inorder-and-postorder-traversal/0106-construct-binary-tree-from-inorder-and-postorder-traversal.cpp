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
    TreeNode* solve(vector<int> &postorder,int postStart, int postEnd,
                    vector<int>&inorder, int inStart,int inEnd, unordered_map<int,int> &inMap)
        {
            if(postStart > postEnd || inStart > inEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int inorderIndex = inMap[postorder[postEnd]];
            int numsLeft = inorderIndex - inStart;

            root->left = solve(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inorderIndex-1,inMap);
            root->right = solve(postorder,postStart+numsLeft,postEnd-1,inorder,inorderIndex+1,inEnd,inMap);
            return root;
        }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(n==0) return NULL;

        unordered_map<int,int> inMap;
        for(int i =0;i<n;i++){
            inMap[inorder[i]]=i;
        }

        return solve(postorder,0,n-1,inorder,0,n-1,inMap);
    }
};