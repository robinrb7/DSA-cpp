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
        if(!root) return postorder;

        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* temp = st.top();
                if(temp->right) curr=temp->right;
                else{
                    postorder.push_back(temp->val);
                    st.pop();

                    while(!st.empty() && st.top()->right==temp){
                        temp = st.top();
                        postorder.push_back(temp->val);
                        st.pop();
                    }
                }
            }
        }
        return postorder;
    }
};