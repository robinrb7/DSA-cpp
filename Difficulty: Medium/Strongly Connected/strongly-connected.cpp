//Position this line where user code will be pasted.
class Solution {
    void dfs(vector<vector<int>> &adj,vector<int> &visited, int node,stack<int> &st){
        visited[node]=1;
        
        for(auto neigh: adj[node]){
            if(visited[neigh]==0){
                dfs(adj,visited,neigh,st);   
            }
        }
        st.push(node);
    }
    
    void dfsForSCC(vector<vector<int>> &revserAdjList,vector<int> &visited, int node){
        visited[node]=1;
        
        for(auto neigh: revserAdjList[node]){
            if(visited[neigh]==0){
                dfsForSCC(revserAdjList,visited,neigh);   
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int>st;
        int n = adj.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adj,visited,i,st);
            }
        }
        
        vector<vector<int>> reverseAdjList(n);
        for(int i=0;i<n;i++){
            visited[i]=0;
            int u = i;;
            for(auto v: adj[u]){
                reverseAdjList[v].push_back(u);
            }
        }
        
        int numSCC = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                numSCC++;
                dfsForSCC(reverseAdjList,visited,node);
            }
        }
        
        return numSCC;
    }
};