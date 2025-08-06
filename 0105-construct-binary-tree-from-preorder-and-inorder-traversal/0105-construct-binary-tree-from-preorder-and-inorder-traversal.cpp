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
    TreeNode* solve(vector<int>&preorder,int preStartIndex,int preEndIndex,
                    vector<int>& inorder, int inStartIndex,int inEndIndex,
                    unordered_map<int,int> &inMap){

        if(preStartIndex > preEndIndex || inStartIndex>inEndIndex) return NULL;                
                    
        TreeNode* root = new TreeNode(preorder[preStartIndex]);
        int inorderIndex = inMap[preorder[preStartIndex]];
        int numsLeft = inorderIndex - inStartIndex;

        root->left = solve(preorder,preStartIndex+1,preStartIndex+numsLeft,
                            inorder,inStartIndex,inorderIndex-1,inMap);
        root->right = solve(preorder,preStartIndex+numsLeft+1,preEndIndex,
                            inorder,inorderIndex+1,inEndIndex,inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0) return NULL;

        unordered_map<int,int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]]=i;
        }

        return solve(preorder,0,n-1,inorder,0,n-1,inMap);

    }
};