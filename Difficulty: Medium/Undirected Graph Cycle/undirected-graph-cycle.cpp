class Solution {
    bool bfs(vector<int> &visited,vector<vector<int>> &adjList, int startNode){
        queue<pair<int,int>>q;
        q.push({startNode,-1});
        visited[startNode]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neigh : adjList[node]){
                if(visited[neigh]==1 && neigh!=parent) return true;
                
                if(neigh!=parent) q.push({neigh,node});
                visited[neigh]=1;
            }
        }
        
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>visited(V,0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(bfs(visited,adjList,i)) return true;
            }
        }
        
        return false;
    }
};