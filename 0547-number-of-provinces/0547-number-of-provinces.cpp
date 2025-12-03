class DisjointSet{
    vector<int> parent,size;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void findUnion(int u, int v){
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

    int CountProvinces(){
        int cntProvinces = 0;
        for(int i=1;i<parent.size();i++){
            if(parent[i]==i) cntProvinces++;
        }

        return cntProvinces;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =  isConnected.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;

                if(isConnected[i][j]==1){
                    ds.findUnion(i+1,j+1);
                }
            }
        }

        int cntProvinces = ds.CountProvinces();
        return cntProvinces;
    }
};