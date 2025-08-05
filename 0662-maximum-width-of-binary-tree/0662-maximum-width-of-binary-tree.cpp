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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int maxWidth = 0;

        while(!q.empty()){
            int size = q.size();
            int minLevelIndex = q.front().second;
            int firstIndex=-1,lastIndex=-1;
            for(int i =0;i<size;i++){
                auto[node,index] = q.front();
                index = index - minLevelIndex;
                q.pop();
                if(i==0) firstIndex = index;
                if(i==size-1) lastIndex = index;

                if(node->left) q.push({node->left,(2*index +1)});
                if(node->right) q.push({node->right,(2*index +2)});
            }
            maxWidth = max(maxWidth,lastIndex-firstIndex+1);
        }

        return maxWidth;
    }
};