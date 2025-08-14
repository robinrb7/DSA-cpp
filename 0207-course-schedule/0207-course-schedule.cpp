class Solution {
    bool checkCycleDFS(vector<vector<int>> &adjList,vector<int> &visited,vector<int> &pathVis, int node){
        visited[node]=1;
        pathVis[node]=1;

        for(auto neigh : adjList[node]){
            if(visited[neigh]==0){
                if(checkCycleDFS(adjList,visited,pathVis,neigh)) return true;
            }
            else if(pathVis[neigh]==1) return true;
        }

        pathVis[node]=0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int>visited(n,0);
        vector<int> indegree(n,0);

        vector<vector<int>> adjList(n);
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            } 
        }

        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto neigh: adjList[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                    visited[neigh]=1;
                }
            }
        }

        if(cnt!=visited.size()) return false;
        return true;
    }
};