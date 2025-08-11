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
    class BSTIterator{
        public:
        bool reverse; // true -> asc Inorder , false -> desc Inorder
        stack<TreeNode*> st;
        BSTIterator(TreeNode* root,bool isReverse){
            reverse = isReverse;
            pushIntoStack(root);
        }
        int next(){
            TreeNode* top = st.top();
            st.pop();
            if(reverse) pushIntoStack(top->right);
            if(!reverse) pushIntoStack(top->left);
            return top->val;
        }

        void pushIntoStack(TreeNode* root){
            while(root){
                st.push(root);
                if(reverse) root = root->left;
                else root= root->right;
            }
        }
    };

public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator smallest(root,true);
        BSTIterator largest(root,false);

        int left = smallest.next();
        int right = largest.next();

        while(left < right){
            int sum = left +right;
            if(sum == k) return true;
            else if(sum < k) left = smallest.next();
            else right =largest.next();
        }

        return false;
    }
};