class Solution {
    private:
    bool dfs(vector<vector<int>>& graph,vector<int> &color, int node, int nodeColor){
        color[node] = nodeColor;

        for(auto neigh : graph[node]){
            if(color[neigh]==-1){
                if(!dfs(graph,color,neigh,!nodeColor)) return false;
            }
            else{
                if(color[neigh]==nodeColor) return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>>& graph,vector<int> &color, int startNode, int nodeColor){

        queue<pair<int,int>>q;
        q.push({startNode,nodeColor});
        while(!q.empty()){
            auto[node,colValue] = q.front();
            q.pop();

            for(auto neigh : graph[node]){
                if(color[neigh]==-1){
                    q.push({neigh,!colValue});
                    color[neigh] = !colValue;
                }
                else if(color[neigh]==colValue) return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!bfs(graph,color,i,0)) return false;
            }
        }

        return true;
    }
};