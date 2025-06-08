class Solution {
    private:
    bool palin(string s){
        int n =  s.length();
        if(n==0) return 1;

        int i =0,j=n-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return 0;
            }
        }
        return 1;
    }
    void solve(string s, vector<vector<string>>&ans, vector<string> &temp, int partIndx, int n){
        if(partIndx == n){
            ans.push_back(temp);
            return;
        } 

        for(int i=partIndx;i<n;i++){
            string str = s.substr(partIndx,i - partIndx +1);
            if(palin(str)){
                temp.push_back(str);
                solve(s,ans,temp,i+1,n);
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> temp;
        int n= s.length();

        solve(s,ans,temp,0,n);
        return ans;
    }
};