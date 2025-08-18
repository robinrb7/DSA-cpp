// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>> > adjList(V);
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        vector<int>distance(V,-1);
        queue<int>q;
        q.push(0);
        distance[0]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto[neigh , dist] : adjList[node]){
                if(distance[neigh]==-1){
                    q.push(neigh);
                    distance[neigh] = distance[node]+dist;
                }
                else if(distance[node] + dist < distance[neigh]){
                    q.push(neigh);
                    distance[neigh] = distance[node]+dist;
                }
            }
        }
        
        return distance;
    }
};
