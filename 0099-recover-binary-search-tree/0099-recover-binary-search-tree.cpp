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
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        if(prev && root->val < prev->val){
            if(first==NULL){
                first=prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;

        first=middle=last=NULL;
        inorder(root);

        if(last!= NULL) swap(first->val,last->val);
        else swap(first->val,middle->val);
        return;
    }
};