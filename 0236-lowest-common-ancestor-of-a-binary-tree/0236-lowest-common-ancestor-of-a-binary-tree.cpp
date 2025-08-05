/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& lca){
        if(!root) return false;

        bool thisNode = (root==p || root==q);

        bool left = solve(root->left,p,q,lca);
        bool right = solve(root->right,p,q,lca);

        if((thisNode && left) || (thisNode && right) || (left && right)){
            lca = root;
        } 

        if(thisNode || left || right) return true;
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        TreeNode* lca = NULL;
        solve(root,p,q,lca);
        return lca;
    }
};