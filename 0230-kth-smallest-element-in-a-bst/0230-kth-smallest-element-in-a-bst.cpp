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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;

        int node=-1;
        int cnt=0;
        stack<TreeNode*>st;
        TreeNode* curr=root;
        while(true){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                if(st.empty()) break;
                curr=st.top();
                st.pop();
                cnt++;
                if(cnt==k){
                    node = curr->val;
                    break;
                } 

                curr= curr->right;
            }
        }

        return node;
    }
};