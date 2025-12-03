class Solution {
private:
    void dfs(vector<vector<int>> &adjList, int node, int parent, vector<int> &timeOfInsert, vector<int> &lowestTimeOfInsert,
            vector<int> &visited, int timer,vector<vector<int>> &bridges)
        {
            timeOfInsert[node]=timer;
            lowestTimeOfInsert[node]=timer;
            visited[node] = 1;

            for(auto it: adjList[node]){
                int neigh = it;
                if(neigh==parent) continue;

                if(!visited[neigh]){
                    dfs(adjList,neigh,node,timeOfInsert,lowestTimeOfInsert,visited,timer + 1,bridges);

                    //after coming back from the dfs call
                    lowestTimeOfInsert[node] = min(lowestTimeOfInsert[node],lowestTimeOfInsert[neigh]);
                    if(lowestTimeOfInsert[neigh] > timeOfInsert[node])
                        bridges.push_back({node,neigh});
                }
                else{
                    lowestTimeOfInsert[node] = min(lowestTimeOfInsert[node],lowestTimeOfInsert[neigh]);
                }
            }

        }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> timeOfInsert(n,-1);
        vector<int> lowestTimeOfInsert(n,INT_MAX);
        vector<int> visited(n,0);

        vector<vector<int>> adjList(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> bridges;
        dfs(adjList,0,-1,timeOfInsert,lowestTimeOfInsert,visited,0,bridges);

        return bridges;
    }
};