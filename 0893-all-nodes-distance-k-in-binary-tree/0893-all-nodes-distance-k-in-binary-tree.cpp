/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*> parentMap;
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    parentMap[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parentMap[node->right]=node;
                    q.push(node->right);
                }
            }
        }

        q.push(target);
        int distance=0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=1;
        while(!q.empty() && distance<k){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited[node->left] = 1;
                } 
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited[node->right] = 1;
                } 
                if(parentMap.count(node) && !visited.count(parentMap[node])){
                    q.push(parentMap[node]);
                    visited[parentMap[node]]=1;
                } 
            }
            distance++;
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }
};