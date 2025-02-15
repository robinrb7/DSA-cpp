//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited,vector<int>&ans){
        visited[node]=1;
        ans.push_back(node);
        
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool>visited(n,false);
        
        vector<int>ans;
        
        for(int i =0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        
            
            return ans;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends