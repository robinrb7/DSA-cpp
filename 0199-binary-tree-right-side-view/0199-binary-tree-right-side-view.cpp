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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        unordered_map<int,int> uMap;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mini=0,maxi=0;
        while(!q.empty()){
            pair<TreeNode*,int> qFront = q.front();
            q.pop();
            TreeNode* node = qFront.first;
            int level = qFront.second;
            uMap[level]= node->val;

            mini=min(mini,level);
            maxi=max(maxi,level);

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }

        for(int i=mini;i<=maxi;i++){
            res.push_back(uMap[i]);
        }

        return res;

    }
};