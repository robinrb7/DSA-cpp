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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> uMap;
        DisJointSet ds(n);


        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(uMap.find(accounts[i][j]) != uMap.end()){
                    ds.unionByRank(uMap[accounts[i][j]],i);
                }
                else{
                    uMap[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string> >emailList(n);
        for(auto it: uMap){
            string mail = it.first;
            int node = it.second;

            emailList[ds.findParent(node)].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i=0;i<emailList.size();i++){
            if(emailList[i].size()==0) continue;
            sort(emailList[i].begin(),emailList[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:emailList[i]){
                temp.push_back(it);
            }

            res.push_back(temp);
        }

        return res;
    }
};