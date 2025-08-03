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

        stack<TreeNode*>st;
        TreeNode* node = root;
        while(node || !st.empty()){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp){
                    node=temp;
                }
                else{
                    temp = st.top();
                    postorder.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp==st.top()->right){
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