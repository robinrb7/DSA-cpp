class Solution {
    private:
    bool dfs(vector<vector<int>>& graph,vector<int>&visited,vector<int> &safeNode,vector<int> & pathVisited,int node){
        visited[node]=1;
        pathVisited[node]=1;

        for(auto neigh: graph[node]){
            if(visited[neigh]==0){
                if(dfs(graph,visited,safeNode,pathVisited,neigh)) return true;
            }
            else if(pathVisited[neigh]==1) return true;
        }

        pathVisited[node]=0;
        safeNode[node]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>visited(n,0);
        vector<int> safeNode(n,0);
        vector<int> pathVisited(n,0);

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(graph,visited,safeNode,pathVisited,i);
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(safeNode[i]==1) res.push_back(i);
        }

        return res;

    }
};