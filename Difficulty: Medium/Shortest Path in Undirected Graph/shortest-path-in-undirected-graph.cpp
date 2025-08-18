class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        int v = adj.size();
        vector<int> dist(v,-1);
        queue<pair<int,int>> q;
        q.push({src,0});
        dist[src]=0;
        
        while(!q.empty()){
            auto[node, distance] = q.front();
            q.pop();
            
            for(auto neigh : adj[node]){
                if(dist[neigh]==-1){
                    q.push({neigh,distance+1});
                    dist[neigh] = distance+1;
                }
            }
        }
        
        
        return dist;
    }
};