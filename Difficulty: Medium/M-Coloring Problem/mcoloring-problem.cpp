class Solution {
    private:
    bool isPossible(vector<vector<int>> &edges, int nodeIndex, int colorCnt,vector<int>&color){
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==nodeIndex) {
                if(color[edges[i][1]]==-1) continue;
                if(color[edges[i][1]]==colorCnt) return false;
            }
            if(edges[i][1]==nodeIndex) {
                if(color[edges[i][0]]==-1) continue;
                if(color[edges[i][0]]==colorCnt) return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<int>> &edges, int n, int nodeIndex, int m,vector<int>&color){
        if(nodeIndex==n) return true;
        
        for(int colorCnt=1;colorCnt<=m;colorCnt++){
            if(isPossible(edges,nodeIndex,colorCnt,color)){
                color[nodeIndex] = colorCnt;
                if(solve(edges,n,nodeIndex+1,m,color)) return true;
                color[nodeIndex]=-1;
            }
        }
        
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int>color(v,-1);
        
        return solve(edges,v,0,m,color);
        
    }
};