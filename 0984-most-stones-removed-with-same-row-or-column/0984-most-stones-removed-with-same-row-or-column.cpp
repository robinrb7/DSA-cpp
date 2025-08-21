class DisJointSet{
private:
    vector<int>parent,rank;

public:
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);
        if(ult_pu == ult_pv) return;

        if(rank[ult_pu] < rank[ult_pv]){
            parent[ult_pu] = ult_pv;
        }
        else if(rank[ult_pv] < rank[ult_pu]){
            parent[ult_pv] = ult_pu;
        }
        else{
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }

    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int nRow=0,nCol=0;
        for(int i=0;i<n;i++){
            int row = stones[i][0];
            int col = stones[i][1];

            if(row > nRow) nRow=row;
            if(col > nCol) nCol= col;
        }
        nRow++,nCol++;
        
        DisJointSet ds(nRow+nCol);
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int u = it[0];
            int v = it[1]+nRow;
            
            ds.unionByRank(u,v);

            stoneNodes[u]=1;
            stoneNodes[v]=1;
        }

        int numComponents =0;
        for(auto it: stoneNodes){
            int i = it.first;
            if(ds.findParent(i)==i) numComponents++;
        }

        return n-numComponents;
    }
};