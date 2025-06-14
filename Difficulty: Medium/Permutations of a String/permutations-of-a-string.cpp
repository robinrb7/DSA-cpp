class Solution {
    private:
    void solve(string &s,vector<string> &ans, int index, int n){
        if(index==n){
            ans.push_back(s);
            return;
        }
        unordered_set<char> used;
        for(int i=index;i<n;i++){
            if(used.count(s[i])) continue;
            used.insert(s[i]);
            
            swap(s[index],s[i]);
            solve(s,ans,index+1,n);
            swap(s[index],s[i]);
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        vector<string>ans;
        solve(s,ans,0,s.length());
        return ans;
    }
};
