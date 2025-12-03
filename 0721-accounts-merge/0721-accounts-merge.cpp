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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> uMap;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                
                if(uMap.count(accounts[i][j])){
                    int alreadyAddedNode = uMap[accounts[i][j]];
                    ds.UnionBySize(alreadyAddedNode, i);
                }
                else{
                    uMap[accounts[i][j]] = i;
                }
            }
        }

        vector<string> temp[n];
        for(auto it: uMap){
            string email = it.first;
            int node = it.second;

            temp[ds.findParent(node)].push_back(email);
        }

        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(temp[i].size()==0) continue;

            sort(temp[i].begin(),temp[i].end());
            vector<string> tempMails;
            tempMails.push_back(accounts[i][0]);
            for(auto it: temp[i]){
                tempMails.push_back(it);
            }

            result.push_back(tempMails);
        }

        return result;


    }
};