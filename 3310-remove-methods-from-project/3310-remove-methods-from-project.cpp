class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adjList[n];     //(o(e))
        for(int i=0;i<invocations.size();i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adjList[u].push_back(v);
        }

        vector<bool> malice(n,0);
        queue<int> q;
        q.push(k);
        malice[k]=1;
        
        while(!q.empty()){     //o(e+v)
            int maliceNode = q.front();
            q.pop();

            for(int neigh: adjList[maliceNode]){
                if(malice[neigh]==0){
                    malice[neigh]=1;
                    q.push(neigh);
                } 
            }
        }

        bool removeAllMaliceMethods= true;
        for(int i=0;i<n;i++){    //o(e+v)
            if(malice[i]) continue;

            for(int neigh: adjList[i]){
                if(malice[neigh]==1){
                    removeAllMaliceMethods = false;
                    break;
                }
            }

        }

        vector<int> ans;
        if(removeAllMaliceMethods){   //o(v)
            for(int i=0;i<n;i++){
                if(malice[i]==0) ans.push_back(i);
            } 
        }
        else{
            for(int i=0;i<n;i++) ans.push_back(i);
        }

        return ans;

    }

    //tc -> 2(e+v)  ,Sc -> o(n) + o(n)
};