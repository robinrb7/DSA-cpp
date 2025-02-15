//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    bool dfs(int node,int parent,vector<vector<int>> &adj,vector<bool>&visited,vector<bool>&dfsVisited){
        visited[node]=1;
        dfsVisited[node]=1;
        
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                bool cycle = dfs(nbr,node,adj,visited,dfsVisited);
                if(cycle) return true;
            }
            else{
                if(dfsVisited[nbr]){
                    return true;
                }
            }
        }
        dfsVisited[node]=0;
        
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<bool>visited(n,0);
        vector<bool>dfsVisited(n,0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bool flag = dfs(i,-1,adj,visited,dfsVisited);
                if(flag) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends