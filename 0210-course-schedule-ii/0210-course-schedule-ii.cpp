class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int>res;
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
            res.push_back(node);

            for(auto neigh: adjList[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        if(res.size() != n) return {};

        reverse(res.begin(),res.end());
        return res;
    }
};