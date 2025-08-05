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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;

        map<int,map<int,multiset<int>>> uMap;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> qfront = q.front();
            q.pop();

            TreeNode* node = qfront.first;
            int vertical =qfront.second.first, level = qfront.second.second;
            uMap[vertical][level].insert(node->val);

            if(node->left){
                q.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                q.push({node->right,{vertical+1,level+1}});
            }
        }

        for(auto p : uMap){
            vector<int> temp;
            for(auto q : p.second){
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            res.push_back(temp);
        }

        return res;
    }
};