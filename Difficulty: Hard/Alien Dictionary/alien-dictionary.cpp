class Solution {
  public:
    string findOrder(vector<string> &words) {
        
        vector<int> present(26,0);
        int cnt=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(present[words[i][j]-'a']==0){
                    present[words[i][j]-'a'] = 1;
                    cnt++;
                }
            }
        }
        
        vector<int>indegree(26,0);
        vector<vector<int>> adjList(26);
        for(int i=0;i<words.size()-1;i++){
            string str1 = words[i];
            string str2 = words[i+1];
            
            int p =0,q=0;
            bool found=false;
            while(p<str1.length() && q<str2.length()){
                if(str1[p] != str2[q]){
                    adjList[str1[p]-'a'].push_back(str2[q]-'a');
                    indegree[str2[q]-'a']++;
                    found=true;
                    break;
                }
                p++;
                q++;
            }
            if(!found && str1.size() > str2.size()) return "";
            
        }
        
        queue<int>q;
        for(int i=0;i<26;i++){
            if(present[i]==1 && indegree[i]==0) q.push(i);
        }
        
        string res="";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            char ch = 'a' + node;
            res += ch;

            for(auto neigh: adjList[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0) q.push(neigh);
            }
        }

        if(res.length()==cnt) return res;
        return "";
        
    }
};