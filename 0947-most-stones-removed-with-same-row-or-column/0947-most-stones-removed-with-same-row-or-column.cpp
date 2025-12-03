class DisjointSet{
    vector<int> parent,size;

    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u == ult_v) return;

        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow=-1, maxCol=-1;

        for(int i=0;i<n;i++){
            maxRow = max(maxRow,stones[i][0]);
            maxCol = max(maxCol,stones[i][1]);
        }

        DisjointSet ds(maxRow + maxCol +2);
        unordered_map<int,int> stoneNode;

        for(int i=0;i<n;i++){
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow +1;

            ds.UnionBySize(nodeRow,nodeCol);
            stoneNode[nodeRow] = 1;
            stoneNode[nodeCol] = 1;
        }

        int cntComponents = 0;
        for(auto it: stoneNode){
            if(ds.findParent(it.first)==it.first) cntComponents++;
        }

        return n - cntComponents;
    }
};