/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>res;
        if(!root) return res;
        
        unordered_map<int,int> uMap;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int mini = 0,maxi =0;
        
        while(!q.empty()){
            pair<Node*,int> qfront = q.front();
            q.pop();
            Node* node = qfront.first;
            int vertical = qfront.second;
            uMap[vertical] = node->data;
            
            mini=min(mini,vertical);
            maxi=max(maxi,vertical);
            
            if(node->left){
                q.push({node->left,vertical-1});
            }
            if(node->right){
                q.push({node->right,vertical+1});
            }
        }
        
        for(int i=mini;i<=maxi;i++){
            res.push_back(uMap[i]);
        }
        
        return res;
        
    }
};