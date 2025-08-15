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

        vector<vector<int>>adjList(n);
        for(int i=0;i<n;i++){
            for(auto neigh: graph[i]){
                adjList[neigh].push_back(i);
            }
        }

        vector<int>visited(n,0);
        vector<int> safeNode(n,0);
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto neigh : adjList[i]){
                indegree[neigh]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i]=1;
            } 
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode[node]=1;

            for(auto neigh: adjList[node]){
                if(visited[neigh]==0){
                    indegree[neigh]--;
                    if(indegree[neigh]==0){
                        q.push(neigh);
                        visited[neigh]=1;
                    }
                }
            }
        }
        

        vector<int> res;
        for(int i=0;i<n;i++){
            if(safeNode[i]==1) res.push_back(i);
        }

        return res;

    }
};