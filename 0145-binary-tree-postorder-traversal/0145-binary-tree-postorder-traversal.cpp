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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        if(root==NULL) return postorder;

        stack<TreeNode*>st1;
        stack<int>st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* top = st1.top();
            st1.pop();
            
            if(top->left) st1.push(top->left);
            if(top->right) st1.push(top->right);

            st2.push(top->val);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top());
            st2.pop();
        }

        return postorder;
    }
};