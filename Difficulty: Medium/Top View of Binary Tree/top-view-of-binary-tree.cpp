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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int>res;
        if(!root) return res;
        
        map<int,int> uMap;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node*,int> qfront = q.front();
            q.pop();
            Node* node = qfront.first;
            int vertical = qfront.second;
            if(!uMap.count(vertical)) uMap[vertical] = node->data;
            
            if(node->left){
                q.push({node->left,vertical-1});
            }
            if(node->right){
                q.push({node->right,vertical+1});
            }
        }
        
        for(auto it: uMap){
            res.push_back(it.second);
        }
        
        return res;
        
    }
};