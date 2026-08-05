class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adjList[n];
        for(int i=0;i<invocations.size();i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adjList[u].push_back(v);
        }

        vector<bool> malice(n,0);
        queue<int> q;
        q.push(k);
        
        while(!q.empty()){
            int maliceNode = q.front();
            q.pop();
            malice[maliceNode]=1;

            for(int neigh: adjList[maliceNode]){
                if(malice[neigh]==0) q.push(neigh);
            }
        }

        bool removeAllMaliceMethods= true;
        for(int i=0;i<n;i++){
            if(malice[i]) continue;

            for(int neigh: adjList[i]){
                if(malice[neigh]==1){
                    removeAllMaliceMethods = false;
                    break;
                }
            }

        }

        vector<int> ans;
        if(removeAllMaliceMethods){
            for(int i=0;i<n;i++){
                if(malice[i]==0) ans.push_back(i);
            } 
        }
        else{
            for(int i=0;i<n;i++) ans.push_back(i);
        }

        return ans;

    }
};