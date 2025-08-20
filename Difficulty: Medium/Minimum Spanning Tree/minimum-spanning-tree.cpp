class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>> > adjList(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        int sumWt = 0;
        vector<int> visited(V,0);
        vector<pair<int,int>> mst;
        priority_queue< pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>> >,
                        greater<pair<int,pair<int,int>>> > minHeap;
        minHeap.push({0,{0,-1}});
        
        while(!minHeap.empty()){
            auto it = minHeap.top();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            minHeap.pop();
            
            if(visited[node]==1) continue;
            
            visited[node]=1;
            sumWt += wt;
            if(parent!=-1) mst.push_back({parent,node});
            
            for(auto temp: adjList[node]){
                int neigh = temp.first;
                int edgeWt = temp.second;
                
                if(visited[neigh]==0){
                    minHeap.push({edgeWt,{neigh,node}});
                }
            }
        }
        
        return sumWt;
    }
};