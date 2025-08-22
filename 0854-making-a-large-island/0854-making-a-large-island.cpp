class DisJointSet{
    
public:
    vector<int>parent,size;

    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);
        if(ult_pu == ult_pv) return;

        if(size[ult_pu] < size[ult_pv]){
            parent[ult_pu] = ult_pv;
            size[ult_pv] += size[ult_pu];
        }
        else{
            parent[ult_pv] = ult_pu;
            size[ult_pu] += size[ult_pv];
        }

    }

};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int dRow[4] = {-1,1,0,0};
        int dCol[4] = {0,0,-1,1};
        DisJointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==0) continue;

                int nodePos = i*n + j;
                for(int k=0;k<4;k++){
                    int row = i + dRow[k];
                    int col = j + dCol[k];

                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                        int neighPos = row*n +col;
                        ds.unionBySize(nodePos,neighPos);
                    }
                }
            }
        }

        int maxIslandSize = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1) continue;

                unordered_set<int> st;
                for(int k=0;k<4;k++){
                    int row = i + dRow[k];
                    int col = j + dCol[k];

                    if(row>=0 && row<n && col>=0 && col<n &&
                        grid[row][col]==1){
                            int pos = row*n + col;
                            st.insert(ds.findParent(pos));
                        }
                }

                int cnt=1;
                for(auto it: st){
                    cnt += ds.size[it];
                }
                if(cnt > maxIslandSize) maxIslandSize = cnt;
            }
        }

        for(int i=0;i<n*n;i++){
            if(ds.findParent(i)==i) maxIslandSize = max(maxIslandSize,ds.size[i]);
        }

        return maxIslandSize;
    }
};