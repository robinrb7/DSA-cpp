class DisjointSet{
    vector<int> parent,size;

    public:
    int countRedundantEdges;
    DisjointSet(int n){
        countRedundantEdges = 0;
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int u){
        if(parent[u]==u) return u;

        return parent[u] = findParent(parent[u]);
    }

    void findUnion(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if(ult_u == ult_v){
            countRedundantEdges++;
            return;
        }

        if(size[ult_u] > size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }

    int countComponents(){
        int cntComponents=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) cntComponents++;
        }

        return cntComponents;
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];

            ds.findUnion(u,v);
        }

        int extraCables = ds.countRedundantEdges;
        int extraNodes = ds.countComponents() -1;

        if(extraNodes > extraCables) return -1;
        return extraNodes;
    }
};