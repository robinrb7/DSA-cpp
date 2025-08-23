class Solution {
    private:
    void dfs(vector<vector<int>> &adjList,vector<int> &visited, int node,int parent, vector<vector<int>> &bridges,
            int &timer,vector<int> &insertTime, vector<int> &lowTime){
        visited[node]=1;
        insertTime[node]=lowTime[node]=timer;
        timer++;

        for(auto neigh: adjList[node]){
            if(neigh==parent) continue;

            if(visited[neigh]==0){
                dfs(adjList,visited,neigh,node,bridges,timer,insertTime,lowTime);
                lowTime[node] = min(lowTime[neigh],lowTime[node]);

                if(lowTime[neigh] > insertTime[node]) bridges.push_back({node,neigh});
            }
            else{
                lowTime[node] = min(lowTime[neigh],lowTime[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visited(n,0);
        vector<vector<int>> bridges;
        vector<int> insertTime(n);
        vector<int> lowTime(n);
        int timer=0;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adjList,visited,i,-1,bridges,timer,insertTime,lowTime);
            }
        }

        return bridges;
    }
};