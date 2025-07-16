class Solution {
    bool isPalindrome(string &s, int startIndex, int endIndex){
        while(startIndex<endIndex){
            if(s[startIndex++]!=s[endIndex--]) return false;
        }
        return true;
    }
    void solve(string &s, vector<string> temp, vector<vector<string>>&res, int startIndex, int n){
        if(startIndex==n){
            res.push_back(temp);
            return;
        }

        

        for(int partitionIndex = startIndex;partitionIndex<n;partitionIndex++){
            if(!isPalindrome(s,startIndex, partitionIndex)) continue;

            temp.push_back(s.substr(startIndex,partitionIndex-startIndex+1));
            solve(s,temp,res,partitionIndex+1,n);
            temp.pop_back();
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        int n = s.length();
        if(n==0) return res;

        vector<string>temp;
        solve(s,temp,res,0,n);
        return res;
    }
};