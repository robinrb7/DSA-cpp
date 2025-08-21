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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int usedCables =0;
        DisJointSet ds(n);
        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) != ds.findParent(v)){
                usedCables++;
                ds.unionByRank(u,v);
            } 
        }

        int givenCables = connections.size();
        int leftCables = givenCables - usedCables;

        int numComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) numComponents++;
        }

        return (leftCables >= numComponents-1)? numComponents-1 : -1;
    }
};