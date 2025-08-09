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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        TreeNode* curr = root;
        TreeNode* lca = NULL;
        while(curr){
            if(curr->val > p->val && curr->val > q->val) curr=curr->left;
            else if(curr->val < p->val && curr->val < q->val) curr=curr->right;
            else {
                lca = curr;
                break;
            }
        }
        
        return lca;
    }
};