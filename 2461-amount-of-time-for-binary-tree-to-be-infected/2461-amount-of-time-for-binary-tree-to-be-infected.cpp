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
    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentNode,TreeNode* &startingNode, int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size =q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val==start) startingNode =node;

                if(node->left){
                    q.push(node->left);
                    parentNode[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parentNode[node->right]=node;
                }
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        unordered_map<TreeNode*,TreeNode*> parentNode;
        TreeNode* startingNode = NULL;
        makeParent(root,parentNode,startingNode,start);

        queue<TreeNode*>q;
        q.push(startingNode);
        unordered_map<TreeNode*,bool> visited;
        visited[startingNode]=1;
        int time=0;
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=1;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=1;
                }
                if(parentNode.count(node) && !visited[parentNode[node]]){
                    q.push(parentNode[node]);
                    visited[parentNode[node]]=1;
                }
            }
            time++;
        }

        return time-1;
    }
};