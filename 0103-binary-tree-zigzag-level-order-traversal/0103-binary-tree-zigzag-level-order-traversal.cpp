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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int>temp(size);

            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                q.pop();
                int index= flag? i : (size-1 -i);
                temp[index] = top->val;

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            flag=!flag; 
            res.push_back(temp);
        }

        return res;
    }
};