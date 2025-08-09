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
    void inorder(TreeNode* root, int &k,int &nodeToFind){
        if(nodeToFind != -1) return;
        if(root==NULL) return;

        inorder(root->left,k,nodeToFind);
        k--;
        if(k==0){
            nodeToFind  = root->val;
            return;
        }
        inorder(root->right,k,nodeToFind);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int nodeToFind=-1;
        inorder(root,k,nodeToFind);
        return nodeToFind;
    }
};