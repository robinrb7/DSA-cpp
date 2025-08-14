class Solution {
    bool checkCycle(vector<vector<int>> &adjList,vector<int> &visited,vector<int> &pathVis, int node){
        visited[node]=1;
        pathVis[node]=1;

        for(auto neigh : adjList[node]){
            if(visited[neigh]==0){
                if(checkCycle(adjList,visited,pathVis,neigh)) return true;
            }
            else if(pathVis[neigh]==1) return true;
        }

        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adjList(n);
        for(int i=0;i<prerequisites.size();i++){
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int>visited(n,0);
        vector<int> pathVis(n,0);

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(checkCycle(adjList,visited,pathVis,i)) return false;
            }
        }

        return true;
    }
};