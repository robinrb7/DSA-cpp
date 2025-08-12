class Solution {
    private:
    void dfs(int node, vector<int> &visited,vector<vector<int>>& isConnected){
        visited[node]=1;
        for(int i =0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && visited[i]==0){
                dfs(i,visited,isConnected);
            }
        }
    }

    void bfs(int node,vector<int>& visited,vector<vector<int>>& isConnected){
        visited[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i = 0;i<isConnected.size();i++){
                if(isConnected[top][i]==1 && visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);

        int provinceCount=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                provinceCount++;
                bfs(i,visited,isConnected);
            }
        }

        return provinceCount;
    }
};