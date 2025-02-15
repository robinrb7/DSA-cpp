//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>visited(n,false);
        vector<int>parent(n,-1);
        queue<int>q;
        bool flag=0;
        
        for(int i =0;i<n;i++){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=-1;
                
                
                while(!q.empty()){
                    int frontNode=q.front();
                    q.pop();
                    
                    for(auto nbr:adj[frontNode]){
                        if(!visited[nbr]){
                            q.push(nbr);
                            visited[nbr]=1;
                            parent[nbr]=frontNode;
                        }
                        else{
                            if(parent[frontNode]!=nbr){
                                flag=1;
                                if(flag) return true;
                            }
                        }
                    }
                }
                
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends